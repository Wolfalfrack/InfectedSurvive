#include "Option.h"

Option::Option()
{
    //ctor
}

Option::~Option()
{
    //dtor
}

void Option::run()
{
    RenderWindow window(VideoMode(600, 600), "Option");
    window.setFramerateLimit(60);

    Font font;
    Text text;
    if(!font.loadFromFile("arial.ttf")){

    }
    text.setFont(font);
    text.setString("Options");
    text.setColor(Color::White);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.draw(text);

        window.display();
        window.clear();
    }

}
