#include "CEngine.h"
#include <iostream>
SDL_Renderer* CEngine::m_renderer = nullptr;
CMainCharacter* CEngine::player = nullptr;
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
    //Create Window
    m_window = SDL_CreateWindow("Exal Game Enginge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, 0);
    if (m_window == nullptr) 
    {
        SDL_Log("Fail to create widnow: %s", SDL_GetError());
        return false;
    }
    //Create Renderer
    if (m_renderer = SDL_CreateRenderer(m_window, -1, 0)) 
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    }
    else if (m_renderer == nullptr){
        SDL_Log("Fail to create renderer: %s", SDL_GetError());
    }

    //Memory allocation
    player = new CMainCharacter();
    levels = new CLevels();
    menu = new CMenu();
    background = new CBackGround();


    menu->isMenu();
    levels->level_1();
    player->isFreeze = false;
    return  m_isRunning;
}
void CEngine::update() 
{
    //Update function for changes in game
    levels->update();
    background->update();
}
void CEngine::render()
{
    //Game starts

    //Render starts
    SDL_RenderClear(CEngine::m_renderer);
    background->render();
    levels->render();

    //Check collisions with meteors and energies
    if (!levels->isMeteorsCollision() && levels->get_counter() != 4)
    {
        player->draw();
        levels->check_colission_energies();
        levels->render_counter();
    }
    //Check winner
    else if (levels->get_counter() == 4)
    {
        if (m_bisWin)
        {
            background->win_background();
            event();
        }
    }
    //Gameover 
    else if(levels->isMeteorsCollision())
    {
        levels->setGameover(1);
        while (levels->getIsGameover()) 
        {
            event();
            background->gameover_background();
        }
    }
    SDL_Delay(10);
    SDL_RenderPresent(m_renderer);
}
void CEngine::event()
{
    //Check for objects events

    menu->events();
    player->events();

    
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
            levels->setCollision(0);
            levels->setGameover(0);
            break;
        }
        //
        if (event.key.keysym.sym == SDLK_F3)
        {
            levels->reset_level();
            levels->level_2();
            levels->set_b_level_1(false);
            levels->setGameover(false);
            break;

        }
        //
        if (event.key.keysym.sym == SDLK_F4) 
        {
            levels->reset_level();
            levels->level_1();
            levels->set_b_level_2(false);
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

    return true;
}
void CEngine::quit()
{
    menu->setMenu(false);
    levels->setGameover(false);
    m_bisWin = false;
    m_isRunning = false;
}