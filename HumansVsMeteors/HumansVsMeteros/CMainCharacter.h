#pragma once
#include "CTextureManager.h"
#include <iostream>
#include "CMeteors.h"
#include "CEnergy.h"
class CMainCharacter
{
public:
   
    CMainCharacter();
    void draw();
    void clean() ;
    void events();

    //Change them to one function with inheritance
    bool check_collision(CMeteors *obj);
    bool check_collision(CEnergy *obj);

    void clear();
    bool isFreeze = false;
    void draw_explosion();
    inline SDL_Rect get_rect(){return destRect;}
    inline void set_rect(SDL_Rect f_rect){ destRect = f_rect;}
private:
    SDL_Rect srcRect, destRect{};
    CTextureManager texManager{};
    SDL_bool collision;
};
