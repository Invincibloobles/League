//
//  StatModifier.h
//  League
//
//  Created by Chris England on 08/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__StatModifier__
#define __League__StatModifier__

#include <string>
#include "ModifierType.h"

class StatModifier {
    std::string _sourceName;
    std::string _statID;
    float _statAdjustment;
    int _duration;
    ModifierType _type;

protected:
    inline void setStatAdjustment(float newStatAdjustment) {_statAdjustment = newStatAdjustment;};
public:
    StatModifier(std::string sourceName, std::string statID, float statAdjustment, int duration, ModifierType type);
    ~StatModifier();
    
    inline std::string getStatID() const {return _statID;};
    inline float getStatAdjustment() const {return _statAdjustment;};
    inline ModifierType getType() const {return _type;};
    inline bool hasExpired() const {return _duration <= 0;};
    virtual void update();
};

#endif /* defined(__League__StatModifier__) */
