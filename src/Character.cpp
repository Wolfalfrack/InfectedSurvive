#include "Character.h"

using namespace std;

Character::Character(int health, int speed,Weapon weapon)
{
    this->health = health;
    this->speed = speed;
    this->weapon = weapon;

    if(!textureCharacter.loadFromFile("spriteCharacter.png")){
            cout<<"Error loading sprite";
    }
    textureCharacter.setSmooth(true);
    spriteCharacter.setTexture(textureCharacter);

    spriteCharacter.setPosition(Vector2f(1230/2,570/2));
}

Character::Character(const Character& other){
    this->health = other.health;
    this->speed = other.speed;
    this->weapon = other.weapon;
}

Character::~Character()
{
    //dtor
}

Character& Character::operator=(const Character& other){
    if(this==&other)return *this;
    this->health = other.health;
    this->speed = other.speed;
    this->weapon = other.weapon;
    return *this;
}

string Character::str()const{
    stringstream strs;
    strs<<health<<" "<<speed<<" "<<weapon.str();
    return strs.str();
}

int Character::getHealth()
{
    return health;
}

void Character::setHealth(int health)
{
    this->health = health;
}

int Character::getSpeed()
{
    return speed;
}

Weapon Character::getWeapon()
{
    return weapon;
}

Sprite Character::getSpriteCharacter()
{
    return spriteCharacter;
}

Texture Character::getTextureCharacter()
{
    return textureCharacter;
}

Vector2f Character::getCenterPosition(){
    return Vector2f(spriteCharacter.getPosition().x +28, spriteCharacter.getPosition().y+32);
}

void Character::keyboardAction()
{
    enum Dir{Up, Left, Down, Right};
    Vector2i anim(1, Down);

    if(Keyboard::isKeyPressed(Keyboard::Z))
    {
        anim.y = Up;
        spriteCharacter.move(0,-speed);
    }
    if(Keyboard::isKeyPressed(Keyboard::S))
    {
        anim.y = Down;
        spriteCharacter.move(0,speed);
    }
    if(Keyboard::isKeyPressed(Keyboard::Q))
    {
        anim.y = Left;
        spriteCharacter.move(-speed,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        anim.y = Right;
        spriteCharacter.move(speed,0);
    }

    if(spriteCharacter.getPosition().x <=0)
        spriteCharacter.setPosition(Vector2f(0, spriteCharacter.getPosition().y));
    if(spriteCharacter.getPosition().y <=0)
        spriteCharacter.setPosition(Vector2f(spriteCharacter.getPosition().x,0));
    if(spriteCharacter.getPosition().y >=580)
        spriteCharacter.setPosition(Vector2f(spriteCharacter.getPosition().x,580));
    if(spriteCharacter.getPosition().x >=1230)
        spriteCharacter.setPosition(Vector2f(1230, spriteCharacter.getPosition().y));

    anim.x++;
    if(anim.x * 64  >= textureCharacter.getSize().x){
        anim.x = 0;
    }

    spriteCharacter.setTextureRect(IntRect(anim.x * 0, anim.y * 64,64,64));
}
