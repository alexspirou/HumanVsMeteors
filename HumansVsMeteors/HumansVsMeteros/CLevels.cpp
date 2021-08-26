#include <iostream>
#include <algorithm>
#include <iterator>


#include "CLevels.h"
#include "CTextureManager.h"
#include "CEngine.h"
#include "CLaserGun.h"
#include "CFontTexture.h"

CLevels::CLevels()
{
    //Texture manager
    m_texManager.load("counter", "assets\\Energies_counter.png");
    m_texManager.load("level_1", "assets\\level_1.png");
    m_texManager.load("level_1_upleft", "assets\\level_1_upleft.png");
    m_texManager.load("energy", "assets\\energy.png");
    m_texManager.load("blackUp",  "assets\\blackUp.png");

    //Sound Manager


    //Meteors init
    m_vMeteors.resize(12, nullptr);
    m_vMeteorsInitPosition.resize(12);
    for (std::size_t i{ 0 }; i < m_vMeteors.size(); i++) 
    {
        m_vMeteors[i] = new CMeteors(0, 0, 0, 0);
    }
    //Energies init
    m_vEnergies.resize(4, nullptr);
    m_vEnergiesInitPosition.resize(4);
    for (size_t i{ 0 }; i < m_vEnergies.size(); i++)
    {
        m_vEnergies.at(i) = new CEnergy(0, 0, 0, 0);
    }

    //Alien init 
    greenAliens = new CAlien(1000,200, 50, 50);

    //Score init 
    score = new CFontTexture();
    score->loadFont("D:\\repos\\HumanVsMeteors\\HumansVsMeteors\\HumansVsMeteros\\Franchise.ttf", 40);

}

CLevels::~CLevels()
{
    for (auto p : m_vMeteors)
    {
        delete[] p;
        p = NULL;
    }
    for (auto p : m_vEnergies)
    {
        delete[] p;
        p = NULL;
    }

    delete greenAliens;
    greenAliens = NULL;
}
void CLevels::level_1() 
{
    //Meteors
    m_bLevel1 = true;
    for (size_t i{ 0 }; i < 5; i++) 
    {
        SDL_RenderClear(CEngine::m_renderer);
        m_texManager.draw("level_1", 0, 0, 800, 800);

        SDL_RenderPresent(CEngine::m_renderer);
        SDL_Delay(250);
    }
    m_vMeteors.at(0)->setRect({ 500, 300, 210, 197 });
    m_vMeteors.at(1)->setRect({ 100, 50, 50, 50 });
    m_vMeteors.at(2)->setRect({ 1250, 250, 50 ,50 });
    m_vMeteors.at(3)->setRect({ 1692 ,100, 50, 50 });
    m_vMeteors.at(4)->setRect({ 1890, 400, 50, 50 });
    m_vMeteors.at(5)->setRect({ 1250, 500, 50, 50 });
    m_vMeteors.at(6)->setRect({ 1630, 550, 50, 50 });
    m_vMeteors.at(7)->setRect({ 1430, 600, 50, 50 });
    m_vMeteors.at(8)->setRect({ 1000, 550, 50, 50 });
    m_vMeteors.at(9)->setRect({ 1900, 650, 50, 50 });
    m_vMeteors.at(10)->setRect({ 1940, 700, 80, 80 });

    //store init pos for reset the level
    for (std::size_t i{ 0 }; i < m_vMeteors.size(); i++)
        m_vMeteorsInitPosition.at(i) = m_vMeteors.at(i)->getRect();

    //Energies
    m_vEnergies.at(0)->destRect = { 150, 50, 60, 60 };
    m_vEnergies.at(1)->destRect = { 150, 500, 60, 60 };
    m_vEnergies.at(2)->destRect = { 650, 50, 60, 60 };
    m_vEnergies.at(3)->destRect = { 650, 500, 60, 60 };

    //store init pos for reset the level
    for (std::size_t i{ 0 }; i < m_vEnergies.size(); i++)
        m_vEnergiesInitPosition.at(i) = m_vEnergies.at(i)->destRect;
}

void CLevels::update()
{

    //Update meteors
    for (int i = 0; i < m_vMeteors.size(); i++) m_vMeteors[i]->update();
    //Check for collision 
    greenAliens->update();

    //Level 1 
    if (!isGameOver() && m_bLevel1) 
    {
        
        for (std::size_t i{ 0 }; i < m_vMeteors.size(); i++) 
        {
            
            m_vMeteors[i]->moveX(2);
            if (m_vMeteors[i]->getRect().x < -100)
            {
                m_vMeteors[i]->setX(1000);
            }
        }
    }


    //Game over
    if (isGameOver()) { greenAliens->setFire(false); }
    else { greenAliens->setFire(true); }
}
void CLevels::render()
{
    //Draw the upper game bar
    if (m_bLevel1)
    { 
        m_texManager.draw("blackUp", 0, -20, 800, 800);
        m_texManager.draw("level_1_upleft", 0, -15, 800, 800);
        score->renderScore(m_countScore);

        if (isLaserGunCollision()) { m_countScore += 100; }
    }

    //Draw Game Assets

    //Energies
    for (std::size_t energy{ 0 }; energy < m_vEnergies.size(); energy++)
    {
        m_vEnergies[energy]->draw();
    }
    //Meteors
    for (std::size_t meteor{ 0 }; meteor < m_vMeteors.size(); meteor++)
    {
        m_vMeteors[meteor]->draw();
    }
    //Aliens
    greenAliens->draw();
}

