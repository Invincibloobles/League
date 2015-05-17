//
//  DecayingStatModifier.h
//  League
//
//  Created by Chris England on 08/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__DecayingStatModifier__
#define __League__DecayingStatModifier__

#include "FixedDurationModifier.h"
#include <iostream>

class DecayingStatModifier : public FixedDurationModifier {
    
    float _decayRate;
    
public:
    
    DecayingStatModifier(std::string sourceName, std::string statID, float statAdjustment, float endStatAdjustment, int duration, ModifierType type);
    ~DecayingStatModifier();
    void update();

};

#endif /* defined(__League__DecayingStatModifier__) */
