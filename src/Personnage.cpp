#include "Personnage.h"

using namespace std;

Personnage::Personnage(int vie, int vitesse)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->sprite = "personnage.png";
}

Personnage::Personnage(const Personnage& other){
    this->vie = other.vie;
    this->vitesse = other.vitesse;
    this->sprite = "personnage.png";
}

Personnage::~Personnage()
{
    //dtor
}

bool Personnage::operator==(const Personnage& other){
    if(this->vie == other.vie && this->vitesse == other.vitesse){
        return true;
    }
    return false;
}

string Personnage::str()const{
    stringstream strs;
    strs<<vie<<" "<<vitesse<<" "<<endl;
    return strs.str();
}
