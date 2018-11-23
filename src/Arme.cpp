#include "Arme.h"

Arme::Arme(int puissance, string sprite)
{
    this->puissance = puissance;
    this->sprite = sprite;
}

Arme::Arme()
{
    this->puissance = 100;
    this->sprite = "sprite.png";
}

Arme::Arme(const Arme& other){
    this->puissance = other.puissance;
    this->sprite = other.sprite;
}

Arme& Arme::operator=(const Arme& other){
    if(this == &other)return *this;
    this->puissance = other.puissance;
    this->sprite = other.sprite;
    return *this;
}

Arme::~Arme()
{
    //dtor
}

string Arme::str()const{
    stringstream strs;
    strs<<puissance<<" ";
    return strs.str();
}

vector<Munition> Arme::getMunition()
{
    return munitions;
}

void Arme::ajouterMunition(Munition mun)
{
    munitions.push_back(mun);
}

void Arme::shoot(Munition mun,Vector2f persoCenter, Vector2f aimDirNorm){
    if(Mouse::isButtonPressed(Mouse::Left))
    {
        mun.shape.setPosition(persoCenter);
        mun.currVelocity = aimDirNorm * mun.maxSpeed;
        ajouterMunition(mun);
    }
    for(int i=0; i<munitions.size(); i++)
    {
        munitions[i].shape.move(munitions[i].currVelocity);
    }
}
