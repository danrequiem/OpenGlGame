//
//  main.cpp
//  OpenGl
//
//  Created by Dan on 21/10/13.
//  Copyright (c) 2013 Dan. All rights reserved.
//

#include <iostream>

#include <OpenGL/gl.h>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <GLUT/glut.h>

#import "Vector3f.h"

using namespace std;
const int WINDOW_WIDTH= 1280;
const int WINDOW_HEIGHT= 720;
const char* WINDOW_TITLE= "OpenGl";

Vector3f CAMERA_POSITION;
Vector3f CAMERA_ROTATION;

bool KEYS[256];

void reshape(int w, int h);
void display();
void keyboardDown(unsigned char key, int x,int y);
void keyboardUp(unsigned char key, int x,int y);
void inputActions();

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
    
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    
    glutMainLoop();
    
    return 0;
}

void keyboardDown(unsigned char key, int x,int y)
{
    KEYS[key] = true;
    
}
void keyboardUp(unsigned char key, int x,int y)
{
    KEYS[key] = false;
    
}
void inputActions()
{
    if(KEYS['w']){
        CAMERA_POSITION.z += 0.01;
        
    }
    if(KEYS['s']){
        CAMERA_POSITION.z -= 0.01;
        
    }
    if(KEYS['a']){
        CAMERA_POSITION.x -= 0.01;
        
    }
    if(KEYS['d']){
        CAMERA_POSITION.x += 0.01;

        
    }


}
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
    inputActions();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    
    glTranslatef(-CAMERA_POSITION.x, -CAMERA_POSITION.y, CAMERA_POSITION.z);
    glRotatef(CAMERA_ROTATION.x, 1, 0, 0);
    glRotatef(CAMERA_ROTATION.y, 0, 1, 0);
    glRotatef(CAMERA_ROTATION.z, 0, 0, 1);
    
    glBegin(GL_TRIANGLES);
    
  
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1, -1,-3);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, 1,-3);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1, -1,-3);
    
    glEnd();
    
    glutSwapBuffers();
}