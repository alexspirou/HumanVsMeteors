#include "CMainCharacter.h"
#include "SDL.h"
#include "CMeteors.h"
CMainCharacter::CMainCharacter()
{

    texManager.load("player","assets\\character.png");
    texManager.load("explosion","assets\\explosion.png");
    destRect.x = 50;
    destRect.y = 200;
    destRect.w = 60;
    destRect.h = 50;
}
void CMainCharacter::draw()
{
    
    texManager.draw("player", destRect.x, destRect.y, destRect.w, destRect.h);
    
}
void CMainCharacter::draw_explosion(){
    
    texManager.draw("explosion", destRect.x, destRect.y, destRect.w, destRect.h);

}

void CMainCharacter::events()
{
    SDL_Event event;
    SDL_PollEvent(&event); 
    switch (event.type)
    {
        case SDL_KEYDOWN:
        {
        if(!isFreeze){
            if (event.key.keysym.sym == SDLK_RIGHT)
                destRect.x += 15;
                
            if (event.key.keysym.sym == SDLK_LEFT)
                destRect.x -= 15;
                
            if (event.key.keysym.sym == SDLK_UP)
                destRect.y -= 15;

            if (event.key.keysym.sym == SDLK_DOWN)
                destRect.y += 15;
        
            }
        }
    }
}
bool CMainCharacter::check_collision(CMeteors *p)
{
    SDL_Rect meteorRect{ p->getRect() };

    if (SDL_HasIntersection(&destRect, &meteorRect))
        return true;
    else 
        return false;
}
bool CMainCharacter::check_collision(CEnergy *p)
{
   
    if (SDL_HasIntersection(&destRect, &p->destRect))
        return true;
    else 
        return false;
}
void CMainCharacter::clean()
{
   texManager.clean();
}
void CMainCharacter::clear(){
       destRect = {50, 200, 60, 50};
}


