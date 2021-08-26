#include "SDL.h"
#include "CMeteors.h"
#include <algorithm>
#include <iostream>
#include "CEngine.h"
CMeteors::CMeteors(int x, int y, int w, int h) : CEnemy(x,y,w,h)
{

    texManager.load("meteor", "assets\\meteor.png");
    texManager.load("explosion", "assets\\explosionAnimation.png");

    m_iRow = 0;
    m_iFrameCount = 3;
    m_iAnimeSpeed = 80;
}
void CMeteors::draw()
{
    //Draw meteors
    texManager.draw("meteor", destRect.x, destRect.y, destRect.w, destRect.h);

}
void CMeteors::update()
{
    //Modulo for loop 0-5
    m_iFrame = (SDL_GetTicks() / m_iAnimeSpeed) % m_iFrameCount;
}
void CMeteors::clean()
{
    texManager.clean();
}