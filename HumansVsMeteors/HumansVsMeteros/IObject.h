#pragma once
class IObject
{
public:
    IObject() {}
    ~IObject() {}
    virtual void draw() = 0;
    virtual void clean() = 0;
    //virtual void drop() = 0;

    //virtual void isCollision() = 0;
};