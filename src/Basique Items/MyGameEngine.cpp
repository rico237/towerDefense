#include "MyGameEngine.h"

void MyGameEngine::idle(){
    if (game.getCurrentState() == Playing && game.getPlayer()->getVie() > 0){
        game.tick();
    }
}
