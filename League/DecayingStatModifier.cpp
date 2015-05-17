//
//  DecayingStatModifier.cpp
//  League
//
//  Created by Chris England on 08/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "DecayingStatModifier.h"

DecayingStatModifier::DecayingStatModifier(std::string sourceName, std::string statID, float statAdjustment, float endStatAdjustment, int duration, ModifierType type)
: FixedDurationModifier(sourceName, statID, statAdjustment, duration, type)
{
    _decayRate = (statAdjustment - endStatAdjustment) / duration;
}

DecayingStatModifier::~DecayingStatModifier()
{
    
}

void DecayingStatModifier::update()
{
    float newStatValue = getStatAdjustment() - _decayRate;
    setStatAdjustment(newStatValue);
}