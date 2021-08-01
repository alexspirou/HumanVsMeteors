#pragma once
#include "CMeteors.h"
#include "CMainCharacter.h"
#include "CTextureManager.h"
class CLevels
{
public:
    CLevels();
    ~CLevels();

    void update();
    void render();
    bool isMeteorsCollision();
    bool check_colission_energies();
    void level_1();
    void level_2();
    void reset_level();
    void render_counter();
    //Getters
    inline bool getIsGameover()   {return gameover; }
    inline bool get_b_level_1()   {return m_bLevel1; }
    inline bool get_b_level_2()   {return m_bLevel1; }
    inline bool get_b_menu()      {return m_bMenu; }
    inline int  get_counter()     {return m_EnergiesCounter; }

    //Seters
    inline void setGameover (bool f_gameover){ gameover = f_gameover; }
    inline void set_b_level_1(bool f_lvl)     { m_bLevel1 = f_lvl; }
    inline void set_b_level_2(bool f_lvl)     { m_bLevel2 = f_lvl; }
    inline void set_menu     (bool f_menu)    { m_bMenu = f_menu; }
    inline void setCollision(bool f_collision) { m_bIsMeteorCollision = f_collision; }

private:

    //Vector of objects
    std::vector<CMeteors*> m_vMeteors;
    std::vector<CEnergy*> m_vEnergies;
    //Init Positions
    std::vector<SDL_Rect> m_vMeteorsInitPosition;
    std::vector<SDL_Rect> m_vEnergiesInitPosition;
    //Booleans
    bool gameover = false;
    bool m_bLevel1 = false;
    bool m_bLevel2 = false;
    bool m_bMenu = true;
    bool m_bIsMeteorCollision = false;
    int m_EnergiesCounter{ 0 };
    CTextureManager m_texManager;


};


