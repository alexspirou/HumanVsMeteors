#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include "CTextureManager.h"
#include "CSoundManager.h"

class IObject
{
public:
    IObject() {}
    ~IObject() {}
    virtual void draw() = 0;
    virtual void clean() = 0;
    virtual void update() = 0;
    virtual SDL_Rect getRect() const = 0;
};