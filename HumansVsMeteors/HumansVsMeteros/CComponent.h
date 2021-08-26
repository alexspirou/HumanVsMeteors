#pragma once
#include "IObject.h"

class CComponent : public IObject
{
public:
	//Constructors
	CComponent(){}
	CComponent(int x, int y, int w, int h) : IObject()
	{
		destRect.x = x;
		destRect.y = y;
		destRect.w = w;
		destRect.h = h;
	}

	virtual ~CComponent() {}
	void draw()override {}
	void clean()override {}
	void update() override{}

	//Getters
	SDL_Rect getRect() const override { return destRect; }

	virtual void setRect(SDL_Rect rect) { destRect = rect; }

	//Setters
	virtual void setX(int x) { destRect.x = x; }

	virtual bool isCollision(IObject* p)
	{
		if (this->destRect.x + this->destRect.w < p->getRect().x + 5 || this->destRect.x > p->getRect().x + p->getRect().w ||
			this->destRect.y + this->destRect.h < p->getRect().y + 5 || this->destRect.y> p->getRect().y + p->getRect().h)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	SDL_Rect destRect{};

protected:
	CTextureManager texManager;
	CSoundManager m_SoundManager;
};