#pragma once
#include "CTextureManager.h"
#include "CSoundManager.h"
class CMenu
{
public:
    CMenu();
    ~CMenu();
    bool isMenu();
    void render();
    void events();
    void diffuculty();
    inline bool isMenuTrue(){return m_bIsMenuOn;}
    inline void setMenu(bool f_menu){m_bIsMenuOn = f_menu; }
private:
    CTextureManager texManager;
    CSoundManager m_soundManager;
    bool m_bIsMenuOn = true;
    int m_flag = 0;
    int prevFlag = 0;
};
