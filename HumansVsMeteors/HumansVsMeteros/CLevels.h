#pragma once
#include "CMeteors.h"
#include "CMainCharacter.h"
#include "CTextureManager.h"
#include "CSoundManager.h"
#include "CFontTexture.h"
#include "CAlien.h"
#include "CFontTexture.h"

class CLevels
{
public:
    CLevels();
    ~CLevels();

    void update();
    void render();

    //Collision functions consider this to make it a  class
    bool isMeteorCollision();
    bool isEnergyCollision();
    bool isLaserGunCollision();
    bool isAlienGunCollision();

    void level_1();
    void reset_level();
    void renderEnergyCounter();

    //Getters
    inline bool isGameOver()                            { return gameover; }
    inline bool getLevelOne()                           { return m_bLevel1; }
    inline bool getLevelTwo()                           { return m_bLevel1; }
    inline bool isMenu()                                { return m_bMenu; }
    inline int  getEnergyCounter()                      { return m_EnergiesCounter; }
    //Game objects getters
    inline std::vector<CMeteors*> getMeteors() const    { return m_vMeteors; }
    inline std::vector<CEnergy*> getEnergies() const    { return m_vEnergies; }

    //Seters
    inline void setGameover (bool f_gameover)           { gameover = f_gameover; }
    inline void set_b_level_1(bool f_lvl)               { m_bLevel1 = f_lvl; }
    inline void set_menu     (bool f_menu)              { m_bMenu = f_menu; }
    inline void setCollision(bool f_collision)          { m_bIsMeteorCollision = f_collision; }

private:
    //Vector of objects
    std::vector<CMeteors*> m_vMeteors;
    std::vector<CEnergy*> m_vEnergies;
    CAlien* greenAliens = NULL;
    CFontTexture* score = NULL;
    int m_countScore = 0;
    //Init Positions, function to Class instead of vector
    std::vector<SDL_Rect> m_vMeteorsInitPosition;
    std::vector<SDL_Rect> m_vEnergiesInitPosition;

    //Booleans
    bool gameover = false;
    bool m_bLevel1 = false;
    bool m_bLevel2 = false;
    bool m_bMenu = true;
    bool m_bIsMeteorCollision = false;
    bool m_bIsAllienCollision = false;
    int m_EnergiesCounter{ 0 };
    CTextureManager m_texManager;
    CSoundManager m_soundManager;
    CFontTexture* m_Text = NULL;
};


