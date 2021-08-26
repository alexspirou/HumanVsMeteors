#pragma once
#include "CEnemy.h"
#include "CAlienLaserBeam.h"
#include "CLaserGun.h"
#include <vector>
class CAlien : public CEnemy
{
public:

	CAlien(int x, int y, int w, int h);
	virtual ~CAlien();

	virtual void draw() override;
	virtual void clean() override {}
	virtual void update() override;
	void resetPositions() override;

	void move(); 
	void attack();

	//Setters
	void setFire(bool fire) { isFireBeam1 = isFireBeam2 = fire; }
	
	//Getters
	std::vector<CAlienLaserBeam*> getAlienBeams() { return m_vAlienBeam; }
private:

	bool upFlag = false;
	bool downFlag = true;
	bool isFireBeam1 = true;
	bool isFireBeam2 = true;

	std::vector<CAlienLaserBeam*> m_vAlienBeam;
	SDL_Rect initPosition{};


};

