#include "CMenu.h"
#include "CEngine.h"
#include "CLevels.h"
CMenu::CMenu()
{
    texManager.load("no_choice", "assets\\Menu\\menu_clean.png");
    texManager.load("menu_play", "assets\\Menu\\menu_play.png");
    texManager.load("menu_difficulty", "assets\\Menu\\menu_difficulty.png");
    texManager.load("menu_levels", "assets\\Menu\\menu_levels.png");
    texManager.load("background", "assets\\backround3.png");
    texManager.load("under_construction", "assets\\Menu\\under_construction.png");
}

CMenu::~CMenu()
{

}

void CMenu::render() 
{
    //"Play"
    if (m_flag == 0) 
    {
        SDL_RenderClear(CEngine::m_renderer);
        texManager.draw("background", 0, 0, 1000, 1000);
        texManager.draw("menu_play", 0, 0, 800, 800);
        m_flag = 0;
    }
    //"Difficulty"
    if (m_flag == 1)
    {
        SDL_RenderClear(CEngine::m_renderer);
        texManager.draw("background", 0, 0, 1000, 1000);
        texManager.draw("menu_difficulty", 0, 0, 800, 800);
        //std::cout << "Diff: " << flag << std::endl;
        m_flag = 1;
    }
    //"Levels"
    if (m_flag == 2) 
    {
        SDL_RenderClear(CEngine::m_renderer);
        texManager.draw("background", 0, 0, 1000, 1000);
        texManager.draw("menu_levels", 0, 0, 800, 800);
        //std::cout << "Lev: " << flag << std::endl;
        m_flag = 2;
    }
    //
    if (m_flag == 3) 
    {
        SDL_RenderClear(CEngine::m_renderer);
        texManager.draw("background", 0, 0, 1000, 1000);
        texManager.draw("under_construction", 0, 0, 800, 800);
        m_flag = 3;
    }
    if (m_flag == 4)
    {
        SDL_RenderClear(CEngine::m_renderer);
        texManager.draw("background", 0, 0, 1000, 1000);
        texManager.draw("under_construction", 0, 0, 800, 800);
        m_flag = 4;
    }
}

//void Menu::difficulty(){
//    
//
//}

void CMenu::isMenu() 
{
    SDL_RenderClear(CEngine::m_renderer);
    while (m_bIsMenuOn)
    {
        render();
        events();
        SDL_RenderPresent(CEngine::m_renderer);
    }
}
void CMenu::events() {

    if (m_bIsMenuOn) 
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_KEYDOWN:
        {

            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                while (m_flag < 2)
                {
                    std::cout << "Right " << m_flag << std::endl;
                    m_flag++;
                    break;
                }
            }
            if (event.key.keysym.sym == SDLK_LEFT) 
            {
                while (m_flag != 0) 
                {
                    std::cout << "Left " << m_flag << std::endl;
                    m_flag--;
                    break;
                }
            }
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                switch (m_flag)
                {
                case 0:
                    m_bIsMenuOn = false;
                case 1:
                    m_flag = 3;
                    break;
                case 2:
                    m_flag = 4;
                    break;
                }
            }
            if (event.key.keysym.sym == SDLK_BACKSPACE) 
            {
                m_flag = 0;
            }

            }
        }
    }
}