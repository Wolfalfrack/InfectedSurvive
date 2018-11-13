#include "Personnage.h"

using namespace std;

Personnage::Personnage(int vie, int vitesse,Arme arme)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->arme = arme;

    if(!texturePerso.loadFromFile("spritePerso.png")){
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
    enum Dir{Down, Left, Right, Up};
    Vector2i anim(1, Down);

    anim.x++;
    if(anim.x * 64  >= texturePerso.getSize().x){
        anim.x = 0;
    }
    spritePerso.setTextureRect(IntRect(anim.x * 64, anim.y * 64,64,64));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        anim.y = Up;
        spritePerso.move(0,-vitesse);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        anim.y = Down;
        spritePerso.move(0,vitesse);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        anim.y = Left;
        spritePerso.move(-vitesse,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        anim.y = Right;
       spritePerso.move(vitesse,0);
    }
}
