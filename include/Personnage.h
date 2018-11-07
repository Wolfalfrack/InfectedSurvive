#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class Personnage
{
    public:
        Personnage(int vie, int vitesse);
        Personnage(const Personnage& other);
        bool operator==(const Personnage& other);
        virtual ~Personnage();

        string str()const;

    protected:

    private:
        int vie;
        int vitesse;


        string sprite;
};

#endif // PERSONNAGE_H
