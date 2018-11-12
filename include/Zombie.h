#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Zombie
{
    public:
        Zombie(int vie, int vitesse, int puissance);
        Zombie(const Zombie& other);
        Zombie& operator=(const Zombie& other);
        virtual ~Zombie();

        string str()const;

    protected:

    private:
        int vie;
        int vitesse;
        int puissance;
};

#endif // ZOMBIE_H
