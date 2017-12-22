//
//  Vaisseau.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 07/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Vaisseau.h"

Vaisseau::Vaisseau(float x_, float y_, TypeVaisseau type_):GraphicShape(x_ + .05f, y_ + .1f), type(type_){
    switch (type_) {
        case Basique:
            setRGB(Colors::getBasiqueRed(), Colors::getBasiqueGreen(), Colors::getBasiqueBlue());
            attackSpeed = 1.f;
            projectileSpeed = .01f;
            puissance = 50;
            prix = 100;
            break;
        case Tank:
            setRGB(Colors::getTankyRed(), Colors::getTankyGreen(), Colors::getTankyBlue());
            attackSpeed = 4.f;
            projectileSpeed = .004f;
            puissance = 150;
            prix = 750;
            break;
        case Ralentisseur:
            setRGB(Colors::getSlowingRed(), Colors::getSlowingGreen(), Colors::getSlowingBlue());
            attackSpeed = 1.5f;
            projectileSpeed = .02f;
            puissance = 0;
            prix = 300;
            break;
    }
}

int Vaisseau::getVesselPrice(float choice){
    if (choice <= 0.1f) {
        if (choice >= -0.22f) {
            return 100;
        }
        return 300;
    }
    else {
        return 750;
    }
}

void Vaisseau::draw(){
    // Dessin Vaisseau
    GraphicPrimitives::drawFillTriangle2D(getX(), getY() + size/2, getX()+size, getY(), getX(), getY() - size/2, getR() , getG(), getB());
    
    // Dessin Projectiles
    for (std::list<float>::iterator projX = projectiles.begin(); projX != projectiles.end(); projX++) {
        // On donne une plus grosse valeur au tank
        if (type == Tank) {
            // Ajouter une plus grande taille ??
            GraphicPrimitives::drawFillRect2D(*projX, getY() - .02f, .04f, .04f, getR(), getG(), getB());
        } else {
            GraphicPrimitives::drawFillRect2D(*projX, getY(), .02f, .02f, getR(), getG(), getB());
        }
    }
}

void Vaisseau::tick(){
    long cadense = 1000000;
    struct timeval temp1, temp2; // Cheque si aucune répercution sur le temps
    gettimeofday(&temp2, NULL);
    time2 = temp2.tv_sec * cadense + temp2.tv_usec;
    
    // Tir automatique en fonction de la vitesse d'attaque
    if((time2 - time1) > (attackSpeed * cadense)){
        projectiles.push_front(getX() + size);
        
        gettimeofday(&temp1, NULL);
        time1 = temp1.tv_sec * cadense + temp1.tv_usec;
    }
    
    // ESSAYER D'INTEGRER DANS LA CONDITION AU DESSUS
    // Déplacement des projectiles
    for (std::list<float>::iterator projX = projectiles.begin(); projX != projectiles.end(); projX++) {
        *projX += projectileSpeed;
    }
    
    // Si le dernier projectile est en dehors de l'écran on le détruit
    if (projectiles.back() > 1.f) {
        projectiles.pop_back();
    }
    
}
