//
//  Champion.cpp
//  FakeLoL
//
//  Created by Chris England on 23/03/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "Champion.h"
#include <math.h>

Champion::Champion(int mana, int health, int moveSpeed, Ability &ability)
:_mana(mana),
_health(health),
_ability(&ability)
{
    _location = sf::Vector2f(0,0);
    _targetPosition = NULL;
    _baseStats["moveSpeed"] = moveSpeed;
    std::cout << "Champion created\n";
}

Champion::~Champion()
{
    if (_targetPosition != NULL) {
        delete _targetPosition;
    }
    delete _ability;
    std::cout << "Champion destroyed\n";
}

void Champion::setLocation(sf::Vector2f location)
{
    _location = location;
}

const sf::Vector2f Champion::getLocation() const
{
    return _location;
}

void Champion::castAbility(sf::Vector2f castLocation)
{
    if (!_ability->isOnCooldown()) {
        _ability->cast(*this, castLocation);
    } else {
        std::cout << "Ability is currently on cooldown \n";
    }
}

void Champion::update()
{
    bool targetReached = false;
    if (_targetPosition != NULL) {
        // move to target position
        float xDiff = _targetPosition->x - _location.x;
        float yDiff = _targetPosition->y - _location.y;
        float mag = sqrt((xDiff*xDiff)+(yDiff*yDiff));
        int moveSpeed = getStatWithModifiers("moveSpeed");
        if (mag <= moveSpeed) {
            targetReached = true;
            _location.x = _targetPosition->x;
            _location.y = _targetPosition->y;
        } else {
            float xUnit = xDiff/mag;
            float yUnit = yDiff/mag;
            _location.x += xUnit * moveSpeed;
            _location.y += yUnit * moveSpeed;
        }
        // if target position reached then delete _targetPosition
        if (targetReached) {
            std::cout << "Target reached\n";
            delete _targetPosition;
            _targetPosition = NULL;
        }
    }
    updateCooldowns();
}

void Champion::updateTargetPosition(const sf::Vector2f &newTarget)
{
    delete _targetPosition;
    _targetPosition = &newTarget;
    std::cout << "Target set: " << _targetPosition->x << ", " << _targetPosition->y << "\n";

}

void Champion::updateCooldowns() {
    _ability->update();
    
    updateModifiers(_flatModifiers);
    updateModifiers(_addativeModifiers);
}

void Champion::updateModifiers(std::map<std::string, std::vector<StatModifier *> > &modiferMap)
{
    std::map<std::string, std::vector<StatModifier*>>::iterator mapIter;
    std::vector<StatModifier*>::iterator modIter;
    
    for (mapIter = modiferMap.begin(); mapIter != modiferMap.end(); ++mapIter) {
        std::vector<StatModifier*> *currentMods = &mapIter->second;
        for (modIter = currentMods->begin(); modIter != currentMods->end();) {
            StatModifier *modifier = (*modIter);
            modifier->update();
            if (modifier->hasExpired()) {
                currentMods->erase(modIter);
                std::cout << "modified removed \n";
                delete modifier;
            } else {
                ++modIter;
            }
        }
    }
}

void Champion::addStatModifier(StatModifier &statModifier)
{
    ModifierType modType = statModifier.getType();
    if (modType == ModifierType::FLAT) {
        _flatModifiers[statModifier.getStatID()].push_back(&statModifier);
    } else if (modType == ModifierType::ADDATIVE) {
        _addativeModifiers[statModifier.getStatID()].push_back(&statModifier);
    } else if (modType == ModifierType::MULTIPLICATIVE) {
        
    } else {
        std::cout << "Unrecognised StatModifer type";
    }
}

int Champion::getStatWithModifiers(std::string statID) const
{
    int baseStat = _baseStats.find(statID)->second;
    float modifiedStat = baseStat;
    
    // declare once
    std::vector<StatModifier*> mods;
    std::vector<StatModifier*>::iterator iter;
    
    // apply flat modifiers first
    if (_flatModifiers.count(statID) > 0) {
        mods = _flatModifiers.find(statID)->second;
        for(iter = mods.begin(); iter != mods.end(); iter++){
            if ((*iter)->getType() == ModifierType::FLAT) {
                modifiedStat += (*iter)->getStatAdjustment();
            }
        }
    }
    
    // apply addative modifiers
    if (_addativeModifiers.count(statID) > 0) {
        float addativePercentage = 1;
        mods = _addativeModifiers.find(statID)->second; // THIS LINE BREAKS
        for(iter = mods.begin(); iter != mods.end(); iter++){
            if ((*iter)->getType() == ModifierType::ADDATIVE) {
                addativePercentage += (*iter)->getStatAdjustment();
            }
        }
        float addativeBonus = addativePercentage * modifiedStat;
        modifiedStat = addativeBonus;
    }
    
    // multiplicative bonus calcs go here.    
    return modifiedStat;
}

void Champion::draw(sf::RenderTexture &texture)
{
    texture.clear(sf::Color(35, 142, 35));
    sf::CircleShape championShape(10);
    championShape.setPosition(_location.x - 10, _location.y - 10);
    championShape.setFillColor(sf::Color(99, 184, 255));
    texture.draw(championShape);
    texture.display();
}