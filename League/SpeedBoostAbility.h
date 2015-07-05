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
#include "FixedDurationModifier.h"

class SpeedBoostAbility : public Ability {

public:
    void cast(Game &gamestate, Champion &owner, sf::Vector2f castLocation);
    SpeedBoostAbility(int manaCost, int castRange, int cooldownTime);
    ~SpeedBoostAbility();
    
    void update();
};
#endif /* defined(__League__SpeedBoostAbility__) */
