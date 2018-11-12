#ifndef APPLICATION_H
#define APPLICATION_H
#include "MainMenu.h"


class Application
{
    public:
        Application();
        virtual ~Application();
        void run();

    protected:

    private:
        MainMenu mainMenu;
};

#endif // APPLICATION_H
