#include "CFontTexture.h"
#include "CEngine.h"

CFontTexture::CFontTexture()
{
    TTF_Init();
    if (!TTF_Init) { std::cout << "Faile to init ttf\n"; }
}
bool CFontTexture::loadFont(const char* path, int fontSize)
{
    font = TTF_OpenFont(path, fontSize);

    if (font == NULL) 
    {
        std::cerr << "Failed the load the font!\n";
        std::cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
        font = TTF_OpenFont(path, fontSize);
        return false;
    }
    return true;
}

void CFontTexture::renderText(const char* textToRender)
{
    //If there was an error in rendering the text

    counter++;
    std::string s = std::to_string(counter);
    message = TTF_RenderText_Solid(font, s.c_str(), wht);

    texture = SDL_CreateTextureFromSurface(CEngine::m_renderer, message);
    SDL_Rect dest = { SCREEN_WIDTH- message->w, SCREEN_HEIGHT - message->h, message->w, message->h };
    SDL_RendererFlip flip{};
    SDL_RenderCopyEx(CEngine::m_renderer, texture, 0, &dest, 0, nullptr, flip);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(message);

}
void CFontTexture::renderScore(int score)
{
    //If there was an error in rendering the text

    std::string s = "SCORE : " + std::to_string(score);
    message = TTF_RenderText_Solid(font, s.c_str(), wht);

    texture = SDL_CreateTextureFromSurface(CEngine::m_renderer, message);
    SDL_Rect dest = { SCREEN_WIDTH - message->w, 0 , message->w, message->h };
    SDL_RendererFlip flip{};
    SDL_RenderCopyEx(CEngine::m_renderer, texture, 0, &dest, 0, nullptr, flip);

    //SDL_DestroyTexture(texture);
    //SDL_FreeSurface(message);

}