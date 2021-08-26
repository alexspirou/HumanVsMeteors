#include "CEngine.h"
#include <iostream>
#include "CFontTexture.h"
#include <string>
SDL_Renderer* CEngine::m_renderer = NULL;
CMainCharacter* CEngine::player = NULL;
bool CEngine::init()
{
    //Check if SDL is initialized
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Fail to init SDL: %s", SDL_GetError());
         m_isRunning = false;
         return m_isRunning;
    }
    else { SDL_Log("SDL init "); }

    //FONT CODE

    TTF_Init();
    
    //Create Window
    m_window = SDL_CreateWindow("Exal Game Enginge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (m_window == NULL) 
    {
        SDL_Log("Fail to create widnow: %s", SDL_GetError());
        return false;
    }
    //Load font
    font = TTF_OpenFont("D:\\repos\\HumanVsMeteors\\HumansVsMeteors\\HumansVsMeteros\\Franchise.ttf", 48);
    if (!font) { std::cout << "Fail to load font\n"; }

    //Surface with message

    //Create Renderer
    //SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    if (m_renderer = SDL_CreateRenderer(m_window, -1, 0 )) 
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    }
    else if (m_renderer == NULL){
        SDL_Log("Fail to create renderer: %s", SDL_GetError());
    }


    //Memory allocation
    player = new CMainCharacter();
    levels = new CLevels();
    menu = new CMenu();
    background = new CBackGround();
    //Load font for score
    //Show menu on screen 
    menu->isMenu();
   
    //Set level 
    levels->level_1();
    player->isFreeze = false;

    return  m_isRunning;
}
CEngine::~CEngine()
{
    clean();
    delete player;
    player = NULL;
    delete levels; 
    levels = NULL;
    delete menu; 
    menu = NULL;
    delete background;
    background = NULL;
    delete score;
    score = NULL;
}


void CEngine::update() 
{
    //Update function for changes in game
    levels->update();
    background->update();
    player->update();
   
}
void CEngine::render()
{
    //Game starts

    //Render starts
    SDL_RenderClear(CEngine::m_renderer);
    background->render();
    levels->render();
    //Check collisions with meteors and energies
    if (!levels->isMeteorCollision() && levels->getEnergyCounter() != 4)
    {
       
        player->draw();
        player->events();
        levels->isEnergyCollision();
        //if (levels->isLaserGunCollision()) { counter += 20; }
        levels->renderEnergyCounter();
    }
    //Check winner
    else if (levels->getEnergyCounter() == 4)
    {
        if (m_bisWin)
        {
            background->win_background();
            event();
        }
    }
    //Gameover 
    if(levels->isMeteorCollision() || levels->isAlienGunCollision())
    {
        levels->reset_level();
        levels->setGameover(true);
        std::cout << "here\n";

    }
    if (levels->isGameOver())
    {
        event();
        background->gameover_background();
    }

    SDL_Delay(8);
    SDL_RenderPresent(m_renderer);
}
void CEngine::event()
{
    //Check for objects events

    menu->events();
    player->events();
    
    //Gameplay events
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT: 
        {
            quit();
        }

        case SDL_KEYDOWN:
        {
            //Play again
            if (event.key.keysym.sym == SDLK_F2) 
            {
                levels->reset_level();
                levels->setCollision(false);
                levels->setGameover(false);
                player->isFreeze = false;

                break;
            }
            //
            if (event.key.keysym.sym == SDLK_F3)
            {
                levels->reset_level();
                levels->set_b_level_1(0);
                levels->setGameover(0);
                player->isFreeze = false;
                SDL_Delay(10);

                break;

            }
            //
            if (event.key.keysym.sym == SDLK_F4) 
            {
                levels->reset_level();
                levels->level_1();
                levels->setGameover(false);
                break;
            }
        }
             default:
                break;
        }

}
bool CEngine::clean()
{
    texManager.clean();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();

    return true;
}
void CEngine::quit()
{
    menu->setMenu(false);
    levels->setGameover(false);
    m_bisWin = false;
    m_isRunning = false;
}