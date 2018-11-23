#ifndef MUNITION_H
#define MUNITION_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>

using namespace std;
using namespace sf;

class Munition
{
    public:
        Munition(float radius);
        virtual ~Munition();

        CircleShape shape;
        Vector2f currVelocity;
        float maxSpeed;
    protected:

    private:


};

#endif // MUNITION_H
