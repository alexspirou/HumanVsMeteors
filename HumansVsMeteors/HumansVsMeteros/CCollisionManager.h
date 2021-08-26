#pragma once
#include "CMeteors.h"
#include "CEnergy.h"

class CCollisionManager
{
public:

    bool isMeteorCollision(const std::vector<CMeteors*> m_vMeteors);
    bool isEnergyCollision(const std::vector<CEnergy*> m_vEnergies);
    bool isLaserGunAndMeteorsCollision(const std::vector<CMeteors*> m_vMeteors);


private:


};

