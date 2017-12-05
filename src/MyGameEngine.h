#pragma once

#include "Engine.h"
#include "Papillon.h"
class MyGameEngine:public GameEngine {
    std::vector<Papillon * > *paps;
public:
    
    MyGameEngine(std::vector<Papillon * > * paps_):paps(paps_){}
    
    virtual void idle();
    
};
