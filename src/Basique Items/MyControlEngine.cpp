
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    // Bouton gauche de la souris clické
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        paps->push_back(new Papillon((x-400) / 400.f, (y-300)/ -300.f ));
    }
}

void MyControlEngine::KeyboardReleaseCallback(unsigned char key,int x, int y){
    if (key == 's' || key == 'S'){
        // Save game
    }
    
    if (key == 'l' || key == 'L'){
        // Load old save
    }
    
    if (key == ' '){
        // Next vague
    }
    
    if (key == 'n' || key == 'N'){
        // Restart
    }
}
