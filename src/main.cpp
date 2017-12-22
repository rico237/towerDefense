

#include <iostream>
#include "Engine.h"
#include "GameControler.h"

int main(int argc, char * argv[])
{
    Engine e(argc,argv);
    GameControler game(&e);
    game.startAll();
    return 0;
}
