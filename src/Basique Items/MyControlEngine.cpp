
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    // Bouton gauche de la souris clické
    GameState gameState = game.getCurrentState();
    float ajustementX = (x-400)/ 400.f;
    float ajustementY = (y-300)/ -300.f;
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (gameState == Playing) {
            if (ajustementY >= .6f) {
                // On est dans la zone de selection des vaisseaux
                sommeAchat = Vaisseau::getVesselPrice(ajustementX);
                float choix = 0.f;
                if (ajustementX <= 0.1f) {
                    if (ajustementX >= -0.22f) {
                        choix = 0.f;
                    } else {
                        choix = -.3f;
                    }
                } else {
                    choix = .4f;
                }
                game.getPlayer()->setChoixVaisseau(choix);
            }
            else if (game.getPlayer()->getArgent() >= sommeAchat && ajustementX <= .4f) {
                // On est dans dans la zone du damier du coup on ajoute un vaisseau
                game.addVessel(ajustementX, ajustementY);
            }
        }
    }
}

void MyControlEngine::KeyboardReleaseCallback(unsigned char key,int x, int y){
    if (key == 's' || key == 'S'){
        // Save game
        game.setCurrentState(Pause);
            // On met d'abord le jeu en pause
    }
    
    if (key == 'l' || key == 'L'){
        // Load old save
        // On met d'abord le jeu en pause
        game.setCurrentState(Pause);
        
    }
    
    if (key == ' '){
        // Next vague or start game
        game.setCurrentState(Playing);
    }
    
    if (key == 'n' || key == 'N'){
        // Restart
        game.restartGame();
    }
    
    if (key == 'm' || key == 'M'){
        // Play or pause
        if (game.getCurrentState() == Playing) game.setCurrentState(Pause);
        else if (game.getCurrentState() == Pause) game.setCurrentState(Playing);
    }
}
