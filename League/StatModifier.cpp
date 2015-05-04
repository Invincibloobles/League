//
//  StatModifier.cpp
//  League
//
//  Created by Chris England on 03/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "StatModifier.h"

StatModifier::StatModifier(std::string sourceName, std::string statID, int flatStatAdjustment, int duration)
:_sourceName(sourceName),
_statID(statID),
_flatStatAdjustment(flatStatAdjustment),
_duration(duration)
{
    
}

void StatModifier::update()
{
    _duration--;
}