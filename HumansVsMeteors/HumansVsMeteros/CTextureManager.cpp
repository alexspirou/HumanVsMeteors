#include "CTextureManager.h"
#include <iostream>
#include "CEngine.h"


bool CTextureManager::load(const char* id, const char* filename)
{
    SDL_Surface* surface = IMG_Load(filename);
    if (surface) 
    { 
        SDL_Log("Image loaded in location:  %s", filename); 
    }
    else { SDL_Log("Error to load image %s", SDL_GetError); return false; }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(CEngine::m_renderer, surface);
    if (texture)
    {
        //SDL_Log("Texture Created"); 
    }
    else { SDL_Log("Error to create texture %s", SDL_GetError()); return false; }
    m_textureMap[id] = texture;
    return true;
}
void CTextureManager::draw(const char* id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = { x , y, width, height };

    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopyEx(CEngine::m_renderer, m_textureMap[id], 0, &dstRect, 0, nullptr, flip);
    //SDL_RenderCopy(Engine::m_renderer, id, &srcRect, &dstRect);
}
void  CTextureManager::drawFrame(const char* id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{


    SDL_Rect srcRect = { width * frame, height * row, width, height };
    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopyEx(CEngine::m_renderer, m_textureMap[id], &srcRect, &dstRect, 0, NULL, flip);
}
void CTextureManager::drop(const char* id)
{

}
void CTextureManager::clean()
{
    std::map<const char*, SDL_Texture*>::iterator it;
    for (it = m_textureMap.begin(); it != m_textureMap.end(); it++)
        SDL_DestroyTexture(it->second);
    m_textureMap.clear();
    SDL_Log("Texture map cleaned");
}