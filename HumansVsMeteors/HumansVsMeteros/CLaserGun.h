#pragma once
#include "CComponent.h"
class CLaserGun: public CComponent
{

public:
    CLaserGun(int x, int y, int w, int h);
    virtual ~CLaserGun() {}
    virtual void draw();
    virtual void clean();
    virtual void fire(int x) 
    { 
        destRect.x += x;
    }
private:
    
};

