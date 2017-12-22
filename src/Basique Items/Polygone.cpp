//
//  Polygone.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 05/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Polygone.h"
#include <math.h>

Polygone::Polygone(float x_, float y_, int cote, float taille_, float r_, float g_, float b_):centerX(x_), centerY(y_),taille(taille_), r(r_), g(g_), b(b_){
    
    float tempX, tempY;
    int steps = 360 / cote;
    
    for (int i = 0; i < cote; i++) {
        tempX = taille * cos(i*steps) + x_;
        tempY = taille * sin(i*steps) + y_;
        x.push_back(tempX);
        y.push_back(tempY);
    }
}

void Polygone::draw(){
    GraphicPrimitives::drawFillPolygone2D(x, y, r, g, b);
}

void Polygone::deplacement(float velocityX, float velocityY){
    for (int i = 0; (int)x.size(); i++) {
        x[i] += velocityX;
        y[i] += velocityY;
    }
    
    centerX += velocityX;
    centerY += velocityY;
}

void Polygone::rotation(float degree){
    for (int i = 0; i < (int)x.size(); i++) {
        float unchangedX = x[i];
        
        x[i] = (x[i] - centerX) * cos(degree) - (y[i] - centerY) * sin(degree) + centerX;
        y[i] = (y[i] - centerY) * cos(degree) + (unchangedX - centerX) * sin(degree) + centerY;
    }
}

void Polygone::setRGB(float r_, float g_, float b_){
    r = r_;
    g = g_;
    b = b_;
}
