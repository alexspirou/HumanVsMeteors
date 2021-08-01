#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
class CTextureManager
{
public:
    CTextureManager() {}
    ~CTextureManager() {}
    bool load(const char* id, const char* filename);
    void drop(const char* id);
    void clean();
    void draw(const char* id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(const char* id, int x, int y, int width, int height, int row, int fram, SDL_RendererFlip flip = SDL_FLIP_NONE);
    std::map<const char*, SDL_Texture*> m_textureMap;
private:
    SDL_Rect srcRect;
};



