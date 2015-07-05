//
//  Champion.h
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __FakeLoL__Champion__
#define __FakeLoL__Champion__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ability.h"
#include "StatModifier.h"
class Game;

class Champion {
private:
    sf::Vector2f _location;
	int _mana, _health;
    Ability* _ability;
    sf::Vector2f const * _targetPosition;
    std::map <std::string, int> _baseStats;
    std::map <std::string, std::vector <StatModifier*>> _flatModifiers;
    std::map <std::string, std::vector <StatModifier*>> _addativeModifiers;
//    std::map <std::string, int> _percentageModifiers; TODO: later
    
    void updateCooldowns();
    void updateModifiers(std::map <std::string, std::vector <StatModifier*>> &modiferMap);
    int getStatWithModifiers(std::string statID) const;
public:
	Champion(int mana, int health, int moveSpeed, Ability &ability);
	~Champion();
    
    void setLocation(sf::Vector2f location);
    const sf::Vector2f getLocation() const;
    void castAbility(Game &gamestate, sf::Vector2f castLocation);
	void update();
    void updateTargetPosition(sf::Vector2f const &newTarget);
    void draw(sf::RenderTexture &texture);
    void addStatModifier(StatModifier &statModifier);
};

#endif /* defined(__FakeLoL__Champion__) */
