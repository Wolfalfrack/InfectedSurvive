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

    spritePerso.setPosition(Vector2f(1230/2,570/2));
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

Texture Personnage::getTexturePerso()
{
    return texturePerso;
}

void Personnage::deplacementClavier()
{
    enum Dir{Up, Left, Down, Right};
    Vector2i anim(1, Down);

    if(Keyboard::isKeyPressed(Keyboard::Z))
    {
        anim.y = Up;
        spritePerso.move(0,-vitesse);
    }
    if(Keyboard::isKeyPressed(Keyboard::S))
    {
        anim.y = Down;
        spritePerso.move(0,vitesse);
    }
    if(Keyboard::isKeyPressed(Keyboard::Q))
    {
        anim.y = Left;
        spritePerso.move(-vitesse,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        anim.y = Right;
        spritePerso.move(vitesse,0);
    }

    if(spritePerso.getPosition().x <=0)
        spritePerso.setPosition(Vector2f(0, spritePerso.getPosition().y));
    if(spritePerso.getPosition().y <=0)
        spritePerso.setPosition(Vector2f(spritePerso.getPosition().x,0));
    if(spritePerso.getPosition().y >=570)
        spritePerso.setPosition(Vector2f(spritePerso.getPosition().x,570));
    if(spritePerso.getPosition().x >=1230)
        spritePerso.setPosition(Vector2f(1230, spritePerso.getPosition().y));


    anim.x++;
    if(anim.x * 64  >= texturePerso.getSize().x){
        anim.x = 0;
    }


    spritePerso.setTextureRect(IntRect(anim.x * 0, anim.y * 64,64,64));
}
