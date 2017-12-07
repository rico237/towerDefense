//
//  Asteroide.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 05/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include "Polygone.h"
#include <ctime>

enum TypeAsteroide {
    FEU,
    EAU,
    GLACE
};

class Asteroide: public Polygone {
    int vie;                        // Vie de l'asteroide avant sa mort
    float puissance;                // Dégats infligé à l'impact
    float vitesse;                  // Vitesse de déplacement
    bool canRotate;                 // Permettre a l'affichage de tourner
    TypeAsteroide type;
    
    clock_t start = std::clock();   // Ajuster l'animation en fonction du FPS
    
public:
    // Constructeur et Destructeur
//    Asteroide();
    Asteroide(int vie_, float puissance_, float vitesse_, float x, float y, int cote, bool canRotate_, TypeAsteroide type_);
    ~Asteroide();
    
    inline void looseLife(int lifeToLoose){vie -= lifeToLoose;};    // Fonction executée à la colision avec un missile ou un vaisseau
    inline bool isAlive(){return vie > 0;};                         // Vraie, si supérieur à 0
    void draw();                                                    // Fonction de dessin grâce aux librairies graphique
    void tick();                                                    // Changement des propriétés de l'asteroide à chaque tick
    
    // Getters
    inline int getLife(){return vie;};
    inline float getVitesse(){return vitesse;};
    inline float getAsteroideX(){return this->getPolygoneX();};
    inline float getAsteroideY(){return this->getPolygoneY();};
    inline float getPuissance(){return puissance;};
    inline float getTaille(){return puissance/50;};
    
};
