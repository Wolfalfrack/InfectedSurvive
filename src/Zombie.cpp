#include "Zombie.h"

Zombie::Zombie(int vie, int vitesse, int puissance)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->puissance = puissance;
}

Zombie::Zombie(const Zombie& other){
    this->vie = other.vie;
    this->vitesse = other.vitesse;
    this->puissance = other.puissance;
}

Zombie& Zombie::operator=(const Zombie& other){
    if(this==&other)return *this;
    this->vie = other.vie;
    this->vitesse = other.vitesse;
    this->puissance = other.puissance;
    return *this;
}

Zombie::~Zombie()
{
    //dtor
}

string Zombie::str()const{
    stringstream strs;
    strs<<vie<<" "<<vitesse<<" "<<puissance;
    return strs.str();
}
