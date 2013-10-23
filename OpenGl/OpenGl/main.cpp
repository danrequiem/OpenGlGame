//
//  main.cpp
//  OpenGl
//
//  Created by Dan on 21/10/13.
//  Copyright (c) 2013 Dan. All rights reserved.
//

#include <iostream>
#include <cmath>

#include <OpenGL/gl.h>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <GLUT/glut.h>

#include "Keyboard.h"
#include "Mouse.h"
#include "Vector3f.h"

using namespace std;

const int WINDOW_WIDTH= 1280;
const int WINDOW_HEIGHT= 720;
const char* WINDOW_TITLE= "OpenGl";

const float WALKING_SPEED = 1.0;
const float MOUSE_SENSITIVITY = 1.0;

const float MAX_TILT = 70;

float LAST_TIME;
float CURRENT_TIME;
float DELTA_TIME;

int MOUSE_LAST_X;
int MOUSE_LAST_Y;
int MOUSE_CURRENT_X;
int MOUSE_CURRENT_Y;
int MOUSE_DELTA_X;
int MOUSE_DELTA_Y;


Vector3f CAMERA_POSITION;
Vector3f CAMERA_ROTATION;

<<<<<<< HEAD
<<<<<<< HEAD
=======
bool KEYS[256];

>>>>>>> develop
=======
>>>>>>> develop
void reshape(int w, int h);
void display();
void preProcesEvents();

double degreesToRadians(double degrees);
double dsin(double theta);
double dcos(double theta);

int main(int argc, char ** argv)
{

    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA |GLUT_DOUBLE | GLUT_DEPTH);
    
    glutCreateWindow(WINDOW_TITLE);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
    glutKeyboardFunc(Keyboard::keyboardDown);
    glutKeyboardUpFunc(Keyboard::keyboardUp);
    
    glutMotionFunc(Mouse::move);
    glutPassiveMotionFunc(Mouse::move);
    
    glutMainLoop();
    
    return 0;
}
<<<<<<< HEAD
<<<<<<< HEAD
=======

void keyboardDown(unsigned char key, int x,int y)
=======
void preProcesEvents()
>>>>>>> develop
{
    CURRENT_TIME =((float) glutGet(GLUT_ELAPSED_TIME))/ 1000;
    
    DELTA_TIME = CURRENT_TIME - LAST_TIME;
    LAST_TIME = CURRENT_TIME;
    
    Mouse::update();

    CAMERA_ROTATION.y += (float)Mouse::deltaX*MOUSE_SENSITIVITY;
    CAMERA_ROTATION.x += (float)Mouse::deltaY*MOUSE_SENSITIVITY;
    
    if(CAMERA_ROTATION.x > MAX_TILT){
        CAMERA_ROTATION.x = MAX_TILT;
    }
    if(CAMERA_ROTATION.x < -MAX_TILT){
        CAMERA_ROTATION.x = -MAX_TILT;
    }
    
    if(Keyboard::keys['w']){
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME)*dsin(CAMERA_ROTATION.y);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME)*dcos(CAMERA_ROTATION.y);
        
    }
    if(Keyboard::keys['s']){
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME)*dsin(CAMERA_ROTATION.y +180);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME)*dcos(CAMERA_ROTATION.y +180);
        
    }
    if(Keyboard::keys['a']){
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME)*dsin(CAMERA_ROTATION.y + 270);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME)*dcos(CAMERA_ROTATION.y + 270);
        
    }
    if(Keyboard::keys['d']){
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME)*dsin(CAMERA_ROTATION.y + 90);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME)*dcos(CAMERA_ROTATION.y + 90);

        
    }


}
>>>>>>> develop
void reshape(int w, int h)
{
    if(h == 0){
        h = 1;
    }
    float ratio = (float) w / h;
    
    glMatrixMode(GL_PROJECTION);
    
    glViewport(0, 0, w, h);
    
    glLoadIdentity();
    
    gluPerspective(45, ratio, 0.01, 1000);
    
    glMatrixMode(GL_MODELVIEW);
    
}
void display()
{
    preProcesEvents();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
<<<<<<< HEAD
<<<<<<< HEAD
    glBegin(GL_TRIANGLES);
    
=======
    
    glTranslatef(CAMERA_POSITION.x, CAMERA_POSITION.y, CAMERA_POSITION.z);
=======
    
<<<<<<< HEAD
    glTranslatef(-CAMERA_POSITION.x, -CAMERA_POSITION.y, CAMERA_POSITION.z);
>>>>>>> develop
=======

>>>>>>> develop
    glRotatef(CAMERA_ROTATION.x, 1, 0, 0);
    glRotatef(CAMERA_ROTATION.y, 0, 1, 0);
    glRotatef(CAMERA_ROTATION.z, 0, 0, 1);
    glTranslatef(-CAMERA_POSITION.x, -CAMERA_POSITION.y, CAMERA_POSITION.z);
    
  
    
  
    glColor3f(1.0, 0.0, 0.0);
    glutWireCube(0.5);
    glColor3f(0.0, 1.0, 0.0);
    glutWireCube(1);
   /* glVertex3f(-1, -1,-3);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, 1,-3);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1, -1,-3);*/
    
    glEnd();
    
<<<<<<< HEAD
>>>>>>> develop
=======
>>>>>>> develop
    glutSwapBuffers();
}
double degreesToRadians(double degrees){
    return  degrees*M_PI/180;
}
double dsin(double theta){
    return sin(degreesToRadians(theta));
}
double dcos(double theta){
    return cos(degreesToRadians(theta));
}