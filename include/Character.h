#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
using namespace std;
using namespace sf;


// This class manages the character of the game played by the user
class Character
{
    public:
        Character(int health, int speed,Weapon weapon);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        string str()const;

        int getHealth();
        void setHealth(int health);
        int getSpeed();
        Weapon getWeapon();
        Sprite getSpriteCharacter();
        Texture getTextureCharacter();

        Vector2f getCenterPosition();

        void keyboardAction();

    protected:

    private:
        int health;
        int speed;
        Weapon weapon;
        Texture textureCharacter;
        Sprite spriteCharacter;
};

#endif // PERSONNAGE_H
