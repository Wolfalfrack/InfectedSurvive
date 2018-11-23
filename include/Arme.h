#ifndef ARME_H
#define ARME_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <SFML/System.hpp>
#include "Munition.h";

using namespace std;
using namespace sf;

class Arme
{
    public:
        Arme(int puissance, string sprite);
        Arme(const Arme& other);
        Arme& operator=(const Arme& other);
        virtual ~Arme();
        Arme();

        vector<Munition> getMunition();


        string str()const;

        void ajouterMunition(Munition& mun);
        void shoot(Munition mun,Vector2f persoCenter, Vector2f aimDirNorm, const RenderWindow& window);

    protected:

    private:
        int puissance;
        string sprite;
        vector<Munition> munitions;
};

#endif // ARME_H
