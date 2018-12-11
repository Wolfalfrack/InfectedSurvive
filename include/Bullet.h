#ifndef BULLET_H
#define BULLET_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>

using namespace std;
using namespace sf;


// This class creates the bullets shot by the weapon of the character in the game
class Bullet
{
    public:
        Bullet(float radius);
        virtual ~Bullet();

        CircleShape shape;
        Vector2f currVelocity;
        float maxSpeed;

    protected:

    private:
};

#endif // BULLET_H
