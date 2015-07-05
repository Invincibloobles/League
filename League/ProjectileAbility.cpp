//
//  ProjectileAbility.cpp
//  League
//
//  Created by Chris England on 14/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "ProjectileAbility.h"
#include "SkillshotProjectile.h"
#include "Champion.h"
#include "Game.h"

ProjectileAbility::ProjectileAbility(int manaCost, int castRange, int cooldownTime)
:Ability(manaCost, castRange, cooldownTime)
{
   std::cout << "ProjectileAbility created\n";
}

ProjectileAbility::~ProjectileAbility()
{
    std::cout << "ProjectileAbility destroyed\n";
    // delete all projectiles
    while (_projectiles.size() > 0) {
        Projectile * back = _projectiles.back();
        delete back;
        _projectiles.pop_back();
    }
}

void ProjectileAbility::cast(Game &gamestate, Champion &owner, sf::Vector2f castLocation)
{
    std::cout << "ProjectileAbility casted\n";
    setCurrentCooldownTimer(getCooldownTime());
    SkillshotProjectile * const projectile = new SkillshotProjectile(owner.getLocation(), castLocation, MAX_PROJECTILE_VELOCITY, PROJECTILE_HIT_RADIUS, MAX_RANGE);
    _projectiles.push_back(projectile);
    gamestate.registerProjectile(*projectile);
    
}

void ProjectileAbility::update()
{
    int cooldownTimer = getCurrentCooldownTimer();
    if (cooldownTimer > 0) {
        cooldownTimer--;
        setCurrentCooldownTimer(cooldownTimer);
    }
}