//
//  GraphicShape.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 07/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include <iostream>

class GraphicShape {
protected:
    float x,y;      // Position
    float r,g,b;    // Couleur
    
public:
    // Constructors & Destructors
    GraphicShape(float x_, float y_):x(x_), y(y_){setRGB(1, 1, 1);};
    GraphicShape(float x_, float y_, float r_, float g_, float b_):x(x_), y(y_), r(r_), g(g_), b(b_){};
    virtual ~GraphicShape(){};
    
    // Virtual Methods
    virtual void draw() = 0;
    virtual void tick() = 0;
    
    // Getters & Setters
    inline float getX(){return x;};
    inline float getY(){return y;};
    inline float getR(){return r;};
    inline float getG(){return g;};
    inline float getB(){return b;};
    
    inline void setX(float x_){x = x_;};
    inline void setY(float y_){y = y_;};
    inline void setRGB(float r_, float g_, float b_){r=r_; g=g_; b=b_;};
};
