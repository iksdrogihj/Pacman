//
//  Pacman.cpp
//  PacMan
//
//  Created by Todor Ivanov on 6/18/15.
//  Copyright (c) 2015 Todor Ivanov. All rights reserved.
//

#include "Pacman.h"

//@description: A Wall object that will be used by all our CheckIfIntersect`s methods
Coord Wall;
Vector positionVec;



// Sets Pacmans initial Position and his initial state
PacMan::PacMan()
:sprite_radius{0.5}, step{2}
{
    currPos.x = nextPos.x = 13;
    currPos.y = nextPos.y = 13;
    state = State::Standing;
}


// Draws Pacman.
void PacMan::RenderSprite()
{
    glPushMatrix();
    setMaterial(PacMan_Material);
    glColor3f(1, 1, 0);
    glutSolidSphere(sprite_radius, 10.0F, 10.0F);
    glPopMatrix();
}


// Finds out where the wall Coords are in the direction in which pacman is mooving
void PacMan::GetWallPos()
{
    switch (state)
    {
            
        case  State::MovingDown:
            for (size_t i = 0; i < maze.size(); i++)
            {
                if (maze[nextPos.y - i][nextPos.x] == Cell::Type::wall)
                {

                    Wall.y = floor(nextPos.y - i);
                    Wall.x = floor(nextPos.x);
                    cout << "Down Wall is at: " << Wall.y << endl;
                    break;
                }
            }
            break;
            
        case State::MovingUp:
            for (size_t i = 0; i < maze.size(); i++)
            {
                if (maze[nextPos.y + i][nextPos.x] == Cell::Type::wall)
                {
                    cout << "UP WAll is at:" << Wall.y << endl;
                    Wall.y = floor(nextPos.y + i);
                    Wall.x = floor(nextPos.x);
                    break;
                }
            }
            break;
            
        case State::MovingLeft:
            for (size_t i = 0; i < maze.size(); i++)
            {
                if (maze[nextPos.y][nextPos.x - i] == Cell::Type::wall)
                {
                    cout << "Left WAll is at:" << Wall.x << endl;
                    Wall.x = floor(nextPos.x - i);
                    Wall.y = floor(nextPos.y);
                    break;
                }
            }
            break;
            
        case State::MovingRight:
            for (size_t i = 0; i < maze.size(); i++)
            {
                if (maze[nextPos.y][nextPos.x + i] == Cell::Type::wall)
                {
                    cout << "Right WAll is at:" << Wall.x << endl;
                    Wall.x = floor(nextPos.x + i);
                    Wall.y = floor(nextPos.y);
                    break;
                }
            }
            break;
            
        default:
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Checks Whether Pacman has a colliding object infront of him while mooving downwards.
// if Pacman has has a wall infront, he stops.
// if Pacman has a pill infront, just eats it.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PacMan::Check_Collision_Down()
{
  //  cout << "Pacman Pos is: " << currPos.y << endl;
    GetWallPos();
    if (Intersects(Wall))
    {
        state = State::Standing;
    }
    
    else if(maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] == Cell::Type::ball)
    {
        maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] = Cell::Type::empty_space;
        nextPos = currPos - (positionVec(0.0f, (sprite_radius + step) *Time::time_lapse()));

        currPos = nextPos;
    }
    
    else
    {
        nextPos = currPos - (positionVec(0.0f, (sprite_radius + step) *Time::time_lapse()));
        currPos = nextPos;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Checks Whether Pacman has a colliding object infront of him while mooving upwards.
// if Pacman has has a wall infront, he stops.
// if Pacman has a pill infront, just eats it.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PacMan::Check_Collision_Up(){
    
    GetWallPos();
    if (Intersects(Wall))
    {
        nextPos.y = floor(currPos.y);
        state = State::Standing;
    }
    else  if (maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] == Cell::Type::ball)
    {
        maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] = Cell::Type::empty_space;
        nextPos = currPos + positionVec(0.0f, (sprite_radius + step) *Time::time_lapse());
        currPos = nextPos;
    }
    else
    {
        nextPos = currPos + positionVec(0.0f, (sprite_radius + step) *Time::time_lapse());
        currPos = nextPos;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Checks Whether Pacman has a colliding object infront of him while mooving right.
// if Pacman has has a wall infront, he stops.
// if Pacman has a pill infront, just eats it.
// if Pacman lands on the right teleportation space gets moved on the left Telep. space.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PacMan::Check_Collision_Right()
{
    
    GetWallPos();
    if (Intersects(Wall))
    {
        nextPos.x = floor(currPos.x);
        state = State::Standing;
    }
    
    else if (maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] == Cell::Type::ball)
    {
        maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] = Cell::Type::empty_space;
        nextPos = currPos + positionVec((sprite_radius + step) *Time::time_lapse(), 0.0f);
        currPos = nextPos;
        
    }
    
    else if (maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] == Cell::Type::teleport)
    {
        currPos.x = {1};
        currPos.y = {14};
        nextPos = currPos + positionVec((sprite_radius + step) *Time::time_lapse(), 0.0f);
        currPos = nextPos;
    }
    
    else
    {
        nextPos = currPos + positionVec((sprite_radius + step)*Time::time_lapse(), 0.0f);
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Checks Whether Pacman has a colliding object infront of him while mooving left.
// if Pacman has has a wall infront, he stops.
// if Pacman has a pill infront, just eats it.
// if Pacman lands on the left teleportation space gets moved on the right Telep. space.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PacMan::Check_Collision_Left(){
    GetWallPos();
    if (Intersects(Wall))
    {
        nextPos.x = nextPos.x - 0.2;
        state = State::Standing;
    }
    else if (maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] == Cell::Type::ball)
    {
        maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] = Cell::Type::empty_space;
        nextPos = currPos - positionVec((sprite_radius + step)*Time::time_lapse(), 0.0f);
    }
    else if (maze[static_cast<int>(currPos.y)][static_cast<int>(currPos.x)] == Cell::Type::teleport){
        currPos.x = {29};
        currPos.y = {14};
        nextPos = currPos - positionVec((sprite_radius + step)*Time::time_lapse(), 0.0f);
    }
    else nextPos = currPos - positionVec((sprite_radius + step)*Time::time_lapse(), 0.0f);
}



