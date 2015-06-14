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
    
}

Projectile::~Projectile()
{
    
}