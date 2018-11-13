#include "DeplacementPersonnage.h"

DeplacementPersonnage::DeplacementPersonnage()
{
    //ctor
}

DeplacementPersonnage::~DeplacementPersonnage()
{
    //dtor
}

void deplacementClavier()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        shape.move(0,-1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shape.move(0,1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        shape.move(-1,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.move(1,0);
    }
}
