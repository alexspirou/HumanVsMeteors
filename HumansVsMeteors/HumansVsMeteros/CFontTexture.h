#pragma once
#include <SDL.h>
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
static TTF_Font* font = NULL;

class CFontTexture
{

public:
    CFontTexture();
    bool loadFont(const char* path, int fontSize);
    void renderText(const char* textToRender);
    void renderScore(int score);
private:
    TTF_Font* font;
    SDL_Color wht = { 180,0,0 };
    SDL_Surface* message;
    SDL_Texture* texture;
    int counter = 0;
};


