#ifndef MAP_H
#define MAP_H
#include<SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using namespace sf;


class Map
{
    public:
        Map();
        virtual ~Map();
        Texture getTextureMap();
        Sprite getSpriteMap();

    protected:

    private:
        Texture textureMap;
        Sprite spriteMap;
};

#endif // MAP_H
