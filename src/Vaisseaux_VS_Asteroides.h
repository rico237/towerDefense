//
//  Vaisseaux_VS_Asteroides.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 07/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>
#include <ctime>
#include "Vaisseau.h"
#include "Joueur.h"
#include "Asteroide.h"
#include "Plateau.h"

enum GameState {
    Initial,
    NextLevel,
    Playing,
    Pause,
    GameOver
};

class Vaisseaux_VS_Asteroides {
    GameState currentState;
    int currentWave;
    int nextWaveObjectif;
    
    std::list<Asteroide> asteroides;
    
    Plateau* damier;
    Joueur* player;
    float vitesse_attaqu;
    long time1 = time(0);
    long time2;
    
    void drawAllElements();
    void drawInitialMenu();
    void drawPauseMenu();
    void drawGameOverPanel();
    void generateAsteroide();
//    void animateProjectilesAndShips();
    void asteroidHitPlayer();
    void colisionAsteroProjectile();
    void asteroidHitShip();
    
public:
    // Constructor & Destructor
    Vaisseaux_VS_Asteroides();
    ~Vaisseaux_VS_Asteroides();
    
    // Getters & Setters
    inline GameState getCurrentState(){return currentState;};
    inline void setCurrentState(GameState cu){currentState = cu;};
    inline Joueur* getPlayer(){return player;};
    
    // Game Logic
    void draw();
    void tick();
    void restartGame();
    void saveGame();
    void loadGame();
    void addVessel(float x, float y); // Ajout de vaisseaux sur le damier
};
