//
//  Pacman.h
//  PacMan
//
//  Created by Todor Ivanov on 6/18/15.
//  Copyright (c) 2015 Todor Ivanov. All rights reserved.
//

#ifndef __PacMan__Pacman__
#define __PacMan__Pacman__
#include <GLUT/glut.h>
#include "Time.h"
#include "Sprite.h"
#include "Lights.h"
#include "Maze.h"
#include <math.h>

class PacMan: public Sprite{
public:
    State state;
    Coord nextPos, currPos;
    
    PacMan();
    void Motion();
    void GetWallPos();
    int roundUp(const float a);
    bool Intersects(const Coord&);
    bool canMove(const char);
    void RenderSprite() override;
    void Check_Collision_Right() override;
    void Check_Collision_Up() override;
    void Check_Collision_Down() override;
    void Check_Collision_Left() override;
private:
    float sprite_radius;
    float step;
};



#endif /* defined(__PacMan__Pacman__) */
