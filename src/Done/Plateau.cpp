//
//  Plateau.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 08/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Plateau.h"

Plateau::Plateau(float size_):GraphicShape(-1,-1, .27, .86, .37),size(size_){
    lines = 8; columns = 10;
    
    vaisseaux = new Vaisseau * [columns * lines];
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            vaisseaux[i * columns + j] = NULL;
        }
    }
}

Plateau::~Plateau(){
//    delete [] vaisseaux;
//    vaisseaux = NULL;
}

void Plateau::draw(){
//    Helper::print("Fonction draw du plateau");
    // Dessin des cases de jeu
    for (int i = 0; i<columns; i++) {
        for (int j = 0; j<lines; j++) {
            
            if ((i % 2 == 0) && (j % 2 == 0)) {
                GraphicPrimitives::drawFillRect2D(-1.f + (i * size), -1.f + (j * size), size, size, getR(), getG(), getB());
            } else if ((i % 2 == 1) && (j % 2 == 0)){
//                UIColor(red:0.09, green:0.66, blue:0.11, alpha:1.00)
                GraphicPrimitives::drawFillRect2D(-1.f + (i * size), -1.f + (j * size), size, size, .09f, .66f, .11f);
            } else if((i % 2 == 0) && (j % 2 == 1)){
//                UIColor(red:0.05, green:0.45, blue:0.06, alpha:1.00)
                GraphicPrimitives::drawFillRect2D(-1.f + (i * size), -1.f + (j * size), size, size, .05,.45, .06);
            } else {
                GraphicPrimitives::drawFillRect2D(-1.f + (i * size), -1.f + (j * size), size, size, getR(), getG(), getB());
            }
            
//            GraphicPrimitives::drawOutlinedRect2D(getX() + (i * size), getY() + (j *size), size, size, 1,1,1);
        }
    }
    
    // Dessin des vaisseaux
    for (int i = 0; i<lines; i++) {
        for (int j = 0; j<columns; j++) {
            Vaisseau *v = vaisseaux[i*columns+j];
            if (v != NULL) {
                v->draw();
            }
        }
    }
}

void Plateau::tick(){
//    Helper::print("Fonction tick du plateau");
    for (int i = 0; i<lines; i++) {
        for (int j = 0; j<columns; j++) {
            Vaisseau *v = vaisseaux[i*columns+j];
            if (v != NULL) {
                v->tick();
            }
        }
    }
}

void Plateau::vaisseauDetruit(int indice){
    Helper::printWithVar("Fonction plateau vaisseau detruit en position indice", indice);
    vaisseaux[indice]->~Vaisseau();
    vaisseaux[indice] = NULL;
}

