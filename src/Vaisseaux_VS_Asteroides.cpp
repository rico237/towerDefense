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
    player = new Joueur(3, 1500);                // Vie, argent
} 

Vaisseaux_VS_Asteroides::~Vaisseaux_VS_Asteroides(){}

void Vaisseaux_VS_Asteroides::addVessel(float x, float y){
    int posX = (int)(x / damier->getSize() + 5);
    int posY = (int)(y / damier->getSize() + 5);
    
    int indice = posX +  posY * damier->getColumns();
    Vaisseau **va = damier->getVaisseaux();
    
    if (va[indice] == NULL) {
        if (player->getChoixVaisseau() < 0) {
            // Vaisseau Ralentisseur
            va[indice] = new Vaisseau(-1 + (posX * damier->getSize()), -1 + (posY * damier->getSize()), Basique);
        } else if (player->getChoixVaisseau() > 0) {
            // Vaisseau tank
            va[indice] = new Vaisseau(-1 + (posX * damier->getSize()), -1 + (posY * damier->getSize()), Tank);
        } else {
            // Vaisseau Basique
            va[indice] = new Vaisseau(-1 + (posX * damier->getSize()), -1 + (posY * damier->getSize()), Ralentisseur);
        }
        player->setMoney( -(va[indice]->getPrice()) ) ;
    }
}

// Game Logic
void Vaisseaux_VS_Asteroides::draw(){
    switch (currentState) {
        case Initial: // Démarage du jeu on affiche les règles du jeu et le titre
            drawInitialMenu();
            break;
        case NextLevel: // Afficher un message de vague suivante
            GraphicPrimitives::drawFillRect2D(0.5, 0.5, 400, 400, 0, 0, 0);
            GraphicPrimitives::drawText2D((char*)"Bar espace pour lancer la prochaine vague", -.5f, -.1, 1, 1, 1);
            break;
        case Playing:
            if (player->getVie() > 0) {
                drawAllElements();
            } else {
                currentState = GameOver;
            }
            break;
        case Pause:
            drawPauseMenu();
            break;
        case GameOver:
            drawGameOverPanel();
            break;
    }
}

void Vaisseaux_VS_Asteroides::drawGameOverPanel(){
    Helper::miseEnForme((char*)"Score Final : ", player->getScore(), -.25f, -.25f, 1, 1, 1);
    GraphicPrimitives::drawText2D((char *)"GAME OVER", -0.1f, 0, 1, 1, 1);
}

void Vaisseaux_VS_Asteroides::drawAllElements(){
    Helper::miseEnForme((char *)"Vague : ", currentWave, .6f, .9f, 0, 0, 1);
    damier->draw();
    player->draw();
    for (std::list<Asteroide>::iterator astero = asteroides.begin(); astero != asteroides.end(); astero++) {
        astero->draw();
    }
}

void Vaisseaux_VS_Asteroides::drawInitialMenu(){
    GraphicPrimitives::drawText2D((char*)"Bienvenue dans ce Jeu , voici les regles :" , -0.4f , 0.9f , 1.0f , 1.0f ,0.0f);
    GraphicPrimitives::drawText2D((char*)" - Vous devez survivre au differentes vagues d'asteroides" , -0.90f , 0.75f , 1.0f , 1.0f ,0.0f);
    GraphicPrimitives::drawText2D((char*)" - Vous avez 3 equipement differents pour vous defendre" , -0.90f , 0.65f , 1.0f , 1.0f ,0.0f);
    GraphicPrimitives::drawText2D((char*)" - Interdit de Defendre dans les 3 dernieres colonnes du Damier" , -0.90f , 0.55f , 1.0f , 1.0f ,0.0f);
    GraphicPrimitives::drawText2D((char*)" - Voici vos Vaisseaux :" , -0.90f , 0.45f , 1.0f , 1.0f ,0.0f);
    GraphicPrimitives::drawText2D((char*)"Ralentisseur : ", -0.90f , 0.30f , 0.30f , 0.0f, 1.0f );
    GraphicPrimitives::drawFillTriangle2D(-0.55f, 0.35f , -0.45f, 0.30f,-0.55f, 0.25f, 0.30f , 0.0f, 1.0f );
    GraphicPrimitives::drawText2D((char*)" Prix 300$    Il permet de ralentir les asteroides", -0.35f , 0.30f , 0.30f , 0.0f, 1.0f );
    GraphicPrimitives::drawText2D((char*)"Vaisseau basique",  -0.90f , 0.15f , 1.0f , 0.5f, 0.3f  );
    GraphicPrimitives::drawFillTriangle2D(-0.55f, 0.20f , -0.45f, 0.15f,-0.55f, 0.10f, 1.0f , 0.5f, 0.3f );
    GraphicPrimitives::drawText2D((char*)"Prix 100$    Il tire a grande cadence et inflige de faible degats", -0.35f , 0.15f , 01.0f , 0.5f, 0.3f );
    GraphicPrimitives::drawText2D((char*)"Tank",  -0.90f , 0.0f, 0.0f , 1.0f, 0.3f );
    GraphicPrimitives::drawFillTriangle2D(-0.55f, 0.05f , -0.45f, 0.0f,-0.55f, -0.05f, 0.0f , 1.0f, 0.3f );
    GraphicPrimitives::drawText2D((char*)"Prix 750$    Il tire a faible cadence et inflige de gros degats", -0.35f , 0.0f , 0.0f , 1.0f, 0.3f );
    
    GraphicPrimitives::drawText2D((char*)"(Clique droit pour continuer) " , 0.4f , -0.9f , 1.0f , 0.0f ,0.0f);
}

