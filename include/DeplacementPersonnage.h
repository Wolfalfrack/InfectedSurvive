#ifndef DEPLACEMENTPERSONNAGE_H
#define DEPLACEMENTPERSONNAGE_H
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "MainMenu.h"

using namespace std;

class DeplacementPersonnage
{
    public:
        DeplacementPersonnage(Personnage personnage);
        virtual ~DeplacementPersonnage();
        void deplacementClavier();
    protected:

    private:
};

#endif // DEPLACEMENTPERSONNAGE_H
