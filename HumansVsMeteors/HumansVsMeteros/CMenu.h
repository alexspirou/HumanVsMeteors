#pragma once
#include "CTextureManager.h"
class CMenu
{
public:
    CMenu();
    ~CMenu();
    void isMenu();
    void render();
    void events();
    void diffuculty();
    inline bool isMenuTrue(){return m_bIsMenuOn;}
    inline void setMenu(bool f_menu){m_bIsMenuOn = f_menu; }
private:
    CTextureManager texManager;
    bool m_bIsMenuOn = true;
    int m_flag = 0;
};
