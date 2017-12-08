//
//  GameControler.hpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 06/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include <stdio.h>
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"

#include "Case.h"

class GameControler {
    Engine *e;
    
public:
    GameControler(Engine *e_);
    
    void startAll();
};
