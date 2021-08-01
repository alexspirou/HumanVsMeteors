#include "CBackGround.h"
#include "CEngine.h"

CBackGround::CBackGround()
{
    xpos_1 = 0;
    xpos_2 = 1200;
    texManager.load("background", "assets//backround3.png");
    texManager.load("gameover", "assets//game_over.png");
    texManager.load("again", "assets//play_again.png");
    texManager.load("win", "assets//Win//play_again.png");
}


CBackGround::~CBackGround()
{
}
void CBackGround::render() 
{

    main_background();


}
void CBackGround::main_background()
{
    texManager.draw("background", xpos_1, 0, 1200, 1000);
    texManager.draw("background", xpos_2, 0, 1200, 900);
}

void CBackGround::gameover_background()
{
    SDL_RenderClear(CEngine::m_renderer);
    CEngine::player->isFreeze = true;
    texManager.draw("background", 0, 0, 1000, 1000);
    texManager.draw("gameover", 250, 50, 528 / 2, 528 / 2);
    texManager.draw("again", 0, 300, 800, 100);
    SDL_RenderPresent(CEngine::m_renderer);
}
void CBackGround::win_background() 
{
    SDL_RenderClear(CEngine::m_renderer);
    texManager.draw("background", 0, 0, 1000, 1000);
    texManager.draw("win", 0, 0, 800, 800);
    SDL_RenderPresent(CEngine::m_renderer);

}

void CBackGround::update()
{

    xpos_1--; xpos_2--;
    if (xpos_1 < -1200)
        xpos_1 = 0;
    if (xpos_2 < 0)
        xpos_2 = 1200;
}
