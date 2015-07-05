//
//  Projectile.cpp
//  League
//
//  Created by Chris England on 07/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, int hitRadius)
:_position(position),
_hitRadius(hitRadius)
{
    std::cout << "Projectile Created\n";
}

Projectile::~Projectile()
{
    std::cout << "Projectile Destroyed\n";
}

void Projectile::draw(sf::RenderTexture &texture) const
{
    sf::CircleShape projectileShape(_hitRadius);
    projectileShape.setPosition(_position.x - _hitRadius / 2.0f, _position.y - _hitRadius / 2.0f);
    projectileShape.setFillColor(sf::Color(255, 255, 255));
    texture.draw(projectileShape);
}

void Projectile::checkForCollisions()
{
    // call collision function
}