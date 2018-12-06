#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
//#include "Zombie.h"
using namespace std;
using namespace sf;


class Personnage
{
    public:
        Personnage(int vie, int vitesse,Weapon weapon);
        Personnage(const Personnage& other);
        Personnage& operator=(const Personnage& other);
        virtual ~Personnage();

        string str()const;

        int getVie();
        void setVie(int vie);
        int getVitesse();
        Weapon getWeapon();
        Sprite getSpritePerso();
        Texture getTexturePerso();

        Vector2f getCenterPosition();

        void deplacementClavier();

    protected:

    private:
        int vie;
        int vitesse;
        Weapon weapon;
        Texture texturePerso;
        Sprite spritePerso;
};

#endif // PERSONNAGE_H
