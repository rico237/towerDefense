//
//  Joueur.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 06/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include <string.h>
#include "GraphicPrimitives.h"
#include "Helper.h"

class Joueur {
    
private:
    char *vieStr, *argentStr, *scoreStr;
    int vie, argent, score;
    float positionX = 0.0f;
    
public:
    // Constructeur & Destructor
    Joueur(int vie_, int argent_);
    ~Joueur();
    
    // Methods
    void draw();
    
    // Getters & Setters
    inline int getVie(){return vie;};
    inline int getArgent(){return argent;};
    inline int getScore(){return score;};
    inline void setLife(int life){vie += life;};
    inline void setMoney(int money){argent += money;};
    inline void setScore(int score_){score += score_;};
};
