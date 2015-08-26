//
//  Maze.h
//  PacMan
//
//  Created by Todor Ivanov on 7/1/14.
//  Copyright (c) 2014 Todor Ivanov. All rights reserved.
//

#ifndef __PacMan__Maze__
#define __PacMan__Maze__

#include <iostream>
#include "Sprite.h"
#include <vector>
using namespace std;

// @description: Declaration of our Maze
//extern vector<vector<int> > maze;

//////////////////////////////////////////////////////
//
// A Struct which Holds Cell Information.
//
//////////////////////////////////////////////////////
struct Cell
{
    enum Type {ball = 0, wall, powerup, empty_space, teleport};
};


//////////////////////////////////////////////////////
//
// Maze Class
//
//////////////////////////////////////////////////////

class Maze{
public:
    int cellTypeAt(Coord&);
    void Draw(void);
    static vector<vector<int> >* getMaze();
    
private:
    Maze();
    ~Maze();
    static vector<vector <int> > *maze;
    GLfloat wall_material[4];     // wall color
    GLfloat pill_material[4];      // pill color
    GLfloat power_up_material[4]; // power_up ball color
};

#endif /* defined(__PacMan__Maze__) */
