#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "CTextureManager.h"
#include "IObject.h"
class CEnergy : public IObject
{
public:
    CEnergy(int x, int y, int w, int h);
    ~CEnergy();
    void draw();
    void clean();
    void drop();
    SDL_Rect getRect() { return destRect; }
    SDL_Rect destRect;
private:
    CTextureManager texManager;
};

