#pragma once
#include "CTextureManager.h"
class CBackGround
{
public:
    CBackGround();
    ~CBackGround();
    void update();
    void render();
    void main_background();
    void gameover_background();
    void win_background();
private:
    CTextureManager texManager;
    int xpos_1, xpos_2;
};


