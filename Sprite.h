//
//  Sprite.h
//  PacMan
//
//  Created by Todor Ivanov on 7/3/14.
//  Copyright (c) 2014 Todor Ivanov. All rights reserved.
//

#ifndef __PacMan__Sprite__
#define __PacMan__Sprite__

#include <iostream>
#include <vector>
#include "Time.h"
using namespace std;

// a Struct the will be used as a... Direction :)
struct Vector
{
    float x, y;
    
    Vector operator()(const float a,const float b)
    {
        this->x = a;
        this->y = b;
        return *this;
    }
};

// Struct which will keep position info
struct Coord
{
   float x, y;
   Coord operator+(const Vector& a);
   Coord operator-(const Vector& a);
   Coord operator=(const Coord& a);
   Coord operator*(const float timeLapse);
};

// Pretty self explanatory
enum State
{
    Standing = 0,
    MovingUp,
    MovingRight,
    MovingDown,
    MovingLeft,
    Dead
};

//////////////////////////////////////////////////////
//
// Base Sprite Class
//
//////////////////////////////////////////////////////
class Sprite{
public:
    virtual void  RenderSprite() =0;
    virtual void Check_Collision_Right(){};
    virtual void Check_Collision_Left(){};
    virtual void Check_Collision_Up(){};
    virtual void Check_Collision_Down(){};
    virtual void Motion_Enemies(const Sprite& pkm, const Sprite& enemie){}; // Will be derived only by enemy derived classes
    virtual void random_motion(const Sprite& obj1,const Sprite& obj2 ){}; // Will be used only by enemies
   // virtual int roundUp(const float var);
};

//////////////////////////////////////////////////////
//
// Enemy Classes
//
//////////////////////////////////////////////////////
/*class TealGhost: public Sprite{
public:
    TealGhost();
    void RenderSprite() override;
    void Motion_Enemies(const Sprite& pkm,const Sprite& teal) override;
};

class OrangeGhost: public Sprite{
public:
    virtual void RenderSprite();
    
};


class RedGhost: public Sprite{
public:
    virtual void RenderSprite();
    
};


class PinkGhost: public Sprite{
public:
    virtual  void RenderSprite();
    
};*/


#endif /* defined(__PacMan__Sprite__) */
