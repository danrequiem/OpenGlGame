//
//  Keyboard.h
//  OpenGl
//
//  Created by Dan on 23/10/13.
//  Copyright (c) 2013 Dan. All rights reserved.
//

#ifndef __OpenGl__Keyboard__
#define __OpenGl__Keyboard__

#include <iostream>

class Keyboard{
public:
    
    static bool keys[256];
    static void keyboardDown(unsigned char key, int x,int y);
    static void keyboardUp(unsigned char key, int x,int y);
    

};

#endif /* defined(__OpenGl__Keyboard__) */
