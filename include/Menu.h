#ifndef MENU_H
#define MENU_H

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"

#include "Application.h";
#include "Settings.h"
#include "Details.h"

#define MAX_NUMBER_OF_ITEMS 4

using namespace std;
using namespace sf;

// this class manages the different button of the main menu
class Menu
{
    public:
        Menu(float width, float height);
        virtual ~Menu();
        void draw(RenderWindow &window);
        void moveUp();
        void moveDown();
        int getPressedItem(RenderWindow &window);
        void setDifficulty(int difficulty);

    protected:

    private:
        int selectedItem;
        int difficulty;
        Font font;
        Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif // MENU_H
