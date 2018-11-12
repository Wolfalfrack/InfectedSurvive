#include "Arme.h"

Arme::Arme(int puissance, int munition, string sprite)
{
    this->puissance = puissance;
    this->munition = munition;
    this->sprite = sprite;
}

Arme::Arme()
{
    this->puissance = 100;
    this->munition = 50;
    this->sprite = "sprite.png";
}

Arme::Arme(const Arme& other){
    this->puissance = other.puissance;
    this->munition = other.munition;
    this->sprite = other.sprite;
}

Arme& Arme::operator=(const Arme& other){µ
    if(this == &other)return *this;
    this->puissance = other.puissance;
    this->munition = other.munition;
    this->sprite = other.sprite;
    return *this;
}

Arme::~Arme()
{
    //dtor
}

string Arme::str()const{
    stringstream strs;
    strs<<puissance<<" "<<munition;
    return strs.str();
}
