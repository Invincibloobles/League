//
//  SkillshotProjectile.h
//  League
//
//  Created by Chris England on 05/07/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__SkillshotProjectile__
#define __League__SkillshotProjectile__

#include "Projectile.h"
#include <iostream>

class SkillshotProjectile : public Projectile {
    sf::Vector2f _velocity;
    int _maxVelocity;
    int _maxRange;
    float _distanceTravelled;
public:
    SkillshotProjectile(sf::Vector2f position, sf::Vector2f target, int maxVelocity, int hitRadius, int maxRange);
    ~SkillshotProjectile();
    
    void update();
    inline bool keepAlive(){return _distanceTravelled < _maxRange;};
};
#endif /* defined(__League__SkillshotProjectile__) */
