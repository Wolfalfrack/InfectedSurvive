#ifndef LISTZOMBIE_H
#define LISTZOMBIE_H
#include "Zombie.h"


class ListZombie
{
    public:
        ListZombie(int nbZombieMax);
        virtual ~ListZombie();

        void ajouterZombie(Zombie zombie);
        vector<Zombie> getZombies();
        int getNbZombie();
        int getNbZombieMax();
        string str();

    protected:

    private:
        int nbZombieMax;
        int nbZombie;
        vector<Zombie> zombies;
};

#endif // LISTZOMBIE_H
