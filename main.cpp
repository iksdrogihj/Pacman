#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include "Maze.h"
#include "Sprite.h"
#include "Lights.h"
#include <math.h>
#include "stdio.h"
#include "Pacman.h"
using namespace std;

PacMan Pacman;
//TealGhost teal;
int frame=0,time1 = 0,timebase=0;

////////////////////////////////////////////////////////
// Using pythagorean theorem to calculate the distance
// between the two given Objects (two sprites)
////////////////////////////////////////////////////////
/*float sprite_distance(const PacMan& obj1, const TealGhost& obj2)
{
    float c ={0.0F};
    return sqrt(c = pow(obj1.pos_x - obj2.pos_x, 2) + (pow(obj1.pos_y - obj2.pos_y, 2)));
}*/


/*void Sprite_Collision(void)
{
    if ( Pacman.sprite_radius + teal.sprite_radius >= sprite_distance(Pacman, teal))
    {
        Pacman.state = State::Dead;
    }
}
*/


////////////////////////////////////////////////////////
// Clears the Buffers
// Draws the main Scene
////////////////////////////////////////////////////////
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    Maze::Draw();
    
    glPushMatrix();
    //teal.RenderSprite();
    glPopMatrix();
    
    glPushMatrix();
    Pacman.Motion();
    glTranslated(Pacman.nextPos.x, Pacman.nextPos.y, 0.0);
    Pacman.RenderSprite();
    glPopMatrix();
    //Sprite_Collision();
 //   teal.Motion_Enemies(Pacman, teal);
    glutPostRedisplay();
    glutSwapBuffers();

}


void init()
{
    // Set the background color to black and sets/Enables light Parameters
    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    
    GLfloat lightpos[4] = {0.0F, 0.0F, 0.0F, 1.0F};
    GLfloat lightdir [4] = {0.0F, 0.0F, 0.0F, 1.0F};
    setLightPosition(GL_LIGHT0, lightpos, lightdir);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


}

void reshape(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45,(GLfloat) w / (GLfloat) h, 1, 1000);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(15, 10, 50, 15, 13, 0, 0, 1, 0);

}

void keyboard(unsigned char key, int x, int y){
    

    switch (key) {
        case 27:
            exit(0);
            break;
        case 'w':
        case 'W':
            if  ((Pacman.state != State::Dead)&&
                 (Pacman.canMove(key)))
                Pacman.state = State::MovingUp;
            break;
            
        case 'a':
        case 'A':
            if((Pacman.state != State::Dead)&&
               (Pacman.canMove(key)))
                
                Pacman.state = State::MovingLeft;
            break;
            
        case 'd':
        case 'D':
           if ((Pacman.state != State::Dead)&&
             (Pacman.canMove(key)))
            
                Pacman.state = State::MovingRight;
            break;
            
        case 's':
        case 'S':
           if ((Pacman.state != State::Dead)&&
             (Pacman.canMove(key)))
                Pacman.state = State::MovingDown;
            break;
            
        default:
            break;
    }
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("PacMan");

    init();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    
    
    glutMainLoop();
}