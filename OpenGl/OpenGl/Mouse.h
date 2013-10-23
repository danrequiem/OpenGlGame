//
//  Mouse.h
//  OpenGl
//
//  Created by Dan on 22/10/13.
//  Copyright (c) 2013 Dan. All rights reserved.
//

#ifndef __OpenGl__Mouse__
#define __OpenGl__Mouse__

#include <iostream>

class Mouse{
    
public:
    static int currentX;
    static int currentY;
    static int lastX;
    static int lastY;
    static int deltaX;
    static int deltaY;
    
    static void update();
    static void move(int x, int y);
    
};

#endif /* defined(__OpenGl__Mouse__) */
