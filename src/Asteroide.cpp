//
//  Asteroide.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 05/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Asteroide.h"

//Asteroide::Asteroide(): Polygone(9,9,30,30){
//    type = FEU;
//    
//}

Asteroide::Asteroide(int vie_, float puissance_, float vitesse_, float x, float y, int cote = 4, bool canRotate_ = true, TypeAsteroide type_ = FEU): Polygone(10,10,4,30, 0,0,0), type(type_), canRotate(canRotate_), vie(vie_), vitesse(vitesse_), puissance(puissance_){
    switch (type_) {
        case FEU:
            setRGB(1, 0, 0);
            break;
        case EAU:
            setRGB(0, 0, 1);
            puissance *= 0.2;
            vie += 20;
            break;
        case GLACE:
            setRGB(27, 176, 244);
            puissance *= 0.4;
            vie += 40;
            break;
    }
}

void Asteroide::draw(){
    // Virtual method
//    Polygone::draw();
    std::cout << "Asteroide" << std::endl;
//    GraphicPrimitives::drawFillPolygone2D(x, y, 1, 1, 1);
}

void Asteroide::tick(){
    // Virtual Method
    deplacement(vitesse, 0);
}

Asteroide::~Asteroide(){}
