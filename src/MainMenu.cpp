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
    // TAILLE POUR NICO
//    sf::RenderWindow window(sf::VideoMode(1300, 650), "InfectedSurvive");
    // TAILE POUR LUDO
    sf::RenderWindow window(sf::VideoMode(1900, 900), "InfectedSurvive");

    window.setFramerateLimit(60);

    Munition mun(5.f);

    Arme arme(10,"sprite.png");
    arme.ajouterMunition(mun);

    Personnage personnage(1000,15,arme);

    Zombie zombie(10, 3, 10);

    ListZombie zombies(0);

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

        if(zombies.getNbZombie()<zombies.getNbZombieMax())
        {
            zombies.ajouterZombie(zombie);
        }

        for (int i = 0; i < zombies.getZombies().size(); i++)
		{
			zombies.getZombies()[i].deplacementAleatoire(personnage);
		}
//        zombie.deplacementAleatoire(personnage);

        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - personnage.getCenterPosition();
        aimDirNorm = aimDir/(float)sqrt(pow(aimDir.x,2) + pow(aimDir.y,2));



        arme.shoot(mun,personnage.getCenterPosition(),aimDirNorm, window);

        window.draw(map.getSpriteMap());

        window.draw(personnage.getSpritePerso());

        for (int i = 0; i < zombies.getZombies().size(); i++)
		{
			window.draw(zombies.getZombies()[i].getSpriteZombie());
		}

        for(int i = 0; i < arme.getMunition().size(); i++)
        {
            window.draw(arme.getMunition()[i].shape);
        }


//        if(personnage.getVie()<=0){
//            window.clear();
//            window.draw(map.getSpriteMap());
//        }

        window.display();
        window.clear();



    }

}
