#ifndef MENU_H
#define MENU_H

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"

#include "Application.h";
#include "Settings.h"

#define MAX_NUMBER_OF_ITEMS 3

using namespace std;
using namespace sf;

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
