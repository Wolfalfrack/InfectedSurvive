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

void ListZombie::ajouterZombie(Zombie* zombie)
{
    zombies.push_back(zombie);
    nbZombie++;
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
//    strs<<puissance<<" ";
    return strs.str();
}
