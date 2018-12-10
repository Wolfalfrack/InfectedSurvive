#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <vector>
#include <SFML/System.hpp>
#include "Bullet.h"
#include "ListZombie.h"


using namespace std;
using namespace sf;

class Weapon
{
    public:
        Weapon(int power);
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);
        virtual ~Weapon();
        Weapon();

        vector<Bullet> getBullet();


        string str()const;

        void addBullet(Bullet& bul);
        void deleteAllBullet();
        void shoot(Bullet bul,Vector2f persoCenter, Vector2f aimDirNorm, const RenderWindow& window, ListZombie& listZombie, int& killStreak);

    protected:

    private:
        int power;
        SoundBuffer buffer;
        Sound sound;
        vector<Bullet> bullets;
};

#endif // ARME_H
