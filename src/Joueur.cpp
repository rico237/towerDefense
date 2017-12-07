//
//  Joueur.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 06/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Joueur.h"


Joueur::Joueur(int vie_, int argent_): vie(vie_), argent(argent_){score = 0;}

void Joueur::draw(){
    Helper::miseEnForme((char *)"Argent : ", argent, -.98f, .90f, 1.f, 1.f, 1.f);
    Helper::miseEnForme((char *)"Score  : ", score, -.98f, .70f, 1.f, 1.f, 1.f);
    Helper::miseEnForme((char *)"Vie    : ", vie, -.98f, .80f, 1.f, 1.f, 1.f);
    
    // TODO : Déplacer ces affichages dans la partie Game Controller
    // Affichage différents types de tourelles
    GraphicPrimitives::drawText2D((char *)"Basique", -.50f, .70f, .3f, 0.f, 0.f);
    GraphicPrimitives::drawFillTriangle2D(-.45f, .9f, -.35f, .85f, -.45f, .8f, .3f, 0, 0);
    GraphicPrimitives::drawText2D((char *)"100$", -.45f, .63f, .3f, 0, 0);
    
    GraphicPrimitives::drawText2D((char *)"Ralentisseur", -.15f, .7f, 1.f, .5f, .3f);
    GraphicPrimitives::drawFillTriangle2D(-.15f, .9f, -.05f, .85f, -.15f, .8f, 1.f, .5f, .3f);
//    GraphicPrimitives:: drawText2D("200$", <#float x#>, <#float y#>, <#float r#>, <#float g#>, <#float b#>)
    
}
