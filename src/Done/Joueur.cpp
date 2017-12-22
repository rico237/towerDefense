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
    GraphicPrimitives::drawText2D((char *)"Basique", -.50f, .70f, Colors::getBasiqueRed(), Colors::getBasiqueGreen(), Colors::getBasiqueBlue());
    GraphicPrimitives::drawFillTriangle2D(-.45f, .9f, -.35f, .85f, -.45f, .8f, Colors::getBasiqueRed(), Colors::getBasiqueGreen(), Colors::getBasiqueBlue());
    GraphicPrimitives::drawText2D((char *)"100$", -.45f, .63f, Colors::getBasiqueRed(), Colors::getBasiqueGreen(), Colors::getBasiqueBlue());
    
    
    GraphicPrimitives::drawText2D((char *)"Ralentisseur", -.15f, .7f, Colors::getSlowingRed(), Colors::getSlowingGreen(), Colors::getSlowingBlue());
    GraphicPrimitives::drawFillTriangle2D(-.15f, .9f, -.05f, .85f, -.15f, .8f, Colors::getSlowingRed(), Colors::getSlowingGreen(), Colors::getSlowingBlue());
    GraphicPrimitives::drawText2D((char*)"300$", -.1f, .63f, Colors::getSlowingRed(), Colors::getSlowingGreen(), Colors::getSlowingBlue());
    
    GraphicPrimitives::drawText2D((char*)"Tank",.15f , .7f, Colors::getTankyRed(), Colors::getTankyGreen(), Colors::getTankyBlue());
    GraphicPrimitives::drawFillTriangle2D(.25f, .9f, .35f, .85f, .25f, .8f, Colors::getTankyRed(), Colors::getTankyGreen(), Colors::getTankyBlue());
    GraphicPrimitives::drawText2D((char*)"750$", .25f, .63f, Colors::getTankyRed(), Colors::getTankyGreen(), Colors::getTankyBlue());
    
    // Rectangle montrant la position de vaisseau choisi
    GraphicPrimitives::drawFillRect2D(choixVaisseau, .95f, .05f, .05f, Colors::getSelectionRed(), Colors::getSelectionGreen(), Colors::getSelectionBlue());
}
