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


using namespace std;
const int WINDOW_WIDTH= 1280;
const int WINDOW_HEIGHT= 720;
const char* WINDOW_TITLE= "OpenGl";

void display();

int main(int argc, char ** argv)
{

    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA |GLUT_DOUBLE | GLUT_DEPTH);
    
    glutCreateWindow(WINDOW_TITLE);
    glutDisplayFunc(display);
    
    glutMainLoop();
    
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glBegin(GL_TRIANGLES);
    
    glutSwapBuffers();
}