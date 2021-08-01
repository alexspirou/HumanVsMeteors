#pragma once
#include "IObject.h"
#include "CTextureManager.h"

class CEnemy : public IObject
{
public:

	CEnemy(int x, int y, int w, int h): IObject()
	{
		destRect.x = x;
		destRect.y = y;
		destRect.w = w;
		destRect.h = h;
	}
	virtual ~CEnemy() {}
	void draw() {}
	void clean() {}
	virtual void setX(int x) { destRect.x = x; }

protected:

	SDL_Rect destRect;


};