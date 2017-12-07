#pragma once
#include "Engine.h"
#include "Vaisseaux_VS_Asteroides.h"

class MyGraphicEngine:public GraphicEngine {
    
    Vaisseaux_VS_Asteroides &game;
    
public:
    MyGraphicEngine(Vaisseaux_VS_Asteroides &game_): game(game_){};
    
    virtual void Draw();
};
