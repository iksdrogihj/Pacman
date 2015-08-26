//
//  Lights.h
//  PacMan
//
//  Created by Todor Ivanov on 7/6/14.
//  Copyright (c) 2014 Todor Ivanov. All rights reserved.
//

#ifndef __PacMan__Lights__
#define __PacMan__Lights__

#include <iostream>
#include <GLUT/glut.h>


struct Material{
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shinnines;
};

struct Light{
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
};

/* Forward Declaration of Material Instances. */
extern const Material PacMan_Material;
extern const Material RedGhost_Material;
extern const Material TealGhost_Material;
extern const Material OrangeGhost_Material;
extern const Material PinkGhost_Material;
extern const Light white;

/* Forward Declarations of Setter Functions */
void setMaterial(const Material& Mat);
void setLightPosition(GLenum, GLfloat pos[4], GLfloat LightDir[4]);

#endif /* defined(__PacMan__Lights__) */
