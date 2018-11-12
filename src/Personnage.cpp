#include "Personnage.h"

using namespace std;

Personnage::Personnage(int vie, int vitesse,Arme arme)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->arme = arme;
    this->sprite = "personnage.png";
}

Personnage::Personnage(const Personnage& other){
    this->vie = other.vie;
    this->vitesse = other.vitesse;
    this->arme = other.arme;
    this->sprite = "personnage.png";
}

Personnage::~Personnage()
{
    //dtor
}

Personnage& Personnage::operator=(const Personnage& other){
    if(this==&other)return *this;
    this->vie = other.vie;
    this->vitesse = other.vitesse;
    this->arme = other.arme;
    this->sprite = "personnage.png";
    return *this;
}

string Personnage::str()const{
    stringstream strs;
    strs<<vie<<" "<<vitesse<<" "<<arme.str();
    return strs.str();
}
