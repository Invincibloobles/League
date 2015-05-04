//
//  StatModifier.h
//  League
//
//  Created by Chris England on 03/05/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__StatModifier__
#define __League__StatModifier__

#include <string>

class StatModifier {
    std::string _sourceName;
    std::string _statID;
    int _flatStatAdjustment;
    int _duration;
    
public:
    StatModifier(std::string sourceName, std::string statID, int flatStatAdjustment, int duration);
    ~StatModifier();
    
    inline std::string getStatID() const {return _statID;};
    inline int getFlatStatAdjust() const {return _flatStatAdjustment;};
    inline bool hasExpired() const {return _duration <= 0;};
    void update();
};

#endif /* defined(__League__StatModifier__) */
