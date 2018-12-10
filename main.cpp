#include <stdexcept>
#include <iostream>
#include "MainMenu.h"
#include "Application.h"

using namespace std;

int main()
{
    srand(time(NULL));

        MainMenu mainMenu;
        mainMenu.run();

}
