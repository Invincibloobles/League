//
//  SpeedBoostAbility.h
//  League
//
//  Created by Chris England on 03/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__SpeedBoostAbility__
#define __League__SpeedBoostAbility__

#include "Ability.h"
#include "StatModifier.h"

class SpeedBoostAbility : public Ability {
    StatModifier *_flatSpeedBoost;
public:
    void cast(Champion &owner, const Point &castLocation);
    SpeedBoostAbility(int manaCost, int castRange, int cooldownTime);
    ~SpeedBoostAbility();
    
    void update();
};
#endif /* defined(__League__SpeedBoostAbility__) */