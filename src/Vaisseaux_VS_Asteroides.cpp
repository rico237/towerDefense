//
//  Vaisseaux_VS_Asteroides.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 07/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Vaisseaux_VS_Asteroides.h"

// Constructor & Destructor
Vaisseaux_VS_Asteroides::Vaisseaux_VS_Asteroides(){
    currentState = Initial;
    currentWave = 1;
    nextWaveObjectif = currentWave * 100;
    vitesse_attaqu = 2.f;
    damier = new Plateau;
    player = new Joueur(1, 500);                // Vie, argent
}

Vaisseaux_VS_Asteroides::~Vaisseaux_VS_Asteroides(){}

void Vaisseaux_VS_Asteroides::addVessel(float x, float y){
    int posX = (int)(x/damier->getSize() + 5);
    int posY = (int)(y/damier->getSize() + 5);
    int indice = posX + ( posY * damier->getColumns());
    Vaisseau **va = damier->getVaisseaux();
    
    if (va[indice] == NULL) {
        if (player->getChoixVaisseau() < 0) {
            // Vaisseau Ralentisseur
            va[indice] = new Vaisseau(-1 + (posX * damier->getSize()), -1 + (posY * damier->getSize()), Ralentisseur);
        } else if (player->getChoixVaisseau() > 0) {
            // Vaisseau tank
            va[indice] = new Vaisseau(-1 + (posX * damier->getSize()), -1 + (posY * damier->getSize()), Tank);
        } else {
            // Vaisseau Basique
            va[indice] = new Vaisseau(-1 + (posX * damier->getSize()), -1 + (posY * damier->getSize()), Basique);
        }
        player->setMoney( -(va[indice]->getPrice()) ) ;
    }
}

// Game Logic
void Vaisseaux_VS_Asteroides::draw(){
    switch (currentState) {
        case Initial: // Démarage du jeu on affiche les règles du jeu et le titre
            break;
        case NextLevel: // Afficher un message de vague suivante
            Graphic
            break;
        default: // Le joueur est en train de jouer
            drawAllElements();
            break;
    }
}

void Vaisseaux_VS_Asteroides::tick(){
    
}

void Vaisseaux_VS_Asteroides::drawAllElements(){
    Helper::miseEnForme((char *)"Vague : ", currentWave, .6f, .9f, 0, 0, 1);
    damier->draw();
    player->draw();
    for (std::vector<Asteroide>::iterator vai = asteroides.begin(); vai != asteroides.end(); vai++) {
        vai->draw();
    }
}
