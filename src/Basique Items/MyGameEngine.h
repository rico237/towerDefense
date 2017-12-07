#pragma once
#include "Engine.h"
#include "Vaisseaux_VS_Asteroides.h"

class MyGameEngine:public GameEngine {
    Vaisseaux_VS_Asteroides &game;
    
public:
    MyGameEngine(Vaisseaux_VS_Asteroides &v):game(v){};
    
    virtual void idle();
};
