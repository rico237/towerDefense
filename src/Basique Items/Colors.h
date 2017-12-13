//
//  Colors.h
//  TowerDefense
//
//  Created by Herrick Wolber on 08/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#pragma once
class Colors {
public:
    // Couleurs des vaisseaux par type
    static inline float getBasiqueRed(){return .3f;};
    static inline float getBasiqueGreen(){return 0.f;};
    static inline float getBasiqueBlue(){return 0.f;};
    
    static inline float getSlowingRed(){return 1.f;};
    static inline float getSlowingGreen(){return .5f;};
    static inline float getSlowingBlue(){return .3f;};
    
    static inline float getTankyRed(){return .1f;};
    static inline float getTankyGreen(){return 1.f;};
    static inline float getTankyBlue(){return .3f;};
    
    // Fleche de selection des vaisseaux
    static inline float getSelectionRed(){return .1f;};
    static inline float getSelectionGreen(){return 1.f;};
    static inline float getSelectionBlue(){return 0.f;};
    
    // Couleurs des asteroides
    static inline float getAsteroidRed(){return .3f;};
    static inline float getAsteroidGreen(){return 0.f;};
    static inline float getAsteroidBlue(){return 0.f;};
    
    static inline float getFastAsteroidRed(){return 1.f;};
    static inline float getFastAsteroidGreen(){return .5f;};
    static inline float getFastAsteroidBlue(){return .3f;};
    
    static inline float getTankyAsteroidRed(){return .1f;};
    static inline float getTankyAsteroidGreen(){return 1.f;};
    static inline float getTankyAsteroidBlue(){return .3f;};
};
