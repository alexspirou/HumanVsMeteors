#include "SDL.h"
#include "CMeteors.h"
#include <iostream>
CMeteors::CMeteors(int x, int y, int w, int h) : CEnemy(x,y,w,h)
{

    texManager.load("meteor", "assets\\meteor.png");

}
void CMeteors::draw()
{
    //Draw meteors
    texManager.draw("meteor", destRect.x, destRect.y, destRect.w, destRect.h);

}
void CMeteors::clean()
{
    texManager.clean();
}