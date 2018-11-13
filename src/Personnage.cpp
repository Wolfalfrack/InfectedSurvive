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

int Personnage::getVie()
{
    return vie;
}

int Personnage::getVitesse()
{
    return vitesse;
}

Arme Personnage::getArme()
{
    return arme;
}

string Personnage::getSprite()
{
    return sprite;
}

void deplacementClavier()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        personnage.getSprite().move(0,-personnage.getVitesse());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        personnage.getSprite().move(0,personnage.getVitesse());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        personnage.getSprite().move(-personnage.getVitesse(),0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        personnage.getSprite().move(personnage.getVitesse(),0);
    }
}
