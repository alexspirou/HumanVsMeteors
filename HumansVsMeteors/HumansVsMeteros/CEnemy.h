#pragma once
#include "IObject.h"
#include "CTextureManager.h"


class CEnemy : public IObject
{
public:
	//Constructor for every enemy. Assign the rectangle values and stores the init position and size
	CEnemy(int x, int y, int w, int h): IObject()
	{
		destRect.x = x;
		destRect.y = y;
		destRect.w = w;
		destRect.h = h;
		initDestRect = destRect;
	}
	virtual ~CEnemy() {}
	
	void setX(int x) { destRect.x = x; }	//Set x pos for Enemy Object
    void moveX(int x) { destRect.x -= x; }	//Move in x pos for every Enemy Object
	void moveY(int y) { destRect.y += y; }	//Move in y pos for every Enemy Object
	//Setters
	void setRect(SDL_Rect rect) { destRect = rect; } 
	void setRect(int x, int y, int w, int h) { destRect.x = x; destRect.y = y; destRect.w = w; destRect.h = h; }
	//Getters
	SDL_Rect getRect() const { return destRect; }

	virtual void resetPositions() { setRect(initDestRect); }

protected:

	SDL_Rect destRect;
	SDL_Rect initDestRect;
	CTextureManager texManager;
	CSoundManager m_SoundManager;
	int m_iRow{};
	int m_iFrameCount{};
	int m_iAnimeSpeed{};
	int m_iFrame;


};