#include "Settings.h"

Settings::Settings()
{
    //ctor
    this->difficulty = 50;
}

Settings::~Settings()
{
    //dtor
}

// this method creates the window from the setting's button, which let the user chooses the difficulty
int Settings::runSettings()
{
    RenderWindow window(VideoMode(600, 600), "Settings");
    window.setFramerateLimit(60);

    Font font;
    Text text;
    if(!font.loadFromFile("Media/arial.ttf")){}
    text.setFont(font);
    text.setString("Set the difficulty with Q and D keys. \n    Press spacebar to confirm");
    text.setPosition(70,200);
    text.setColor(Color::White);

    Text textDifficulty;
    if(!font.loadFromFile("Media/arial.ttf")){}
    textDifficulty.setFont(font);
    textDifficulty.setString(to_string(difficulty));
    textDifficulty.setPosition(290,320);
    textDifficulty.setColor(Color::White);

    int timer = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if(timer > 5){
            // keyboard interaction to increase or decrease the difficulty
            if(Keyboard::isKeyPressed(Keyboard::Q))
            {
                timer = 0;
                if(difficulty > 10)
                {
                    difficulty -= 10;
                    textDifficulty.setString(to_string(difficulty));
                }
                if(difficulty < 10)
                {
                    difficulty = 10;
                    textDifficulty.setString(to_string(difficulty));
                }
            }
            else if(Keyboard::isKeyPressed(Keyboard::D))
            {
                timer = 0;
                if(difficulty < 500)
                {
                    difficulty += 10;
                    textDifficulty.setString(to_string(difficulty));
                }
                if(difficulty > 500)
                {
                    difficulty = 500;
                    textDifficulty.setString(to_string(difficulty));
                }
            }
            else if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                window.close();
                return difficulty;
            }
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
        window.draw(textDifficulty);

        window.display();
        window.clear();

        timer ++;
    }

}
