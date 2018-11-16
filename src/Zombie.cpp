#include "Zombie.h"

Zombie::Zombie(int vie, int vitesse, int puissance)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->puissance = puissance;

    if(!textureZombie.loadFromFile("zombie.png")){
        cout<<"Error loading sprite";
    }
    textureZombie.setSmooth(true);
    spriteZombie.setTexture(textureZombie);
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

int Zombie::getVie()
{
    return vie;
}

int Zombie::getVitesse()
{
    return vitesse;
}

int Zombie::getPuissance()
{
    return puissance;
}

Texture Zombie::getTextureZombie()
{
    return textureZombie;
}

Sprite Zombie::getSpriteZombie()
{
    return spriteZombie;
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

void Zombie::deplacementAleatoire(Personnage personnage)
{

    enum Dir{Down, Left, Right, Up};
    Vector2i anim(1, Down);

    if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        anim.y = Up;
        spriteZombie.move(0,-vitesse);
    }
    if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        anim.y = Down;
        spriteZombie.move(0,vitesse);
    }
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        anim.y = Left;
        spriteZombie.move(-vitesse,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        anim.y = Right;
        spriteZombie.move(vitesse,0);
    }

    if(spriteZombie.getPosition().x <=0)
        spriteZombie.setPosition(Vector2f(0, spriteZombie.getPosition().y));
    if(spriteZombie.getPosition().y <=0)
        spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,0));
    if(spriteZombie.getPosition().y >=570)
        spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,570));
    if(spriteZombie.getPosition().x >=1230)
        spriteZombie.setPosition(Vector2f(1230, spriteZombie.getPosition().y));


    anim.x ++;
    if(anim.x * 16  >= textureZombie.getSize().x){
        anim.x = 0;
    }

    // X = 16 / 64 / 112 / 160 = sprite 1 / 2 / 3 / 4

    spriteZombie.setTextureRect(IntRect(anim.x * 16, anim.y * 32,34,32));

}
