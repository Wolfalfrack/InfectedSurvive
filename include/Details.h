#ifndef DETAILS_H
#define DETAILS_H
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"

#include <iostream>

using namespace std;
using namespace sf;


// This class shows a windows with the informations about the developers
class Details
{
    public:
        Details();
        virtual ~Details();

        void run();
    protected:

    private:
};

#endif // DETAILS_H
