#include "MainMenu.h"

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

        Arme arme(10,50,"sprite.png");
        Personnage personnage(10,10,arme);
        personnage.deplacementClavier();

        window.clear();
        window.draw(shape);
        window.display();
    }

}
