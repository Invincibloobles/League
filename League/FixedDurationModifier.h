//
//  FixedDurationModifier.h
//  League
//
//  Created by Chris England on 17/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__FixedDurationModifier__
#define __League__FixedDurationModifier__

#include "StatModifier.h"

class FixedDurationModifier : public StatModifier {
    
public:
    FixedDurationModifier(std::string sourceName, std::string statID, float statAdjustment, int duration, ModifierType type);
    virtual ~FixedDurationModifier();
    
    virtual void update();
};

#endif /* defined(__League__FixedDurationModifier__) */
