//
//  Ability.h
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __FakeLoL__Ability__
#define __FakeLoL__Ability__

#include <SFML/Graphics.hpp>
class Champion;

class Ability {
private:
	int _manaCost;
	int _castRange;
	int _cooldownTime;
    int _currentCooldownTimer;
public:
    Ability(int manaCost, int castRange, int cooldownTime);
	virtual ~Ability();
    virtual void cast(Champion &owner, sf::Vector2f castLocation) = 0;
    virtual void update() = 0;
    
    inline int getCooldownTime() const {return _cooldownTime;};
    inline int getCurrentCooldownTimer() const {return _currentCooldownTimer;};
    inline void setCurrentCooldownTimer(int time) {_currentCooldownTimer = time;};
    inline bool isOnCooldown() const {return (_currentCooldownTimer > 0);};
};

#endif /* defined(__FakeLoL__Ability__) */
