#include <iostream>
#include <algorithm>


#include "CLevels.h"
#include "CTextureManager.h"
#include "CEngine.h"
CLevels::CLevels()
{
    m_texManager.load("counter", "assets\\Energies_counter.png");
    m_texManager.load("level_1", "assets\\level_1.png");
    m_texManager.load("level_2", "assets\\level_2.png");
    m_texManager.load("level_1_upleft", "assets\\level_1_upleft.png");
    m_texManager.load("level_2_upleft", "assets\\level_2_upleft.png");
    m_texManager.load("energy", "assets\\energy.png");
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
}

CLevels::~CLevels()
{
    for (auto p : m_vMeteors)
        delete[] p;
    for (auto p : m_vEnergies)
        delete[] p;
}
void CLevels::level_1() 
{
    //Meteors
    m_bLevel1 = true;
    std::cout << "---LEVEL1---" << std::endl;
    for (size_t i{ 0 }; i < 5; i++) 
    {
        SDL_RenderClear(CEngine::m_renderer);
        m_texManager.draw("level_1", 0, 0, 800, 800);
        SDL_RenderPresent(CEngine::m_renderer);
        SDL_Delay(250);
    }
    m_vMeteors.at(0)->setRect({ 50, 300, 100, 100 });
    m_vMeteors.at(1)->setRect({ 1100, 50, 50, 50 });
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


void CLevels::level_2() 
{
    //level2
    m_bLevel2 = true;
    for (size_t i{ 0 }; i < 5; i++)
    {
        SDL_RenderClear(CEngine::m_renderer);
        m_texManager.draw("level_2", 0, 0, 800, 800);
        SDL_RenderPresent(CEngine::m_renderer);
        SDL_Delay(250);
    }

    std::cout << "---LEVEL2---" << std::endl;

    //Init position of Meteors
    m_vMeteors.at(0)->destRect = { 50, 20, 100, 100 };
    m_vMeteors.at(1)->setRect({ 10, 50, 50, 50 });
    m_vMeteors.at(2)->setRect({ 20, 250, 50 ,50 });
    m_vMeteors.at(3)->setRect({ 1692 ,100, 50, 50 });
    m_vMeteors.at(4)->setRect({ 1890, 400, 50, 50 });
    m_vMeteors.at(5)->setRect({ 1250, 500, 50, 50 });
    m_vMeteors.at(6)->setRect({ 1630, 550, 50, 50 });
    m_vMeteors.at(7)->setRect({ 1430, 600, 50, 50 });
    m_vMeteors.at(8)->setRect({ 1000, 550, 50, 50 });
    m_vMeteors.at(9)->setRect({ 1900, 650, 50, 50 });
    m_vMeteors.at(10)->setRect({ 1940, 700, 80, 80 });
    //Store init pos for reset the level
    for (std::size_t i{ 0 }; i < m_vMeteors.size(); i++)
        m_vMeteorsInitPosition[i] = m_vMeteors.at(i)->getRect();
    //Energies
    m_vEnergies.at(0)->destRect = { 150, 50, 60, 60 };
    m_vEnergies.at(1)->destRect = { 150, 500, 60, 60 };
    m_vEnergies.at(2)->destRect = { 650, 50, 60, 60 };
    m_vEnergies.at(3)->destRect = { 650, 500, 60, 60 };
}
void CLevels::update()
{
    if (!getIsGameover() && m_bLevel1) 
    {
        int x = 0;
        for (std::size_t i{ 0 }; i < m_vMeteors.size(); i++) 
        {
            x -= 1;
            m_vMeteors.at(i)->setX(-1);
            if (m_vMeteors.at(i)->getRect().x < -100)
            {
                m_vMeteors.at(i)->setX(1000);
            }
        }
    }
    if (!getIsGameover() && m_bLevel2)
    {
        SDL_Rect meteorRect{};

        for (std::size_t i{ 0 }; i < m_vMeteors.size(); i++)
        {
            meteorRect.x -= 5;
            m_vMeteors.at(i)->setX(meteorRect.x);
            if (m_vMeteors.at(i)->getRect().x < -100)
            {
                //I should keep the initial positions
                meteorRect.x = 1000;
                m_vMeteors.at(i)->setRect(meteorRect);
            }
        }
    }
}
void CLevels::render()
{
    //Draw the level in the scren
    if (m_bLevel1) { m_texManager.draw("level_1_upleft", 0, 0, 800, 800); }
    if (m_bLevel2) { m_texManager.draw("level_2_upleft", 0, 0, 800, 800); }
    //Draw Game Assetes

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
}

bool CLevels::isMeteorsCollision()
{
    //Returns true if player has collision with meteors obj
    if (std::any_of(m_vMeteors.cbegin(), m_vMeteors.cend(), [](const auto& i) {return CEngine::player->check_collision(i); })) 
    {
        return true;
    }
    else 
    {
        return false;
    }

}
void CLevels::reset_level()
{
    for (std::size_t meteor{ 0 }; meteor < m_vMeteors.size(); meteor++) 
    {
        m_vMeteors[meteor]->getRect() = { m_vMeteorsInitPosition[meteor].x,m_vMeteorsInitPosition[meteor].y,m_vMeteorsInitPosition[meteor].h,m_vMeteorsInitPosition[meteor].w };
    }
    CEngine::player->clear();
    m_EnergiesCounter = 0;
    for (std::size_t i{ 0 }; i < m_vEnergies.size(); i++) 
    {
        m_vEnergies.at(i)->destRect = { m_vEnergiesInitPosition.at(i).x,m_vEnergiesInitPosition.at(i).y,m_vEnergiesInitPosition.at(i).h,m_vEnergiesInitPosition.at(i).w };
    }
}
//Energies
bool CLevels::check_colission_energies() 
{

    for (std::size_t i{ 0 }; i < m_vEnergies.size(); i++)
    {
        if (CEngine::player->check_collision(m_vEnergies.at(i))) 
        {
            m_vEnergies.at(i)->destRect = { 0,0,0,0 };
            m_EnergiesCounter++;
        }
    }
    return true;

}


void CLevels::render_counter()
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