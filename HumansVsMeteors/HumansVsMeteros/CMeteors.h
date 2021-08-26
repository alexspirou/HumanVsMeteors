#pragma once
#include "IObject.h"
#include "CEnemy.h"
#include "CTextureManager.h"
#include  <vector>

class CMeteors : public CEnemy
{
public:
    CMeteors(int x, int y, int w, int h);
    virtual ~CMeteors() {}
    virtual void draw() override;
    virtual void clean() override;
    void update();
    void setExplosion(bool explosion) { m_bIsExpolosion = explosion; }
    //Getters
    bool isExplosion() { return m_bIsExpolosion; }


private:

    bool m_bIsExpolosion{false};
};

