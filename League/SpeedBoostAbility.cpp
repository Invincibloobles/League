//
//  SpeedBoostAbility.cpp
//  League
//
//  Created by Chris England on 03/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "SpeedBoostAbility.h"

#include <iostream>
#include "Champion.h"
#include "ModifierType.h"

SpeedBoostAbility::SpeedBoostAbility(int manaCost, int castRange, int cooldownTime)
:Ability(manaCost, castRange, cooldownTime)
{
    std::cout << "SpeedBoostAbility created\n";
}

SpeedBoostAbility::~SpeedBoostAbility()
{
    std::cout << "SpeedBoostAbility destroyed\n";
}

void SpeedBoostAbility::cast(Game &gamestate, Champion &owner, sf::Vector2f castLocation)
{
    std::cout << "SpeedBoostAbility casted\n";
    // apply speed boost to owner
    owner.addStatModifier(*new FixedDurationModifier("SpeedBoostAbility", "moveSpeed", 0.5, 30, ModifierType::ADDATIVE));
    setCurrentCooldownTimer(getCooldownTime());
}

void SpeedBoostAbility::update()
{
    int cooldownTimer = getCurrentCooldownTimer();
    if (cooldownTimer > 0) {
        cooldownTimer--;
        setCurrentCooldownTimer(cooldownTimer);
    }
}
