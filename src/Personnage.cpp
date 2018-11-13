#include "Personnage.h"

using namespace std;

Personnage::Personnage(int vie, int vitesse,Arme arme)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->arme = arme;
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

void Personnage::deplacementClavier()
{
    sf::Texture texturePerso;
    if(!texturePerso.loadFromFile("spritePerso.png")){
            cout<<"Error loading sprite";
    }
//    sf::Sprite spritePerso;
//    spr.setImage(ImageManager.GetImage()));
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
//    {
//        spr.move(0,-getVitesse());
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//    {
//        spr.move(0,getVitesse()));
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//    {
//        spr.move(-getVitesse(),0);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//       spr.move(getVitesse(),0);
//    }
}
