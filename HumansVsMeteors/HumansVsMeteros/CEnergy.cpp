#include "CEnergy.h"

CEnergy::CEnergy(int x, int y, int w, int h) : CComponent(x, y, w, h) 
{
    destRect = { x, y, w, h };
    texManager.load("energy", "assets\\energy.png");
}

CEnergy::~CEnergy()
{

}
void CEnergy::draw() 
{

    texManager.draw("energy", destRect.x, destRect.y, destRect.w, destRect.h);

}
void CEnergy::clean() 
{

}