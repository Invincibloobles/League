//
//  TestAbility.cpp
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "TestAbility.h"
#include <iostream>

TestAbility::TestAbility(int manaCost, int castRange, int cooldownTime)
:Ability(manaCost, castRange, cooldownTime)
{
    std::cout << "TestAbility created\n";
}

TestAbility::~TestAbility()
{
    std::cout << "TestAbility destroyed\n";
}

void TestAbility::cast(Champion &owner, const Point &castLocation)
{
    std::cout << "TestAbility casted\n";
}