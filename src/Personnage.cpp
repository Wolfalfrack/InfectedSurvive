#include "Personnage.h"

using namespace std;

Personnage::Personnage(int vie, int vitesse,Arme arme)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->arme = arme;

    if(!texturePerso.loadFromFile("spritePerso.png",sf::IntRect(64,0,64,64))){
            cout<<"Error loading sprite";
    }
    texturePerso.setSmooth(true);
    spritePerso.setTexture(texturePerso);
}

Personnage::Personnage(const Personnage& other){
    this->vie = other.vie;
    this->vitesse = other.vitesse;
    this->arme = other.arme;
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

Sprite Personnage::getSpritePerso()
{
    return spritePerso;
}

void Personnage::deplacementClavier()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        spritePerso.move(0,-vitesse);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        spritePerso.move(0,vitesse);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        spritePerso.move(-vitesse,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
       spritePerso.move(vitesse,0);
    }
}
