#include "Application.h"

Application::Application(int difficulty)
{
    hpBar.setSize(Vector2f(1000,30));
    hpBar.setOutlineColor(Color::White);
    hpBar.setPosition(150,660);
    killStreak = 0;
    this->difficulty = difficulty;
}

Application::~Application()
{
    //dtor
}

void Application::setDifficulty(int difficulty)
{
    this->difficulty = difficulty;
}

void Application::run(){
    sf::RenderWindow window(VideoMode(1300, 700), "InfectedSurvive");

    window.setFramerateLimit(60);

    Bullet bul(5.f);

    Weapon weapon(10,"sprite.png");
    weapon.addBullet(bul);

    Character character(1000,5,weapon);

    Map map;

    Zombie zombie(1,10, character.getSpriteCharacter().getPosition());
    ListZombie listZombie(difficulty);

    int timer = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        character.keyboardAction();

        if(timer >100)
        {
            if(listZombie.getZombies().size()<listZombie.getNbZombieMax())
            {
                listZombie.addZombie(zombie.clone());
            }

            for(int i = 0; i < listZombie.getZombies().size(); i++)
            {
                listZombie.getZombies()[i]->getSpriteZombie().setPosition(Vector2f(rand()%1230,rand()%570));
            }

            for (int i = 0; i < listZombie.getZombies().size(); i++)
            {
                if(listZombie.getZombies()[i]->randomMove(character.getSpriteCharacter()))
                {
                    character.setHealth(character.getHealth() - listZombie.getZombies()[i]->getPower());
                    hpBar.setSize(Vector2f( hpBar.getSize().x - (10 * listZombie.getZombies()[i]->getPower()) ,30));
                    timer = 90;
                    listZombie.deleteZombie(listZombie.getZombies()[i]);
                }
            }
        }

        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - character.getCenterPosition();
        aimDirNorm = aimDir/(float)sqrt(pow(aimDir.x,2) + pow(aimDir.y,2));

        weapon.shoot(bul,character.getCenterPosition(), aimDirNorm, window, listZombie, killStreak);

        window.draw(map.getSpriteMap());

        window.draw(character.getSpriteCharacter());

        for(int i =0; i < listZombie.getZombies().size(); i++)
        {
            window.draw(listZombie.getZombies()[i]->getSpriteZombie());
        }

        for(int i = 0; i < weapon.getBullet().size(); i++)
        {
            window.draw(weapon.getBullet()[i].shape);
        }

        window.draw(hpBar);

        if(character.getHealth()<=0){
            window.clear();
            window.draw(map.getSpriteMap());
            window.close();
        }

        window.display();
        window.clear();


        timer++;
    }
}

