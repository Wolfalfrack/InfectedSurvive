#ifndef APPLICATION_H
#define APPLICATION_H
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include <thread>
#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Zombie.h"
#include "Map.h"
#include "Bullet.h"
#include "ListZombie.h"


// This class manages the entire game
class Application
{
    public:
        Application(int difficulty);
        virtual ~Application();
        void run();
        void draw();
        void func();
        void setDifficulty(int difficulty);
    protected:

    private:
        int killStreak;
        int difficulty;
        Vector2f mousePosWindow;
        Vector2f aimDir;
        Vector2f aimDirNorm;
        RectangleShape hpBar;
        Text text;
        Text score;
        Font font;
};

#endif // APPLICATION_H