void Vaisseaux_VS_Asteroides::drawPauseMenu(){
    Helper::print((char *)"Fonction de dessin du menu - drawPauseMenu");
}

void Vaisseaux_VS_Asteroides::restartGame(){
    // Reset variables
    currentState = Initial;
    currentWave = 1;
    nextWaveObjectif = currentWave * 100;
    vitesse_attaqu = 2.f;
    damier = new Plateau;
    player = new Joueur(3, 1500);                // Vie, argent
    asteroides.erase(asteroides.begin(), asteroides.end());         // Possible segfault
}

void Vaisseaux_VS_Asteroides::tick(){
    
    // Load next level
    if (player->getScore() >= nextWaveObjectif) {
        currentWave ++;
        
        double coef = 0.0;
        
        if (currentWave < 6) {
            coef = 0.5;
        } else if (currentWave >= 6 && currentWave < 10) {
            coef = 0.25;
        } else {
            coef = 0.1;
        }
        
        vitesse_attaqu = 2.f / (currentWave * coef);
        nextWaveObjectif = sqrt(nextWaveObjectif) * 30 + player->getScore() * 1.6;
        currentState = NextLevel;
    }
    
    if (currentState == Playing){
        generateAsteroide();
        colisionAsteroProjectile();
        asteroidHitShip();
        asteroidHitPlayer();
    }
    
    
    damier->tick();
}

void Vaisseaux_VS_Asteroides::generateAsteroide(){
    long frequFPS = 1000000;
    struct timeval tempo2;
    gettimeofday(&tempo2, NULL);
    time2 = tempo2.tv_sec * frequFPS + tempo2.tv_usec;
    
    if ((time2 - time1) > (vitesse_attaqu * frequFPS)){
        
        float randomY = -1.f + ((rand() % damier->getLines()) - 1) * damier->getSize() + ((damier->getSize()/2) + 0.17f);
        int frequ = rand() % 15;
        if (frequ <= currentWave && currentWave > 2){
            frequ = rand() % 15;
            if (frequ <= currentWave) {
                asteroides.push_front(Asteroide(1.f, randomY, TankAsteroid));
            }
            else {
                asteroides.push_front(Asteroide(1.f, randomY, FastAsteroid));
            }
        } else {
            asteroides.push_front(Asteroide(1.f, randomY, BasiqueAsteroide));
        }
        
        struct timeval tempo1;
        gettimeofday(&tempo1, NULL);
        time1 = tempo1.tv_sec * frequFPS + tempo1.tv_usec;
    }
}


void Vaisseaux_VS_Asteroides::colisionAsteroProjectile(){
    for (std::list<Asteroide>::iterator astero = asteroides.begin(); astero != asteroides.end(); astero++) {
        int posX = (int) (astero->getX() / damier->getSize() +5);
        int posY = (int) (astero->getY() / damier->getSize() +5);
        
        for (int x = 0; x < posX; x++) {
            
            int indice = x + posY * damier->getColumns();
            if (damier->getVaisseaux()[indice] != NULL) {
                float projectile = damier->getVaisseaux()[indice]->projectiles.back();
                
                if ((astero->getX() <= projectile) && (((projectile > .001f) && (projectile < 1.f)) || ((projectile < -.001f) && (projectile > -1.f)))) {
                    
                    if (damier->getVaisseaux()[indice]->projectiles.size() != 0) {
                        damier->getVaisseaux()[indice]->projectiles.pop_back();
                    }
                    if (astero->hittenWith(damier->getVaisseaux()[indice]->getPower(), damier->getVaisseaux()[indice]->getType())) {
                        astero->gainAssocie(player);
                        astero = asteroides.erase(astero);
                        break;
                    }
                    
                }
            }
        }
    }
}
void Vaisseaux_VS_Asteroides::asteroidHitShip(){
    for (std::list<Asteroide>::iterator astero = asteroides.begin(); astero != asteroides.end(); astero++) {
        int posX = (int) (astero->getX() / damier->getSize() +5);
        int posY = (int) (astero->getY() / damier->getSize() +5);
        int indice = posX + posY * damier->getColumns();
        if (damier->getVaisseaux()[indice] != NULL && posX < damier->getColumns()) {
            damier->getVaisseaux()[indice]->isHittenByMeteor();
            if (damier->getVaisseaux()[indice]->getLife() == 0){
                damier->vaisseauDetruit(indice);
            }
        }
    }
}

void Vaisseaux_VS_Asteroides::asteroidHitPlayer(){
    for (std::list<Asteroide>::iterator astero = asteroides.begin(); astero != asteroides.end(); astero++) {
        if (astero->getX() <= -1.f){
            astero = asteroides.erase(astero);
            player->setLife(-1);
        } else {
            astero->tick();
        }
    }
}
