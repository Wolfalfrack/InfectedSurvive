#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Arme.h"
using namespace std;
using namespace sf;


class Personnage
{
    public:
        Personnage(int vie, int vitesse,Arme arme);
        Personnage(const Personnage& other);
        Personnage& operator=(const Personnage& other);
        virtual ~Personnage();

        string str()const;

        int getVie();
        void setVie(int vie);
        int getVitesse();
        Arme getArme();
        Sprite getSpritePerso();
        Texture getTexturePerso();

        Vector2f getCenterPosition();

        void deplacementClavier();
        void attaque();

    protected:

    private:
        int vie;
        int vitesse;
        Arme arme;
        Texture texturePerso;
        Sprite spritePerso;
};

#endif // PERSONNAGE_H
