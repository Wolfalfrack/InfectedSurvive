#include "Details.h"

Details::Details()
{
    //ctor
}

Details::~Details()
{
    //dtor
}

// this method creates the window from the "about Infected Survive" button which give informations about the game
void Details::run()
{
    RenderWindow window(VideoMode(600, 600), "Details");
    window.setFramerateLimit(60);

    Font font;
    Text text;
    if(!font.loadFromFile("Media/arial.ttf")){}
    text.setFont(font);
    text.setString("\t\t\t\t\tJeu réalisé par\nVerfaille Ludovic et Verhaeghe Nicolas\n étudiants de la HELHa Campus Mons,\ndans le cadre du cours de Mr. V. Altares.");
    text.setPosition(35,200);
    text.setColor(Color::White);

    Text footer;
    if(!font.loadFromFile("Media/arial.ttf")){}
    footer.setFont(font);
    footer.setString("Press spacebar to go back.");
    footer.setPosition(120,550);
    footer.setColor(Color::White);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Sprite spriteBackground;
        Texture textureBackground;
        if(!textureBackground.loadFromFile("Media/Background.png"))
        {
            cout<<"Error loading background";
        }
        textureBackground.setSmooth(true);
        spriteBackground.setTexture(textureBackground);
        window.draw(spriteBackground);

        window.draw(text);
        window.draw(footer);

        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            window.close();
        }

        window.display();
        window.clear();
    }
}
