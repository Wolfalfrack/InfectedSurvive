#include "Weapon.h"


Weapon::Weapon(int power)
{
    this->power = power;

    //Initialization of the goat's sound
    if (!buffer.loadFromFile("Media/Goat.wav")){}
    sound.setBuffer(buffer);
}

Weapon::Weapon()
{
    this->power = 100;
}

Weapon::Weapon(const Weapon& other){
    this->power = other.power;
}

Weapon& Weapon::operator=(const Weapon& other){
    if(this == &other)return *this;
    this->power = other.power;
    return *this;
}

Weapon::~Weapon()
{
    //dtor
}

string Weapon::str()const{
    stringstream strs;
    strs<<power<<" ";
    return strs.str();
}

vector<Bullet> Weapon::getBullet()
{
    return bullets;
}

void Weapon::addBullet(Bullet& bul)
{
    bullets.push_back(bul);
}

void Weapon::deleteAllBullet()
{
    bullets.clear();
}

// this method manages the shooting action by pulling bullets from the character's position to the mouse cursor's position
void Weapon::shoot(Bullet bul,Vector2f persoCenter, Vector2f aimDirNorm, const RenderWindow& window, ListZombie& listZombie, int& killStreak){
    if(Mouse::isButtonPressed(Mouse::Left))
    {
        bul.shape.setPosition(persoCenter);
        bul.currVelocity = aimDirNorm * bul.maxSpeed;
        addBullet(bul);
    }
    for(int i=0; i<bullets.size(); i++)
    {
        bullets[i].shape.move(bullets[i].currVelocity);
    }
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].shape.move(bullets[i].currVelocity);

        if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window.getSize().x
            || bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
        {
            bullets.erase(bullets.begin() + i);
        }
        else
        {
            // management of the collision between a bullet and a zombie by deleting both of them and incrementing killingStreak
            for (size_t k = 0; k < listZombie.getZombies().size(); k++)
            {
                if (bullets[i].shape.getGlobalBounds().intersects(listZombie.getZombies()[k]->getSpriteZombie().getGlobalBounds()))
                {
                    // deleting all zombies of the list if a goat is killed
                    if(listZombie.getZombies()[k]->getNbSprite() == 9){
                        killStreak+=listZombie.getZombies().size();
                        listZombie.deleteAllZombie();

                        sound.play();
                    }
                    else{
                        bullets.erase(bullets.begin() + i);
                        listZombie.deleteZombie(listZombie.getZombies()[k]);
                        killStreak++;

                    }
                    break;
                }
            }
        }
    }
}

