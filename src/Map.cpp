#include "Map.h"
using namespace std;

Map::Map()
{
    if(!textureMap.loadFromFile("background.png"))
    {
        cout<<"Error loading Map";
    }
    textureMap.setSmooth(true);
    spriteMap.setTexture(textureMap);
}

Map::~Map()
{
    //dtor
}

Texture Map::getTextureMap()
{
    return textureMap;
}

Sprite Map::getSpriteMap()
{
    return spriteMap;
}
