#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
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
        int getVitesse();
        Arme getArme();
        Sprite getSpritePerso();

        void deplacementClavier();

    protected:

    private:
        int vie;
        int vitesse;
        Arme arme;
        Texture texturePerso;
        Sprite spritePerso;
};

#endif // PERSONNAGE_H
