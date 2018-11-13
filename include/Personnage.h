#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <sstream>
#include <iostream>
#include "Arme.h"
using namespace std;


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
        string getSprite();

        void deplacementClavier();

    protected:

    private:
        int vie;
        int vitesse;
        Arme arme;


        string sprite;
};

#endif // PERSONNAGE_H
