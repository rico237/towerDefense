#pragma once
#include "Engine.h"
#include "Vaisseaux_VS_Asteroides.h"
#include "Helper.h"

class MyGraphicEngine:public GraphicEngine {
    
    Vaisseaux_VS_Asteroides &game;
    
public:
    MyGraphicEngine(Vaisseaux_VS_Asteroides &game_): game(game_){};
    
    virtual void Draw();
    virtual void reshape(int width, int height);
};
