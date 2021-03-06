#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <SDL_ttf.h>

#include "CLevels.h"
#include "CMainCharacter.h"
#include "CMeteors.h"
#include "CTextureManager.h"
#include "CMenu.h"
#include "CBackGround.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

class CEngine
{
public:
    CEngine() { init(); }
    ~CEngine();
    bool init(); //Whent the program starts create the need staff
    bool clean(); //Clean surfaces, renderers etc
    void update(); // Update events renders etc
    void render(); // Render all graphics
    void event(); //Handle the user's inputs
    void quit(); // Quit program, destroy what it needs to be destroyed
    void start_menu();
    //getters
    inline CMainCharacter* get_player() { return player; }
    inline bool getIsRunning() { return m_isRunning; }
    inline bool isGameOver() { return gameover; }
    inline bool isWin() { return m_bisWin; }

    //Setters
    inline void setWin(bool f_isWin) { m_bisWin = f_isWin; }

    static SDL_Renderer* m_renderer;
    static CMainCharacter* player;

    static bool gameover;
private:

    SDL_Window* m_window;
    bool m_isRunning = true;
    bool m_bisWin = true;
    SDL_bool collision;
    CLevels* levels = nullptr;
    CTextureManager texManager;
    CBackGround* background = nullptr;
    CMenu* menu = nullptr;
    CFontTexture* score = nullptr;


    int counter = 0;
};
