#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using namespace sf;

// this class manages the actions of the zombies during the game
class Zombie
{
    public:
        Zombie(int speed, int power, Vector2f characterPosition);
        Zombie(const Zombie& other);
        Zombie& operator=(const Zombie& other);
        virtual ~Zombie();

        Zombie* clone()const;

        bool randomMove(Sprite spritePerso);
        bool attack(Sprite spritePerso);
        int randomSprite();

        string str()const;

        int* getId();
        int getSpeed();
        int getPower();
        int getNbSprite();

        void setSpeed();
        void setPower();
        Texture getTextureZombie();
        Sprite getSpriteZombie();
        int spriteValue();

    protected:

    private:
        int* id;
        static int counter;
        int speed;
        int power;
        int nbSprite;
        Texture textureZombie;
        Sprite spriteZombie;
        Vector2f characterPosition;
};

#endif // ZOMBIE_H
