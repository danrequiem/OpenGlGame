//
//  Keyboard.cpp
//  OpenGl
//
//  Created by Dan on 23/10/13.
//  Copyright (c) 2013 Dan. All rights reserved.
//

#include "Keyboard.h"

bool Keyboard::keys[256];

void Keyboard::keyboardDown(unsigned char k, int x,int y){
    keys[k] = true;
}

void Keyboard::keyboardUp(unsigned char k, int x,int y){
    keys[k] = false;
}
