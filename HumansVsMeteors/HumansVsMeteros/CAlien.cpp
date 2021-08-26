#include "CAlien.h"
#include "CEngine.h"
//CEnemy constructor gives the values to destRect
CAlien::CAlien(int x, int y, int w, int h) : CEnemy(x, y, w, h)
{
	texManager.load("greenAlien", "assets/alien.png");
	//Store init position
	initPosition.x = x; initPosition.y = y; initPosition.w = w; initPosition.h = h;

	//Animation
	m_iRow = 0;
	m_iFrameCount = 3;
	m_iAnimeSpeed = 80;
	//Array of alien beam objects
	m_vAlienBeam.resize(2);
	m_vAlienBeam[0] = new CAlienLaserBeam(destRect.x, destRect.y, 20, 50);
	m_vAlienBeam[1] = new  CAlienLaserBeam(destRect.x, destRect.y, 20, 50);

	m_SoundManager.loadSound("music/alienBeamSound.wav");
}
CAlien::~CAlien()
{
	for (auto& beam : m_vAlienBeam)
	{
		delete beam;
		beam = NULL;
	}

}
void CAlien::draw()
{
	
	attack();
	//Draw alien
	texManager.draw("greenAlien", destRect.x, destRect.y, destRect.w, destRect.h);

}
void CAlien::update()
{
	//Modulo for loop 0-5
	m_iFrame = (SDL_GetTicks() / m_iAnimeSpeed) % m_iFrameCount;
	//Move alien up and down
	move();

}

void CAlien::move()
{
	
	//While alien is not appeared move him
	if (this->getRect().x != SCREEN_WIDTH - 100) { this->moveX(2); }
	//Move up
	if (this->getRect().y < SCREEN_HEIGHT - 50 && downFlag) { this->moveY(2); downFlag = true;  }
	else { downFlag = false; upFlag = true; }
	//Move down
	if(this->getRect().y >= 20 && upFlag){ this->moveY(-2);upFlag = true; }
	else{ upFlag = false; downFlag = true; }

}
void CAlien::attack()
{

	//Fire beam 1
	if (isFireBeam1) { m_vAlienBeam[0]->fire(5); }
	//Fire beam 2
	if (m_vAlienBeam[0]->destRect.x < 400 || isFireBeam2)
	{

		m_vAlienBeam[1]->fire(5);
		isFireBeam2 = true;
	}
	//Return back to alien the beam 1 when is out of screen
	if (m_vAlienBeam[0]-> destRect.x < 0)
	{
		m_SoundManager.playSound();
		m_vAlienBeam[0]->destRect = destRect;
	}
	//Return back to alien the beam 2 when is out of screen
	if (m_vAlienBeam[1]->getRect().x < 0)
	{
		m_SoundManager.playSound();
		m_vAlienBeam[1]->setRect(destRect);
		isFireBeam2 = false;
	}
	//Draw beams
	m_vAlienBeam[0]->draw();
	m_vAlienBeam[1]->draw();
}

void CAlien::resetPositions()
{
	destRect = initPosition;
	m_vAlienBeam[0]->destRect.x = initPosition.x; m_vAlienBeam[0]->destRect.y = initPosition.x;
	m_vAlienBeam[1]->destRect.x = initPosition.x; m_vAlienBeam[1]->destRect.y = initPosition.x;

}