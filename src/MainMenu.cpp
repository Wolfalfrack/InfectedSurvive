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

    Munition mun();

    Arme arme(10,"sprite.png");
    arme.ajouterMunition(mun);
    Personnage personnage(1000,15,arme);
    Zombie zombie(10,5,10);
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
        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - personnage.getCenterPosition();
        aimDirNorm = aimDir/(float)sqrt(pow(aimDir.x,2) + pow(aimDir.y,2));
        cout<< aimDirNorm.x << " "<< aimDirNorm.y << endl;

        window.draw(map.getSpriteMap());
        for(size_t i = 0; i < arme.getMunition().size(); i++)
        {
            window.draw(arme.getMunition());
        }

        arme.shoot(mun,personnage.getCenterPosition(),aimDirNorm);
        window.draw(personnage.getSpritePerso());
        window.draw(zombie.getSpriteZombie());

//        if(personnage.getVie()<=0){
//            window.clear();
//            window.draw(map.getSpriteMap());
//        }

        window.display();
        window.clear();


    }

}
