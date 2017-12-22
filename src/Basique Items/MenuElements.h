//
//  MenuElements.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 11/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "Colors.h"
#include "GraphicPrimitives.h"
#include "Vaisseaux_VS_Asteroides.h"

class MenuElements {
    
    Vaisseaux_VS_Asteroides &game;
    
public:
    MenuElements(Vaisseaux_VS_Asteroides &game_):game(game_){};
    ~MenuElements(){};
    
    // Methods
    void draw();
    void tick();
};
