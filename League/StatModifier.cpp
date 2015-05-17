//
//  StatModifier.cpp
//  League
//
//  Created by Chris England on 08/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "StatModifier.h"
#include <iostream>

StatModifier::StatModifier(std::string sourceName, std::string statID, float statAdjustment, int duration, ModifierType type)
:_sourceName(sourceName),
_statID(statID),
_statAdjustment(statAdjustment),
_duration(duration),
_type(type)
{
    std::cout << "Modifier created \n";
}

StatModifier::~StatModifier()
{
    std::cout << "Modifier destroyed \n";
}
