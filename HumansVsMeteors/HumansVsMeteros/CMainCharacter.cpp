#include "CMainCharacter.h"
#include "CEngine.h"
CMainCharacter::CMainCharacter()
{

    texManager.load("player","assets\\character.png");
    texManager.load("explosion","assets\\explosion.png");
    texManager.load("anime", "assets\\explosionAnimation.png");

    destRect.x = 50;
    destRect.y = 200;
    destRect.w = 60;
    destRect.h = 50;
    //destRect.x = 100;
    //destRect.y = 200;
    //destRect.w = 60;
    //destRect.h = 60;
    laserGun = new CLaserGun(destRect.x, destRect.y, 10, 20);

    //Animation

    m_iRow = 0;
    m_iFrameCount = 8;
    m_iAnimeSpeed = 60;
}
CMainCharacter::~CMainCharacter()
{
    delete laserGun;
    laserGun = NULL;
}
void CMainCharacter::draw()
{
    //Draw bullet behind character
    if (isFire == false){ laserGun->setRect(destRect); }
    //Is space key pressed fire
    else if (isFire == true) { laserGun->draw(); laserGun->fire(30); }
    //Bullet become availble after is bigger than width
    if (laserGun->getRect().x > SCREEN_WIDTH) { isFire = 0; }
    //Draw 

    //Draw Character
    texManager.draw("player", destRect.x, destRect.y, destRect.w, destRect.h);
    //texManager.draw("anime", destRect.x, destRect.y, destRect.w, destRect.h);
    //texManager.drawFrame("anime", destRect.x, destRect.y, destRect.w, destRect.h, m_iRow, m_iFrame);

}
void CMainCharacter::update() 
{
    m_iFrame = (SDL_GetTicks() / m_iAnimeSpeed) % m_iFrameCount;
}
void CMainCharacter::draw_explosion()
{
    
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
            if(!isFreeze)
            {
                if (event.key.keysym.sym == SDLK_RIGHT && destRect.x < SCREEN_WIDTH - destRect.w)
                    destRect.x += 15;
                
                if (event.key.keysym.sym == SDLK_LEFT && destRect.x > 0)
                    destRect.x -= 15;
                
                if (event.key.keysym.sym == SDLK_UP && destRect.y > 0 + destRect.w)
                    destRect.y -= 15;

                if (event.key.keysym.sym == SDLK_DOWN && destRect.y < SCREEN_HEIGHT - destRect.h)
                {
                    std::cout << destRect.y << std::endl;
                    destRect.y += 15;
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    if(isFire == 0 )soundManager.loadSound("music\\laserGun.wav");
                    isFire = 1;
                }
        
            }
        }
    }
}
//Function detects collision for Main Char with game Objects
bool CMainCharacter::isCollision(IObject *p)
{
    if (this->destRect.x + this->destRect.w < p->getRect().x + 5|| this->destRect.x > p->getRect().x + p->getRect().w ||
        this->destRect.y + this->destRect.h < p->getRect().y + 5 || this->destRect.y> p->getRect().y + p->getRect().h)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void CMainCharacter::clean()
{
   texManager.clean();
}
void CMainCharacter::clear()
{
    destRect = destRect;
}


