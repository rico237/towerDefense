//
//  Helper.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 06/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
#include <string.h>
#include "GraphicPrimitives.h"

// Class comprenant des fonctions generiques pour le projet
class Helper {
public:
    static void miseEnForme(char *str, int nombre, float x, float y, float r, float g, float b){
        char s[50];
        strcpy(s,str);
        std::string nb = std::to_string(nombre);
        char const* pchar = nb.c_str();
        strncat(s,pchar,10);
        GraphicPrimitives::drawText2D(s, x, y, r, g, b);
    };
    
    static void print(char *str){
        std::cout << str << std::endl;
    };
};
