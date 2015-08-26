//
//  Lights.cpp
//  PacMan
//
//  Created by Todor Ivanov on 7/6/14.
//  Copyright (c) 2014 Todor Ivanov. All rights reserved.
//

#include "Lights.h"


const Material PacMan_Material
{
    {1.0F, 1.0F, 0.0F, 0.0F},
    {1.0F, 1.0F, 0.0F, 0.0F},
    {0.0F, 0.0F, 0.0F, 0.0F},
    50
};

const Material RedGhost_Material
{
    
    {1.0F, 0.0F, 0.0F, 0.0F},
    {1.0F, 0.0F, 0.0F, 0.0F},
    {0.0F, 0.0F, 0.0F, 0.0F},
    50
};

const Material TealGhost_Material
{
    {0.0F, 0.7F, 0.7F, 0.0F},
    {0.0F, 0.7F, 0.7F, 0.0F},
    {0.0F, 0.0F, 0.0F, 0.0F},
    50
};

const Material OrangeGhost_Material
{
    {1.0F, 0.5F, 0.0F, 0.0F},
    {1.0F, 0.5F, 0.0F, 0.0F},
    {0.0F, 0.0F, 0.0F, 0.0F},
    50
};

const Material PinkGhost_material
{
    {1.0F, 0.5F, 0.7F, 0.0F},
    {1.0F, 0.5F, 0.7F, 0.0F},
    {0.0F, 0.0F, 0.0F, 0.0F},
    50
};


    ////////////////////////////////////////////////////
    //
    //  Setter Functions
    //
    ////////////////////////////////////////////////////
void setMaterial(const Material& Mat){
     glMaterialfv(GL_FRONT, GL_AMBIENT, Mat.ambient);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, Mat.diffuse);
     glMaterialfv(GL_FRONT, GL_SPECULAR, Mat.specular);
     glMaterialf(GL_FRONT, GL_SHININESS, Mat.shinnines);
    
}


void setLight(GLenum LightNumber, const Light& light){
    glLightfv(LightNumber, GL_AMBIENT, light.ambient);
    glLightfv(LightNumber, GL_DIFFUSE, light.diffuse);
    glLightfv(LightNumber, GL_SPECULAR, light.specular);
    
}




void setLightPosition(GLenum LightNumber, GLfloat pos[4], GLfloat LightDir[3]){
    glLightfv(LightNumber, GL_SPOT_DIRECTION, LightDir);
    glLightfv(LightNumber, GL_POSITION, pos);
}







