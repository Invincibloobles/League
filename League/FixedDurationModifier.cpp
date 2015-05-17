//
//  FixedDurationModifier.cpp
//  League
//
//  Created by Chris England on 17/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "FixedDurationModifier.h"

FixedDurationModifier::FixedDurationModifier(std::string sourceName, std::string statID, float statAdjustment, int duration, ModifierType type)
: StatModifier(sourceName, statID, statAdjustment, duration, type)
{

}

FixedDurationModifier::~FixedDurationModifier()
{
    
}

void FixedDurationModifier::update()
{
    int currentDuration = getDuration();
    setDuration(--currentDuration);
}