#include "Zombie.h"

int Zombie::counter = 1000;

Zombie::Zombie(int speed, int power, Vector2f characterPosition)
{
    this->id = new int(counter++);
    this->speed = speed;
    this->power = power;

    // management of the sprite with a random system
    bool loadSprite = false;
    while(!loadSprite){
        this->nbSprite = (rand()%9 + 1);
        if(nbSprite >0 && nbSprite <=4){
            if(!textureZombie.loadFromFile("Media/zombie1.png")){
                cout<<"Error loading sprite";
            }
            loadSprite = true;
        }
        else if(nbSprite >4 && nbSprite <=8){
            if(!textureZombie.loadFromFile("Media/zombie2.png")){
                cout<<"Error loading sprite";
            }
            loadSprite = true;
        }

        else if( nbSprite == 9){
            this->nbSprite = (rand()%50 + 9);
            if( nbSprite == 9){
                if(!textureZombie.loadFromFile("Media/goat.png")){
                    cout<<"Error loading sprite";
                }
                loadSprite = true;
            }
        }
    }

    textureZombie.setSmooth(true);
    spriteZombie.setTexture(textureZombie);

    // random spawn of zombies from one of the 4 wall of the game
    spriteZombie.setPosition(Vector2f(rand()%1230,rand()%570));
    int value = rand()%4 + 1;
    if(value == 1){
        spriteZombie.setPosition(Vector2f(10,rand()%570));
    }
    else if(value == 2){
         spriteZombie.setPosition(Vector2f(1220,rand()%570));
    }
    else if(value == 3){
         spriteZombie.setPosition(Vector2f(rand()%1230,10));
    }
    else if (value == 4){
         spriteZombie.setPosition(Vector2f(rand()%1230,560));
    }
}

Zombie::Zombie(const Zombie& other){
    this->speed = other.speed;
    this->power = other.power;
}

Zombie& Zombie::operator=(const Zombie& other){
    if(this==&other)return *this;
    this->speed = other.speed;
    this->power = other.power;
    return *this;
}

Zombie* Zombie::clone()const
{
    return new Zombie(this->speed, this->power, this->characterPosition);
}

int* Zombie::getId()
{
    return id;
}

int Zombie::getSpeed()
{
    return speed;
}

int Zombie::getPower()
{
    return power;
}

Texture Zombie::getTextureZombie()
{
    return textureZombie;
}

Sprite Zombie::getSpriteZombie()
{
    return spriteZombie;
}

int Zombie::getNbSprite()
{
    return nbSprite;
}

void Zombie::setSpeed()
{
    this->speed;
}

void Zombie::setPower()
{
    this->power++;
}

Zombie::~Zombie()
{
    delete this->id;
}

string Zombie::str()const{
    stringstream strs;
    strs << *id <<" "<<speed<<" "<<power;
    return strs.str();
}

// this method manages the movement of the zombie according to the position of the character
bool Zombie::randomMove(Sprite spritePerso)
{

    enum Dir{Down, Left, Right, Up};
    Vector2i anim(1, Down);

    // this conditions manage the movement of zombies with their size of 32px / 32px
    if(nbSprite != 9){
        if(!attack(spritePerso)){
            if(spritePerso.getPosition().x+28 < spriteZombie.getPosition().x+16)
            {
                anim.y = Left;
                spriteZombie.move(-speed,0);
            }
            if(spritePerso.getPosition().x+28 > spriteZombie.getPosition().x+16)
            {
                anim.y = Right;
                spriteZombie.move(speed,0);
            }
            if(spritePerso.getPosition().y+32 < spriteZombie.getPosition().y+16)
            {
                anim.y = Up;
                spriteZombie.move(0,-speed);
            }
            if(spritePerso.getPosition().y+32> spriteZombie.getPosition().y+16)
            {
                anim.y = Down;
                spriteZombie.move(0,speed);
            }

            // management of the map limits
            if(spriteZombie.getPosition().x <=0)
                spriteZombie.setPosition(Vector2f(0, spriteZombie.getPosition().y));
            else if(spriteZombie.getPosition().y <=0)
                spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,0));
            else if(spriteZombie.getPosition().y >=570)
                spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,570));
            else if(spriteZombie.getPosition().x >=1230)
                spriteZombie.setPosition(Vector2f(1230, spriteZombie.getPosition().y));

            anim.x ++;
            if(anim.x * 16  >= textureZombie.getSize().x){
                anim.x = 64;
            }
            spriteZombie.setTextureRect(IntRect(anim.x * spriteValue(), anim.y * 32,34,32));

            return false;
        }
    }
    // this conditions manage the movement of goats with their size of 48px / 48px
    if(nbSprite == 9)
    {
        if(!attack(spritePerso)){
            if(spritePerso.getPosition().x+28 < spriteZombie.getPosition().x+32)
            {
                anim.y = Left;
                spriteZombie.move(-speed,0);
            }
            if(spritePerso.getPosition().x+28 > spriteZombie.getPosition().x+32)
            {
                anim.y = Right;
                spriteZombie.move(speed,0);
            }
            if(spritePerso.getPosition().y+32 < spriteZombie.getPosition().y+32)
            {
                anim.y = Up;
                spriteZombie.move(0,-speed);
            }
            if(spritePerso.getPosition().y+32> spriteZombie.getPosition().y+32)
            {
                anim.y = Down;
                spriteZombie.move(0,speed);
            }

            // management of the map limits
            if(spriteZombie.getPosition().x <=0)
                spriteZombie.setPosition(Vector2f(0, spriteZombie.getPosition().y));
            else if(spriteZombie.getPosition().y <=0)
                spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,0));
            else if(spriteZombie.getPosition().y >=570)
                spriteZombie.setPosition(Vector2f(spriteZombie.getPosition().x,570));
            else if(spriteZombie.getPosition().x >=1230)
                spriteZombie.setPosition(Vector2f(1230, spriteZombie.getPosition().y));

            anim.x ++;
            if(anim.x * 48  >= textureZombie.getSize().x){
                anim.x = 0;
            }
            spriteZombie.setTextureRect(IntRect(anim.x * spriteValue(), anim.y * 48,48,48));

            return false;
        }
    }
    return true;
}

// this method returns true if there is a collision between the zombie and the character
bool Zombie::attack(Sprite spriteCharacter)
{
    if((abs((spriteCharacter.getPosition().x + 32) - (spriteZombie.getPosition().x + 16)) < 32)&&(abs((spriteCharacter.getPosition().y + 32) - (spriteZombie.getPosition().y + 16)) < 32)){
        return true;
    }
    return false;
}

// this method gives speed ad power values according to the zombie and return a number according to their position in the sprite sheet
int Zombie::spriteValue()
{
    if(nbSprite == 1 || nbSprite == 5){
        return 16;
    }
    else if (nbSprite == 2 || nbSprite == 6){
        speed = 2;
        power = 15;
        return 64;
    }
    else if (nbSprite == 3 || nbSprite == 7){
        power = 20;
        return 112;
    }
    else if (nbSprite == 4 || nbSprite == 8){
        speed = 3;
        return 160;
    }
    else if (nbSprite == 9){
        speed = 5;
        power = 0;
        return 0;
    }
}
