#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::run()
{
    RenderWindow window(VideoMode(600, 600), "Survivor Infected");

    Menu menu(window.getSize().x,window.getSize().y);
    Music music;
    if (!music.openFromFile("Media/Final Destination.wav")){

    }
    music.setVolume(20);
    music.setLoop(true);
    music.play();

    Font font;
    Text title;
    if(!font.loadFromFile("Media/arial.ttf")){}
    title.setFont(font);
    title.setString("Infected Survive");
    title.setPosition(190,30);
    title.setStyle(Text::Bold);
    title.setStyle(Text::Underlined);
    title.setColor(Color::White);

    Text footer;
    if(!font.loadFromFile("Media/arial.ttf")){}
    footer.setFont(font);
    footer.setString("Press enter to confirm.");
    footer.setPosition(180,550);
    footer.setColor(Color::White);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::KeyReleased:
                switch(event.key.code)
                {
                case Keyboard::Z:
                    menu.moveUp();
                    break;

                case Keyboard::S:
                    menu.moveDown();
                    break;

                case Keyboard::Return:
                    menu.getPressedItem(window);
                    break;
                }
                break;
            case Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        Sprite spriteBackground;
        Texture textureBackground;
        if(!textureBackground.loadFromFile("Media/Background.png"))
        {
            cout<<"Error loading background";
        }
        textureBackground.setSmooth(true);
        spriteBackground.setTexture(textureBackground);
        window.draw(spriteBackground);
        window.draw(title);
        window.draw(footer);
        menu.draw(window);
        window.display();


    }
}
