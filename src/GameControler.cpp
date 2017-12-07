//
//  GameControler.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 06/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "GameControler.h"
#include "Vaisseaux_VS_Asteroides.h"

GameControler::GameControler(Engine *e_): e(e_){}

void GameControler::startAll(){
    
    std::vector<Papillon *> paps;
    Vaisseaux_VS_Asteroides game;
    
    MyGraphicEngine ge(game);
    MyGameEngine gme(game);
    MyControlEngine ce(game);
    
    e->setGraphicEngine(&ge);
    e->setGameEngine(&gme);
    e->setControlEngine(&ce);
    e->start();
}
