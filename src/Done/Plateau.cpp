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
    
    vaisseaux = new Vaisseau *[lines * columns];
    for (int i = 0; i<lines; i++) {
        for (int j = 0; j<columns; j++) {
            vaisseaux [i * columns + j] = NULL;
        }
    }
}

Plateau::~Plateau(){
    delete [] vaisseaux;
    vaisseaux = NULL;
}

void Plateau::draw(){
    // Dessin des cases de jeu
    for (int i = 0; i<lines; i++) {
        for (int j = 0; j<columns; j++) {
            GraphicPrimitives::drawFillRect2D(getX() + (i * size), getY() + (j *size), size, size, getR(), getG(), getB());
            
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
    vaisseaux[indice]->~Vaisseau();
    vaisseaux[indice] = NULL;
}

