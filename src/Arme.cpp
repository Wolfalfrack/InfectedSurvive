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

void Arme::ajouterMunition(Munition& mun)
{
    munitions.push_back(mun);
}

void Arme::shoot(Munition mun,Vector2f persoCenter, Vector2f aimDirNorm, const RenderWindow& window, ListZombie& listZombie){
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
    for (size_t i = 0; i < munitions.size(); i++)
    {
        munitions[i].shape.move(munitions[i].currVelocity);

        if (munitions[i].shape.getPosition().x < 0 || munitions[i].shape.getPosition().x > window.getSize().x
            || munitions[i].shape.getPosition().y < 0 || munitions[i].shape.getPosition().y > window.getSize().y)
        {
            munitions.erase(munitions.begin() + i);
        }
        else
        {
            for (size_t k = 0; k < listZombie.getZombies().size(); k++)
            {
                if (munitions[i].shape.getGlobalBounds().intersects(listZombie.getZombies()[k]->getSpriteZombie().getGlobalBounds()))
                {
                    munitions.erase(munitions.begin() + i);
                    listZombie.deleteZombie(listZombie.getZombies()[k]);
                    break;
                }
            }
        }
    }
}

