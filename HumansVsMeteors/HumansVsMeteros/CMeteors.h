#pragma once
#include "IObject.h"
#include "CEnemy.h"
#include "CTextureManager.h"
#include  <vector>

class CMeteors : public CEnemy
{
public:
    CMeteors(int x, int y, int w, int h);
    virtual ~CMeteors() {}
    void draw();
    void clean();
    SDL_Rect getRect() { return destRect; }
    void setRect(SDL_Rect rect) { destRect = rect; }
    void setRect(int x, int y, int w, int h) { destRect.x = x; destRect.y = y; destRect.w = w; destRect.h = h; }
    SDL_Rect destRect;

private:
    CTextureManager texManager;


};

