#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Personnage.h"

using namespace std;
using namespace sf;

class Zombie
{
    public:
        Zombie(int vie, int vitesse, int puissance);
        Zombie(const Zombie& other);
        Zombie& operator=(const Zombie& other);
        virtual ~Zombie();

        void deplacementAleatoire();

        string str()const;

        int getVie();
        int getVitesse();
        int getPuissance();
        Texture getTextureZombie();
        Sprite getSpriteZombie();

    protected:

    private:
        int vie;
        int vitesse;
        int puissance;
        Texture textureZombie;
        Sprite spriteZombie;
};

#endif // ZOMBIE_H
