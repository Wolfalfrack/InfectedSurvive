#include <stdexcept>
#include <iostream>
#include "Application.h"

using namespace std;

int main()
{
    try
    {
        srand(time(NULL));
        Application app;
        app.run();

    }catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
