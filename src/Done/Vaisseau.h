//
//  Vaisseau.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 07/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include <iostream>
#include <list>
#include <sys/time.h>
#include "GraphicShape.h"
#include "GraphicPrimitives.h"
#include "Colors.h"
#include "Helper.h"

enum TypeVaisseau {
    Basique,
    Tank,
    Ralentisseur
};

class Vaisseau: public GraphicShape {
    float size = .1f;
    
    long int time1 = time(0);
    long int time2;
    
    
    
    float attackSpeed, projectileSpeed;
    int puissance, prix;
    int life = 1;
    TypeVaisseau type;
    
public:
    Vaisseau(float x_, float y_, TypeVaisseau type_);
    ~Vaisseau(){Helper::print((char*)"Destruction vaisseau");};
    
    std::list<float> projectiles;             // Vector with X position of projectiles
    
    // Methods
    void draw();
    void tick();
    inline void isHittenByMeteor(){life--;};
    
    static int getVesselPrice(float choice);
    
    // Getters & Setters
//    inline float getSize(){return size;};
    inline float getLife(){return  life;};
    inline TypeVaisseau getType(){return type;};
    inline int getPrice(){return prix;};
    inline int getPower(){return  puissance;};
//    inline std::list<float> getProjectiles(){return projectiles;};
};
