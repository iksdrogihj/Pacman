//
//  Sprite.cpp
//  PacMan
//
//  Created by Todor Ivanov on 7/3/14.
//  Copyright (c) 2014 Todor Ivanov. All rights reserved.
//

#include "Sprite.h"
#include <GLUT/glut.h>
#include "Lights.h"
#include "Maze.h"
#include "math.h"
#include <iomanip>
using namespace std;

//////////////////////////////////////////////////////
//
// Overloades
//
//////////////////////////////////////////////////////
Coord Coord::operator+(const Vector& a)
{
    this->x += a.x;
    this->y += a.y;
    return *this;
}

Coord Coord::operator-(const Vector& a)
{
    this->x -= a.x;
    this->y -= a.y;
    return *this;
}

Coord Coord::operator=(const Coord& a)
{
    this->x = a.x;
    this->y = a.y;
    return *this;
}

Coord Coord::operator*(const float timeLapse)
{

    this->y *= timeLapse;
    return *this;
}

//=============================================================================================================================
/*TealGhost::TealGhost()
{   pos_y  = {5};
    pos_x = {5};
}

void TealGhost::RenderSprite(){
    
    glPushMatrix();
    glTranslated(pos_x, pos_y, 0.0F);
    setMaterial(TealGhost_Material);
    glutSolidSphere(sprite_radius, 10.0F, 10.0F);
    glPopMatrix();
}

void TealGhost::Motion_Enemies(const Sprite& pkm, const Sprite& teal){
    
    if (pkm.GetCords_x() > teal.GetCords_x()) {
        pos_x += step;
    }
    if (pkm.GetCords_y() > teal.GetCords_y()) {
        pos_y += step;
    }
    if (pkm.GetCords_x() < teal.GetCords_x()) {
        pos_x -= step;
    }
    if (pkm.GetCords_y() < teal.GetCords_y()) {
       pos_y -= step;
    }
}*/

