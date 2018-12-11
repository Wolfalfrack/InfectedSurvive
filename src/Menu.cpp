#include "Menu.h"

Menu::Menu(float width,float height)
{
    //ctor

    if(!font.loadFromFile("Media/arial.ttf")){

    }

    // creation of the different text as table of Text elements
    menu[0].setFont(font);
    menu[0].setColor(Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(280, height/(MAX_NUMBER_OF_ITEMS + 1) *1));

    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(Vector2f(260, height/(MAX_NUMBER_OF_ITEMS + 1)* 2));

    menu[2].setFont(font);
    menu[2].setColor(Color::White);
    menu[2].setString("About Infected Survive");
    menu[2].setPosition(Vector2f(160, height/(MAX_NUMBER_OF_ITEMS + 1)* 3));

    menu[3].setFont(font);
    menu[3].setColor(Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(Vector2f(280, height/(MAX_NUMBER_OF_ITEMS + 1)* 4));

    selectedItem = 0;

    this->difficulty = 50;
}

Menu::~Menu()
{
    //dtor
}

void Menu::setDifficulty(int difficulty)
{
    this->difficulty = difficulty;
}

// this method draws the different Texts in the window.
void Menu::draw(RenderWindow &window)
{
    for(int i =0 ;i<MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }
}

// this method manages the color of the selected item when it moves up
void Menu::moveUp()
{
    if(selectedItem -1 >= 0)
    {
        menu[selectedItem].setColor(Color::White);
        selectedItem--;
        menu[selectedItem].setColor(Color::Red);
    }
}

// this method manages the color of the selected item when it moves down
void Menu::moveDown()
{
    if(selectedItem + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItem].setColor(Color::White);
        selectedItem++;
        menu[selectedItem].setColor(Color::Red);
    }
}

// this method manages the link between the buttons and the class corresponding
int Menu::getPressedItem(RenderWindow &window)
{
    if(selectedItem== 0)
    {
        Application application(difficulty);
        application.run();
    }
    else if(selectedItem==1)
    {
        Settings settings;
        difficulty = settings.runSettings();
    }
    else if(selectedItem==2)
    {
        Details details;
        details.run();
    }
    else
    {
        window.close();
    }
}
