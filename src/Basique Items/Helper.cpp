//
//  Helper.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 06/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Helper.h"

void Helper::miseEnForme(char *str, int nombre, float x, float y, float r, float g, float b){
    char s[50];
    strcpy(s,str);
    std::string nb = std::to_string(nombre);
    char const* pchar = nb.c_str();
    strncat(s,pchar,10);
    GraphicPrimitives::drawText2D(s, x, y, r, g, b);
}
