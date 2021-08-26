#include "CCollisionManager.h"
#include <algorithm>
#include <vector>


bool CCollisionManager::isMeteorCollision(const std::vector<CMeteors*> m_vMeteors)
{
    //{
    //    //Returns true if player has collision with meteors object
    //    if (std::any_of(m_vMeteors.cbegin(), m_vMeteors.cend(), [&](const auto& i) { return CEngine::player->isCollision(i); }))
    //    {
    //        return true;
    //    }
    //    else
    //    {
    //        return false;1
    //    }

    //}
    return true;
}
bool CCollisionManager::isEnergyCollision(const std::vector<CEnergy*> m_vEnergies)
{

    //for (std::size_t i{ 0 }; i < m_vEnergies.size(); i++)
    //{
    //    if (CEngine::player->isCollision(m_vEnergies.at(i)))
    //    {
    //        m_vEnergies.at(i)->destRect = { 0,0,0,0 };
    //        m_EnergiesCounter++;
    //        //m_soundManager.playSound();
    //        m_soundManager.loadSound("music\\energyTake.wav");
    //    }
    //}

    return true;

}
bool CCollisionManager::isLaserGunAndMeteorsCollision(const std::vector<CMeteors*> m_vMeteors)
{
    return true;
}
