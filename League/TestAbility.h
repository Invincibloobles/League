//
//  TestAbility.h
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __FakeLoL__TestAbility__
#define __FakeLoL__TestAbility__

#include "Ability.h"

class TestAbility : public Ability {
    
public:
    void cast(Champion &owner, const Point &castLocation);
    TestAbility(int manaCost, int castRange, int cooldownTime);
    ~TestAbility();
};

#endif /* defined(__FakeLoL__TestAbility__) */
