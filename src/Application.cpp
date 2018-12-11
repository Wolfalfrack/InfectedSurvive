#include "Application.h"

Application::Application(int difficulty)
{
    // Initialization of the health bar, the kill counter, the difficulty, the end text and the score text
    hpBar.setSize(Vector2f(1000,30));
    hpBar.setOutlineColor(Color::White);
    hpBar.setPosition(280,660);
    killStreak = 0;
    this->difficulty = difficulty;

    if(!font.loadFromFile("Media/arial.ttf")){}
    score.setFont(font);
    score.setString(to_string(killStreak));
    score.setPosition(50,660);
    score.setColor(Color::White);

    if(!font.loadFromFile("Media/arial.ttf")){}
    text.setFont(font);
    text.setPosition(400,300);
    text.setColor(Color::White);
}

Application::~Application()
{
    //dtor
}

void Application::setDifficulty(int difficulty)
{
    this->difficulty = difficulty;
}

// this method manages the progress of the game
void Application::run(){
    RenderWindow window(VideoMode(1300, 700), "InfectedSurvive");
    window.setFramerateLimit(60);

    Bullet bul(5.f);

    Weapon weapon(10);
    weapon.addBullet(bul);

    Character character(1000,5,weapon);

    Map map;

    Zombie zombie(1,10, character.getSpriteCharacter().getPosition());
    ListZombie listZombie(difficulty);

    int timer = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        character.keyboardAction();

        // timer used for recovery between each damage taken
        if(timer >100)
        {
            // management of zombies (add in list and call of method randomMove for each zombie of the list) and damage taken by the character
            if(listZombie.getZombies().size()<listZombie.getNbZombieMax())
            {
                listZombie.addZombie(zombie.clone());
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

        // management of the mouse cursor position for the shoot method
        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - character.getCenterPosition();
        aimDirNorm = aimDir/(float)sqrt(pow(aimDir.x,2) + pow(aimDir.y,2));

        weapon.shoot(bul,character.getCenterPosition(), aimDirNorm, window, listZombie, killStreak);

        // drawing the map, the character, the zombies, the bullets, the score and the health bar
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
        score.setString(to_string(killStreak));
        window.draw(score);
        window.draw(hpBar);

        // screen of end game with the final score
        if(hpBar.getSize().x<=0){
            window.clear();

            Sprite spriteBackground;
            Texture textureBackground;
            if(!textureBackground.loadFromFile("Media/Background.png"))
            {
                cout<<"Error loading background";
            }
            textureBackground.setSmooth(true);
            spriteBackground.setTexture(textureBackground);
            window.draw(spriteBackground);

            weapon.deleteAllBullet();
            listZombie.deleteAllZombie();

            text.setString("                       You lose\n                   Your score : "+to_string(killStreak)+"\nPress spacebar to return to the menu.");

            window.draw(text);

            if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                window.close();
            }
        }

        window.display();
        window.clear();


        timer++;
    }
}
