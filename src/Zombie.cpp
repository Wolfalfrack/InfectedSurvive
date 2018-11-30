#include "Zombie.h"

Zombie::Zombie(int vie, int vitesse, int puissance)
{
    this->vie = vie;
    this->vitesse = vitesse;
    this->puissance = puissance;

    if(!textureZombie.loadFromFile("zombie.png")){
        cout<<"Error loading sprite";
    }
    srand(time(NULL));

    textureZombie.setSmooth(true);
    spriteZombie.setTexture(textureZombie);

    // SPAWN ZOMBIE POUR NICO
    spriteZombie.setPosition(Vector2f(rand()%1230,rand()%570));
    // SPAWN ZOMBIE POUR LUDO
//    spriteZombie.setPosition(Vector2f(rand()%1830,rand()%830));

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

void Zombie::deplacementAleatoire(Personnage& personnage)
{

    enum Dir{Down, Left, Right, Up};
    Vector2i anim(1, Down);


    if(!attaque(personnage)){
        if(personnage.getSpritePerso().getPosition().x+32 < spriteZombie.getPosition().x+16)
        {
            anim.y = Left;
            spriteZombie.move(-vitesse,0);
        }
        if(personnage.getSpritePerso().getPosition().x+32 > spriteZombie.getPosition().x+16)
        {
            anim.y = Right;
            spriteZombie.move(vitesse,0);
        }
        if(personnage.getSpritePerso().getPosition().y+64 < spriteZombie.getPosition().y+16)
        {
            anim.y = Up;
            spriteZombie.move(0,-vitesse);
        }
        if(personnage.getSpritePerso().getPosition().y> spriteZombie.getPosition().y+16)
        {
            anim.y = Down;
            spriteZombie.move(0,vitesse);
        }
    }


    // LIMITE POUR NICO
    if(spriteZombie.getPosition().x <=0)
        spriteZombie.setPosition(Vector2f(0, spriteZombie.getPosition().y));
    else if(spriteZombie.getPosition().y <=0)
        spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,0));
    else if(spriteZombie.getPosition().y >=570)
        spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,570));
    else if(spriteZombie.getPosition().x >=1230)
        spriteZombie.setPosition(Vector2f(1230, spriteZombie.getPosition().y));

    // LIMITE POUR LUDO
//    if(spriteZombie.getPosition().x <=0)
//        spriteZombie.setPosition(Vector2f(0, spriteZombie.getPosition().y));
//    else if(spriteZombie.getPosition().y <=0)
//        spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,0));
//    else if(spriteZombie.getPosition().y >=830)
//        spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,830));
//    else if(spriteZombie.getPosition().x >=1830)
//        spriteZombie.setPosition(Vector2f(1830, spriteZombie.getPosition().y));

    anim.x ++;
    if(anim.x * 16  >= textureZombie.getSize().x){
        anim.x = 64;
    }

    // X = 16 / 64 / 112 / 160 = sprite 1 / 2 / 3 / 4

    spriteZombie.setTextureRect(IntRect(anim.x * 16, anim.y * 32,34,32));
}

bool Zombie::attaque(Personnage& personnage)
{
    if((abs((personnage.getSpritePerso().getPosition().x + 32) - (spriteZombie.getPosition().x + 16)) < 32)&&(abs((personnage.getSpritePerso().getPosition().y + 32) - (spriteZombie.getPosition().y + 16)) < 32))
    {
        personnage.setVie(personnage.getVie()-puissance);
        cout<<personnage.getVie();
        return true;
    }
    return false;
}
