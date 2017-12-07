//
//  Polygone.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 05/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include "GraphicPrimitives.h"

class Polygone {
    
protected:
    std::vector<float> x, y;
    float centerX, centerY;
    float r,g,b;
    float taille;
    
public:
    // Constructor & Destructors
    Polygone();
    Polygone(float x_, float y_, int cote, float taille_, float r, float g, float b);
    
    // Methods
    
    virtual void draw();
    void rotation(float degree);
    void deplacement(float velocityX, float velocityY);
    
    // Getters & Setters
    inline float getPolygoneX(){return centerX;};
    inline float getPolygoneY(){return centerY;};
    void setRGB(float r, float g, float b);
};
