//
//  Ability.cpp
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "Ability.h"
#include <iostream>
Ability::Ability(int manaCost, int castRange, int cooldownTime)
: _manaCost(manaCost),
_castRange(castRange),
_cooldownTime(cooldownTime),
_currentCooldownTimer(0)
{
    std::cout << "Ability created\n";
}

Ability::~Ability()
{
    std::cout << "Ability destroyed\n";
}

