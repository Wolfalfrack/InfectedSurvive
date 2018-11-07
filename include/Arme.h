#ifndef ARME_H
#define ARME_H
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Arme
{
    public:
        Arme(int puissance, int munition, string sprite);
        Arme(const Arme& other);
        bool operator=(const Arme& other);
        virtual ~Arme();
        Arme();

        string str()const;

    protected:

    private:
        int puissance;
        int munition;
        string sprite;
};

#endif // ARME_H
