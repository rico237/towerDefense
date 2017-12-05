

#include <iostream>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"


int main(int argc, char * argv[])
{
    
    Engine e(argc,argv, 1200, 700, "Tower Defense");
    
    std::vector<Papillon *> paps;
    GraphicEngine * ge = new MyGraphicEngine(&paps);
    GameEngine * gme = new MyGameEngine(&paps);
    ControlEngine * ce = new MyControlEngine(&paps);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    e.start();
    return 0;
}
