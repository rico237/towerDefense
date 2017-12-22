#pragma once
#include "Engine.h"
#include "Vaisseaux_VS_Asteroides.h"
#include "Helper.h"
#include "SaveEngine.h"

//typedef std::list<DrawableObject*> DrawableList;

class MyControlEngine:public ControlEngine {
    Vaisseaux_VS_Asteroides &game;
    int sommeAchat;
    
public:
    MyControlEngine(Vaisseaux_VS_Asteroides &v_):game(v_), sommeAchat(100){};
   
    virtual void MouseCallback(int button, int state, int x, int y);
    virtual void KeyboardReleaseCallback(unsigned char key,int x, int y);
};
