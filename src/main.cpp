

#include <iostream>
#include "Engine.h"
#include "GameControler.h"

int main(int argc, char * argv[])
{
    Engine e(argc,argv, 1200, 700, (char *)"Tower Defense");
    GameControler game(&e);
    game.startAll();
    return 0;
}
