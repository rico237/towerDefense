//
//  Plateau.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 08/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include "GraphicPrimitives.h"
#include "Colors.h"
#include "Helper.h"
#include "Vaisseau.h"

class Plateau : public GraphicShape {
    float size;
    int lines, columns;
    Vaisseau ** vaisseaux;
    
public:
    // Constructor & Destructors
    Plateau(float size_ = 0.2f);
    ~Plateau();
    
    // Methods
    void draw();
    void tick();
    void vaisseauDetruit(int indice);
    
    // Getters & Setters
    inline float getSize(){return size;};
    inline int getLines(){return lines;};
    inline int getColumns(){return columns;};
    inline Vaisseau ** getVaisseaux(){return vaisseaux;};
    inline void setSize(float siz){size = siz;};
    inline void setLines(int lin){lines = lin;};
    inline void setColumns(int col){columns = col;};
};
