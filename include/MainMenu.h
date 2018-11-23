#ifndef MAINMENU_H
#define MAINMENU_H
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include "Personnage.h"
#include "Arme.h"
#include "Zombie.h"
#include "Map.h"
#include "Munition.h"
#include "ListZombie.h"
#include <thread>
#include <iostream>


class MainMenu
{
    public:
        MainMenu();
        virtual ~MainMenu();
        void draw();
        void func();

    protected:

    private:
        Vector2f mousePosWindow;
        Vector2f aimDir;
        Vector2f aimDirNorm;
};

#endif // MAINMENU_H
