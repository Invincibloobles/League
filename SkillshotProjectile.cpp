//
//  SkillshotProjectile.cpp
//  League
//
//  Created by Chris England on 05/07/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "SkillshotProjectile.h"
#include <math.h>

SkillshotProjectile::SkillshotProjectile(sf::Vector2f position, sf::Vector2f target, int maxVelocity, int hitRadius, int maxRange)
:Projectile(position, hitRadius),
_maxRange(maxRange),
_maxVelocity(maxVelocity),
_distanceTravelled(0)
{
    _velocity = target - position;
    int mag = sqrt(_velocity.x * _velocity.x + _velocity.y * _velocity.y);
    if (mag != 0) {
        _velocity.x /= mag;
        _velocity.y /= mag;
    }
    std::cout << "SkillshotProjectile Created\n";
}

SkillshotProjectile::~SkillshotProjectile()
{
    std::cout << "SkillshotProjectile Destroyed\n";
}

void SkillshotProjectile::update()
{
    sf::Vector2f currentPos = getPosition();
    sf::Vector2f velStep = _velocity;
    velStep.x *= _maxVelocity;
    velStep.y *= _maxVelocity;
    currentPos += velStep;
    setPosition(currentPos);
    float moveDistance = sqrt(velStep.x * velStep.x + velStep.y * velStep.y);
    _distanceTravelled += moveDistance;
}