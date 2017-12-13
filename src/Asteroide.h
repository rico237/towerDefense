//
//  Asteroide.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 05/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include "GraphicShape.h"
#include <ctime>
#include <sys/time.h>
#include "Joueur.h"
#include "Vaisseau.h"

enum TypeAsteroide {
    BasiqueAsteroide,
    FastAsteroid,
    TankAsteroid
};

class Asteroide: public GraphicShape {
    int vie;                        // Vie de l'asteroide avant sa mort
    float vitesse;                  // Vitesse de déplacement
    float frequence;
    float size;
    long int time1 = time(0);
    long int time2;
    TypeAsteroide type;
    
public:
    // Constructeur et Destructeur
    Asteroide( float x, float y, TypeAsteroide type_);
    ~Asteroide(){Helper::print((char*)"Destruction Asteroide");};
    
    inline void looseLife(int lifeToLoose){vie -= lifeToLoose;};    // Fonction executée à la colision avec un missile ou un vaisseau
    inline bool isAlive(){return vie > 0;};                         // Vraie, si supérieur à 0
    void draw();                                                    // Fonction de dessin grâce aux librairies graphique
    void tick();                                                    // Changement des propriétés de l'asteroide à chaque tick
    bool hittenWith(int power, TypeVaisseau type);
    void gainAssocie(Joueur *joueur);
    
    // Getters
    inline int getLife(){return vie;};
    inline float getVitesse(){return vitesse;};
    inline TypeAsteroide getType(){return type;};
//    inline float getAsteroideX(){return this->getX();};
//    inline float getAsteroideY(){return this->getY();};
    inline float getTaille(){return size;};
    
};