void PacMan::Motion(){
    switch(state) {
        case State::Standing:
            break;
        case State::MovingUp:
            Check_Collision_Up();
            break;
        case State::MovingRight:
            Check_Collision_Right();
            break;
        case State::MovingLeft:
            Check_Collision_Left();
            break;
        case State::MovingDown:
            Check_Collision_Down();
            break;
        case State::Dead:
            currPos.x ={1};
            currPos.y ={1};
            state = State::MovingRight;
            break;
        default:
            break;
    }
    
}




//////////////////////////////////////////////////////
//
// This is soo Wrong it makes Pacman cry. :(
//
//////////////////////////////////////////////////////
bool PacMan::Intersects(const Coord& wall)
{
    switch (state) {
        case State::MovingDown:
           // cout << "Floored Pos: " << floor(currPos.y) << endl;
            if((currPos.y - sprite_radius > wall.y )&&
               (currPos.y - sprite_radius - step < wall.y))
            {
                
                //currPos.y = static_cast<int>(currPos.y);
                return true;
            }
            else return false;

            //===========================================================================================
        case State::MovingUp:
            if((static_cast<int>(currPos.y) + sprite_radius < (wall.y))&&
               (static_cast<int>(currPos.y) + (sprite_radius + step) > wall.y))
            {
                cout << "UP POS:" << currPos.y << endl;
                return true;
            }
            
            else return false;
            break;
            
            //===========================================================================================
        case State::MovingLeft:
            if((currPos.x  - sprite_radius > wall.x)&&
               (currPos.x  - sprite_radius - step < wall.x))
            {
                cout << "LEFT POS:" << currPos.x << endl;
                return true;
            }
            
            else return false;
            //===========================================================================================
        case State::MovingRight:
            if((static_cast<int>(currPos.x) + sprite_radius < wall.x)&&
               (static_cast<int>(currPos.x) + sprite_radius + step > wall.x))
            {
                cout << "RIGHT POS:" << currPos.x << endl;
                return true;
            }
            
            else return false;
            
            
        default:
            return false;
            break;
    }
    
    
}

// Check wether u can move in the given direction
bool PacMan::canMove(const char dir)
{
    bool res = false;
    switch(dir)
    {
           
        case 'w':
        case 'W':

            if (currPos.y + (sprite_radius + step) != Cell::Type::wall)
            {
                res = true;
            }
            break;
        case 'd':
        case 'D':

            if (currPos.x + (sprite_radius + step) != Cell::Type::wall)
            {
                res = true;
            }
            break;
        case 'A':
        case 'a':

            if (currPos.x - (sprite_radius + step) != Cell::Type::wall)
            {
                res = true;            }
            break;
        case 's':
        case 'S':

            if (currPos.y - (sprite_radius + step) != Cell::Type::wall)
            {
                res = true;
            }
            break;
        default:
            res = true;
            break;
    }
    return res;
}

