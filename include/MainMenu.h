#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Arme.h"
#include "Zombie.h"
#include "Map.h"

class MainMenu
{
    public:
        MainMenu();
        virtual ~MainMenu();
        void draw();

    protected:

    private:
};

#endif // MAINMENU_H
