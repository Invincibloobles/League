//
//  AbilityDisplay.cpp
//  League
//
//  Created by Chris England on 26/07/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "AbilityDisplay.h"
#include "Champion.h"
#include <array>

AbilityDisplay::AbilityDisplay(sf::Font font)
:_font(font)
{
    _cooldownInfo.setFont(_font);
    _cooldownInfo.setString("TEST");
    _cooldownInfo.setCharacterSize(16);
    _cooldownInfo.setPosition(20, 20);
    
    _cooldownBox.setSize(sf::Vector2f(50, 50));
    _cooldownBox.setOrigin(0, 50);
    _cooldownBox.setPosition(0, 60);
    _cooldownBox.setFillColor(sf::Color(0, 230, 255));
}

AbilityDisplay::~AbilityDisplay()
{
}

void AbilityDisplay::setInfo(const Champion &champion)
{
    std::array<std::pair<int, float>, 1> cdInfo = champion.getAbilityCooldowns();
    int cooldown = cdInfo[0].first;
    _cooldownInfo.setString(std::to_string(cooldown));
    float cooldownPercentage = cdInfo[0].second;
    if (cooldownPercentage != 1) {
        _cooldownBox.setScale(1, cooldownPercentage);
        _cooldownBox.setFillColor(sf::Color(255, 0, 0));
    } else {
        _cooldownBox.setFillColor(sf::Color(0, 230, 255));
    }
}

void AbilityDisplay::draw(sf::RenderTexture &texture)
{
    texture.draw(_cooldownBox, getTransform());
    texture.draw(_cooldownInfo, getTransform());
}