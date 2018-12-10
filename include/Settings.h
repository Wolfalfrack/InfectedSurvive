#ifndef SETTINGS_H
#define SETTINGS_H
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"

#include <iostream>

using namespace std;
using namespace sf;

class Settings
{
    public:
        Settings();
        virtual ~Settings();
        int runSettings();

    protected:

    private:
        int difficulty;
};

#endif // SETTINGS_H
