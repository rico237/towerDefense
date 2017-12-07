//
//  Vaisseaux_VS_Asteroides.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 07/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>

class Vaisseaux_VS_Asteroides {
    
    
public:
    // Constructor & Destructor
    Vaisseaux_VS_Asteroides();
    ~Vaisseaux_VS_Asteroides();
    
    // Getters & Setters
    
    // Game Logic
    void draw();
    void tick();
};
