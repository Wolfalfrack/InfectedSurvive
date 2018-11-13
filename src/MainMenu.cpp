#include "MainMenu.h"
#include <SFML/Graphics.hpp>

MainMenu::MainMenu()
{
    //ctor
}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::draw()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "InfectedSurvive");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
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

        window.clear();
        window.draw(shape);
        window.display();
    }

}
