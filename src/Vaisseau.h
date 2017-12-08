//
//  Vaisseau.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 07/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include <iostream>
#include <sys/time.h>
#include "GraphicShape.h"
#include "GraphicPrimitives.h"
#include "Colors.h"

enum TypeVaisseau {
    Basique,
    Tank,
    Ralentisseur
};

class Vaisseau: public GraphicShape {
    float size = .1f;
    
    std::vector<float> projectiles;             // Vector with X position of projectiles
    
    long int time1 = time(0);
    long int time2;
    
    float attackSpeed, projectileSpeed;
    int puissance;
    int life = 1;
    TypeVaisseau type;
    
public:
    Vaisseau(float x_, float y_, TypeVaisseau type_);
    ~Vaisseau(){};
    
    // Methods
    void draw();
    void tick();
    inline void isHittenByMeteor(){life--;};
    
    // Getters & Setters
//    inline float getSize(){return size;};
    inline float getLife(){return  life;};
    inline TypeVaisseau getType(){return type;};
};
