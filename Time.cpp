//
//  Time.cpp
//  PacMan
//
//  Created by Todor Ivanov on 6/18/15.
//  Copyright (c) 2015 Todor Ivanov. All rights reserved.
//

#include "Time.h"

//////////////////////////////////////////////////////
//
// Calculates Delta time
//
//////////////////////////////////////////////////////
float Time::time_lapse()
{
    static float oldframe = 0;
    float timeCap = 0.17;
    float timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    
    float deltaTime = (timeSinceStart - oldframe)/1000;
    std::cout << "delta Time " << deltaTime << std::endl;
    if (deltaTime > timeCap || deltaTime <= 0)
        deltaTime = timeCap;
    oldframe = timeSinceStart;
    return deltaTime;
}

