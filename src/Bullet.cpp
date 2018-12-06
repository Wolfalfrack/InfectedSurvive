#include "Bullet.h"

Bullet::Bullet(float radius = 5.f): currVelocity(0.f, 0.f), maxSpeed(15.f)
{
    this->shape.setRadius(radius);
    this->shape.setFillColor(Color::Black);
}

Bullet::~Bullet()
{
    //dtor
}
