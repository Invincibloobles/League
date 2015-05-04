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

SpeedBoostAbility::SpeedBoostAbility(int manaCost, int castRange, int cooldownTime)
:Ability(manaCost, castRange, cooldownTime)
{
//    _flatSpeedBoost = new StatModifier("SpeedBoostAbility", "moveSpeed", 20, 120);
    std::cout << "SpeedBoostAbility created\n";
}

SpeedBoostAbility::~SpeedBoostAbility()
{
    std::cout << "SpeedBoostAbility destroyed\n";
}

void SpeedBoostAbility::cast(Champion &owner, const Point &castLocation)
{
    std::cout << "SpeedBoostAbility casted\n";
    // apply speed boost to owner
    owner.addFlatStatModifier(*new StatModifier("SpeedBoostAbility", "moveSpeed", 20, 30));
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
