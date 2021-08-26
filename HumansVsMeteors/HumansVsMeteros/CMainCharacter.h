#pragma once
#include "CTextureManager.h"
#include "CSoundManager.h"
#include <iostream>
#include "CMeteors.h"
#include "CEnergy.h"
#include "CLaserGun.h"
#include "CLevels.h"

class CMainCharacter : public IObject
{
public:
   
    CMainCharacter();
    virtual ~CMainCharacter();

    virtual void draw() override;
    virtual void clean() override ;

    void events();
    void clear();
    void draw_explosion();
    void update();

    bool isCollision(IObject *p);
    //Change it to setter getter
    bool isFreeze = false;
    //Getters 
    virtual  inline SDL_Rect getRect() const override { return destRect; }
    inline CLaserGun* getLaserGun() { return laserGun; }
    //Setters
    inline void set_rect(SDL_Rect f_rect){ destRect = f_rect;}
    inline void setIsFire(bool f_bool) { isFire = f_bool; }

private:
    //Managers
    CTextureManager texManager{};
    CSoundManager soundManager{};

    SDL_Rect srcRect, destRect{};
    SDL_bool collision;
    CLaserGun* laserGun = NULL;
    bool isFire = false;


    //Animation
    int m_iRow{};
    int m_iFrameCount{};
    int m_iFrame{};
    int m_iAnimeSpeed{};
};
