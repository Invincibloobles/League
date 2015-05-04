//
//  Champion.h
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __FakeLoL__Champion__
#define __FakeLoL__Champion__

#include "Point.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ability.h"
#include "StatModifier.h"

class Champion {
private:
	Point* _location;
	int _mana, _health;
    Ability* _ability;
    Point const * _targetPosition;
    std::map <std::string, int> _baseStats;
    std::map <std::string, std::vector <StatModifier*>> _flatModifiers;
//    std::map <std::string, int> _percentageModifiers; TODO: later
    
    void updateCooldowns();
    int getStatWithModifiers(std::string statID) const;
public:
	Champion(int mana, int health, int moveSpeed, Ability &ability);
	~Champion();
    
    void setLocation(double x, double y);
    const Point& getLocation() const;
    void castAbility(Point const &castLocation);
	void update();
    void updateTargetPosition(Point const &newTarget);
    void draw(sf::RenderTexture &texture);
    void addFlatStatModifier(StatModifier &statModifier);
};

#endif /* defined(__FakeLoL__Champion__) */