bool CLevels::isMeteorCollision()
{
    //Returns true if player has collision with meteors object
    if (std::any_of(m_vMeteors.cbegin(), m_vMeteors.cend(), [&](const auto& i) { return CEngine::player->isCollision(i); }))
    {
        return true;
    }
    else 
    {
        return false;
    }

}

//Energies
bool CLevels::isEnergyCollision()
{

    for (std::size_t i{ 0 }; i < m_vEnergies.size(); i++)
    {
        if (CEngine::player->isCollision(m_vEnergies.at(i)))
        {
            m_vEnergies.at(i)->destRect = { 0,0,0,0 };
            m_EnergiesCounter++;
            //m_soundManager.playSound();
            m_soundManager.loadSound("music\\energyTake.wav");
        }
    }

    return true;

}

bool CLevels::isLaserGunCollision()
{
 
    if (std::any_of(m_vMeteors.cbegin(), m_vMeteors.cend(), [&](const auto& i) { return CEngine::player->getLaserGun()->isCollision(i); }))
    {
        //Returns true if player has collision with meteors object
        std::vector<CMeteors*>::iterator it = std::find_if(m_vMeteors.begin(), m_vMeteors.end(), [&](const auto& meteor) { return CEngine::player->getLaserGun()->isCollision(meteor); });
        int index = std::distance(m_vMeteors.begin(), it);
        m_vMeteors[index]->setExplosion(true);
        CEngine::player->setIsFire(false);
        m_soundManager.loadSound("music\\meteorExplosion.wav");
        m_vMeteors[index]->setX(1200);
        return true;
    }

    return false;
 }

bool CLevels::isAlienGunCollision()
{
    auto beamVector = greenAliens->getAlienBeams();
    if (std::any_of(beamVector.cbegin(), beamVector.cend(), [&](const auto& beam) {return CEngine::player->isCollision(beam); }))
    {
        m_bIsAllienCollision = true;
        return m_bIsAllienCollision;
    }
    m_bIsAllienCollision = false;
    return m_bIsAllienCollision;
}

void CLevels::reset_level()
{
    for (std::size_t meteor{ 0 }; meteor < m_vMeteors.size(); meteor++) 
    {
        m_vMeteors[meteor]->setRect({ m_vMeteorsInitPosition[meteor].x,m_vMeteorsInitPosition[meteor].y,m_vMeteorsInitPosition[meteor].h,m_vMeteorsInitPosition[meteor].w });
    }
    CEngine::player->clear();
    m_EnergiesCounter = 0;
    for (std::size_t i{ 0 }; i < m_vEnergies.size(); i++) 
    {
        m_vEnergies.at(i)->destRect = { m_vEnergiesInitPosition.at(i).x,m_vEnergiesInitPosition.at(i).y,m_vEnergiesInitPosition.at(i).h,m_vEnergiesInitPosition.at(i).w };
    }

    //Reset alien
    greenAliens->resetPositions();
}



void CLevels::renderEnergyCounter()
{
    m_texManager.draw("counter", 0, -10, 650, 650);

    if (m_EnergiesCounter == 1) 
    {
        m_texManager.draw("energy", 140, 590, 40, 40);
        m_texManager.draw("2", 0, 0, 0, 0);
        m_texManager.draw("3", 0, 0, 0, 0);
        m_texManager.draw("4", 0, 0, 0, 0);
    }
    else if (m_EnergiesCounter == 2) 
    {
        m_texManager.draw("energy", 140, 590, 40, 40);
        m_texManager.draw("energy", 180, 590, 40, 40);
        m_texManager.draw("3", 0, 0, 0, 0);
        m_texManager.draw("4", 0, 0, 0, 0);
    }
    else if (m_EnergiesCounter == 3) 
    {
        m_texManager.draw("energy", 140, 590, 40, 40);
        m_texManager.draw("energy", 180, 590, 40, 40);
        m_texManager.draw("energy", 220, 590, 40, 40);
        m_texManager.draw("4", 0, 0, 0, 0);
    }
    else if (m_EnergiesCounter == 4) 
    {
        m_texManager.draw("energy", 140, 590, 40, 40);
        m_texManager.draw("energy", 180, 590, 40, 40);
        m_texManager.draw("energy", 220, 590, 40, 40);
        m_texManager.draw("energy", 260, 590, 40, 40);
    }

}