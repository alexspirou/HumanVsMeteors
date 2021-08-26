#pragma once
#include "CComponent.h"
class CAlienLaserBeam : public CComponent
{
public:
	CAlienLaserBeam(){}
	CAlienLaserBeam(int x, int y, int w, int h): CComponent(x,y,w,h)
	{
		texManager.load("alienBeam", "assets\\alienBeam.png");

	}
	virtual ~CAlienLaserBeam() {}

	virtual void draw()override { texManager.draw("alienBeam", destRect.x, destRect.y, destRect.w, destRect.h); }
	virtual void clean()override  { texManager.clean(); }
	virtual void update() override {}
	virtual void fire(int x) { destRect.x -= x; }

	


};