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
    _location = new Point(0,0);
    _targetPosition = NULL;
    _baseStats["moveSpeed"] = moveSpeed;
    std::cout << "Champion created\n";
    
}

Champion::~Champion()
{
    delete _location;
    if (_targetPosition != NULL) {
        delete _targetPosition;
    }
    delete _ability;
    std::cout << "Champion destroyed\n";
}

void Champion::setLocation(double x, double y)
{
    _location->x = x;
    _location->y = y;
}

const Point& Champion::getLocation() const
{
    return *_location;
}

void Champion::castAbility(Point const &castLocation)
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
        float xDiff = _targetPosition->x - _location->x;
        float yDiff = _targetPosition->y - _location->y;
        float mag = sqrt((xDiff*xDiff)+(yDiff*yDiff));
        int moveSpeed = getStatWithModifiers("moveSpeed");
        if (mag <= moveSpeed) {
            targetReached = true;
            _location->x = _targetPosition->x;
            _location->y = _targetPosition->y;
        } else {
            float xUnit = xDiff/mag;
            float yUnit = yDiff/mag;
            _location->x += xUnit * moveSpeed;
            _location->y += yUnit * moveSpeed;
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

void Champion::updateTargetPosition(const Point &newTarget)
{
    delete _targetPosition;
    _targetPosition = &newTarget;
    std::cout << "Target set: " << _targetPosition->x << ", " << _targetPosition->y << "\n";

}

void Champion::updateCooldowns() {
    _ability->update();
    // update each current buff as well
    // for each base stat do the following
    if (_flatModifiers.count("moveSpeed") > 0) {
        std::vector<StatModifier*> *currentMods = &_flatModifiers.find("moveSpeed")->second;
        if (currentMods->size() > 0) {
            std::vector<StatModifier*>::iterator iter;
            for(iter = currentMods->begin(); iter != currentMods->end();){
                (*iter)->update();
                if ((*iter)->hasExpired()) {
                    currentMods->erase(iter);
                } else {
                    ++iter;
                }
            }
        }
    }
}

void Champion::addFlatStatModifier(StatModifier &statModifier)
{
    std::cout << "Stuff";
    // seems a little clumsy to get the statID out
    _flatModifiers[statModifier.getStatID()].push_back(&statModifier);
}

int Champion::getStatWithModifiers(std::string statID) const
{
    int baseStat = _baseStats.find(statID)->second;
    int modifiedStat = baseStat;
    if (_flatModifiers.count(statID) > 0) {
        std::vector<StatModifier*> currentMods = _flatModifiers.find(statID)->second;
        std::vector<StatModifier*>::iterator iter;
        for(iter = currentMods.begin(); iter != currentMods.end(); iter++){
            modifiedStat += (*iter)->getFlatStatAdjust();
        }
    }
    return modifiedStat;
}

void Champion::draw(sf::RenderTexture &texture)
{
    texture.clear(sf::Color(0, 150, 0));
    sf::CircleShape championShape(10);
    championShape.setPosition(_location->x - 10, _location->y - 10);
    championShape.setFillColor(sf::Color(200, 0, 200));
    texture.draw(championShape);
    texture.display();
}