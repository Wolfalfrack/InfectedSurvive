#include "Munition.h"

Munition::Munition(float radius = 5.f): currVelocity(0.f, 0.f), maxSpeed(15.f)
{
    this->shape.setRadius(radius);
    this->shape.setFillColor(Color::Red);
}

Munition::~Munition()
{
    //dtor
}


