#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "IObject.h"
#include "CComponent.h"
#include "CTextureManager.h"

class CEnergy : public CComponent
{
public:
    CEnergy(int x, int y, int w, int h);
    ~CEnergy();
    virtual void draw() override;
    virtual void clean() override;
    virtual void update() override {}

private:
    //CTextureManager texManager;
};

