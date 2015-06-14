//
//  Projectile.cpp
//  League
//
//  Created by Chris England on 07/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, sf::Vector2f velocity, int hitRadius)
:_position(position),
_velocity(velocity),
_hitRadius(hitRadius)
{
    std::cout << "Projectile Created\n";
}

Projectile::~Projectile()
{
    std::cout << "Projectile Destroyed\n";
}

void Projectile::update()
{
    _position += _velocity;
}

void Projectile::draw(sf::RenderTexture &texture)
{
    sf::CircleShape projectileShape(_hitRadius);
    projectileShape.setPosition(_position.x - _hitRadius / 2.0f, _position.y - _hitRadius / 2.0f);
    projectileShape.setFillColor(sf::Color(255, 255, 255));
    texture.draw(projectileShape);
}