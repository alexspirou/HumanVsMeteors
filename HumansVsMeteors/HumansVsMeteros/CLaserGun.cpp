#include "CLaserGun.h"

CLaserGun::CLaserGun(int x, int y, int w, int h ): CComponent(x,y,w,h)
{
	texManager.load("laserGun", "assets\\laser.png");
}

void CLaserGun::draw()
{
	texManager.draw("laserGun", destRect.x, destRect.y, destRect.w, destRect.h);

}

void CLaserGun::clean()
{
	texManager.clean();
}

