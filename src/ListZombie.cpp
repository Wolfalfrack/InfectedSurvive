#include "ListZombie.h"

ListZombie::ListZombie(int nbZombieMax)
{
    this->nbZombieMax = nbZombieMax;
    this->nbZombie = 0;
}

ListZombie::~ListZombie()
{
    //dtor
}

void ListZombie::addZombie(Zombie* zombie)
{
    zombies.push_back(zombie);
    nbZombie++;
}

void ListZombie::deleteZombie(Zombie* zombie)
{
    delete zombies.at(indexOf(zombie));
    zombies.erase(zombies.begin() + indexOf(zombie));

}

void ListZombie::deleteAllZombie()
{
    for(int i = 0; i< zombies.size(); i++){
        delete zombies.at(i);
    }
    zombies.clear();

}

int ListZombie::indexOf(Zombie* zombie)
{
    for(int i = 0; i<zombies.size(); i++)
    {
        if(zombies[i]->getId() == zombie->getId())
        {
            return i;
        }
    }
}

vector<Zombie*> ListZombie::getZombies()
{
    return zombies;
}

int ListZombie::getNbZombie()
{
    return nbZombie;
}

int ListZombie::getNbZombieMax()
{
    return nbZombieMax;
}

string ListZombie::str()
{
    stringstream strs;
    for (int i = 0; i < zombies.size(); i++)
    {
        strs<<zombies[i]->str()<<" ";
    }
    return strs.str();
}
