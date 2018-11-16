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
    sf::RenderWindow window(sf::VideoMode(1300, 650), "InfectedSurvive");
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Arme arme(10,50,"sprite.png");
    Personnage personnage(10,5,arme);
    Zombie zombie(10,3,10);
    Map map;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        personnage.deplacementClavier();

       zombie.deplacementAleatoire(personnage);

        window.draw(map.getSpriteMap());
        window.draw(personnage.getSpritePerso());
        window.draw(zombie.getSpriteZombie());



        window.display();
        window.clear();


    }

}
