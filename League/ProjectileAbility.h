//
//  ProjectileAbility.h
//  League
//
//  Created by Chris England on 14/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__ProjectileAbility__
#define __League__ProjectileAbility__

#include "Ability.h"
#include <iostream>
class Projectile;

class ProjectileAbility : public Ability {
    std::vector<Projectile*> _projectiles;
    
    const int MAX_RANGE = 100;
    const int MAX_PROJECTILE_VELOCITY = 5;
    const int PROJECTILE_HIT_RADIUS = 2;
public:
    void cast(Game &gamestate, Champion &owner, sf::Vector2f castLocation);
    ProjectileAbility(int manaCost, int castRange, int cooldownTime);
    ~ProjectileAbility();
    
    void update();
};

#endif /* defined(__League__ProjectileAbility__) */
