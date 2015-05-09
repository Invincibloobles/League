//
//  DecayingStatModifier.h
//  League
//
//  Created by Chris England on 08/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__DecayingStatModifier__
#define __League__DecayingStatModifier__

#include "StatModifier.h"
#include <iostream>

class DecayingStatModifier : public StatModifier {
    
    float _decayRate;
    
public:
    
    DecayingStatModifier(std::string sourceName, std::string statID, float statAdjustment, int duration, ModifierType type);
    ~DecayingStatModifier();
    void update();

};


#endif /* defined(__League__DecayingStatModifier__) */
