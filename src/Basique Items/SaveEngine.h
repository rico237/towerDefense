//
//  SaveEngine.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 19/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Vaisseaux_VS_Asteroides.h"

class SaveEngine {
    Vaisseaux_VS_Asteroides &game;
    
public:
    
    SaveEngine(Vaisseaux_VS_Asteroides &game_);
    ~SaveEngine();
    
    void saveGame();
    void loadGame();
};
