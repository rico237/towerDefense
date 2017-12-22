
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    game.draw();
}

void MyGraphicEngine::reshape(int width, int height){
    Helper::print((char*)"Resize function");
}
