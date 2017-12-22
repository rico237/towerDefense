//
//  Asteroide.cpp
//  Projet C++ M1-IFI 2017
//
//  Created by Herrick Wolber on 05/12/2017.
//  Copyright © 2017 Herrick Wolber. All rights reserved.
//

#include "Asteroide.h"

Asteroide::Asteroide( float x, float y, TypeAsteroide type_):GraphicShape(x, y), type(type_){
    switch (type_) {
        case BasiqueAsteroide:
            setRGB(Colors::getAsteroidRed(), Colors::getAsteroidGreen(), Colors::getAsteroidBlue());
            frequence = 1; vitesse = .003f; vie = 100; size = 1;
            break;
        case FastAsteroid:
            setRGB(Colors::getFastAsteroidRed(), Colors::getFastAsteroidGreen(), Colors::getFastAsteroidBlue());
            frequence = 2; vitesse = .01f; vie = 200; size = 1.5;
            break;
        case TankAsteroid:
            setRGB(Colors::getTankyAsteroidRed(), Colors::getTankyAsteroidGreen(), Colors::getTankyAsteroidBlue());
            frequence = 2; vitesse = .004f; vie = 600; size = 2;
            break;
    }
}

void Asteroide::draw(){
    // TODO : essayer de dessiner un losange
    GraphicPrimitives::drawFillRect2D(getX(), getY(), size * .04f, size * .06f, getR(), getG(), getB());
}

void Asteroide::tick(){
//    long cadense = 1000000;
//    struct timeval temp1, temp2; // Cheque si aucune répercution sur le temps
//    gettimeofday(&temp2, NULL);
//    time2 = temp2.tv_sec * cadense + temp2.tv_usec;
//
//    if((time2 - time1) > (frequence * cadense)){
//        gettimeofday(&temp1, NULL);
//        time1 = temp1.tv_sec * cadense + temp1.tv_usec;
//    }
    
    setPosX(vitesse);
//    std::cout << "Asteroide life " << getLife() <<std::endl;
    if (isDead()){
        Helper::print("Is dead form asteroide");
        this->~Asteroide();
    }
}

bool Asteroide::hittenWith(int power, TypeVaisseau typeV){
    // Le ralentisseur diminue la vitesse
    if (typeV == Ralentisseur) {
        vitesse *= 0.7f;
    }
    else {
        switch (type) {
            case BasiqueAsteroide:
                size *= 0.7f;
                setY(getY()+.01f);
                break;
            case FastAsteroid:
                size *= 0.8f;
                setY(getY()+.006f);
                break;
            case TankAsteroid:
                size *= 0.9f;
                setY(getY()+.003f);
                break;
        }
        looseLife(power);
    }
    
    return isDead();
}

void Asteroide::gainAssocie(Joueur *joueur){
    int money, score;
    switch (type) {
        case BasiqueAsteroide:
            money = 50;
            score = 100;
            break;
        case FastAsteroid:
            money = 75;
            score = 200;
            break;
        case TankAsteroid:
            money = 100;
            score = 300;
            break;
    }
    
    joueur->setMoney(money);
    joueur->setScore(score);
}


