//
//  HUD.cpp
//  League
//
//  Created by Chris England on 15/07/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "HUD.h"
#include "Champion.h"
#include <string>
#include "ResourcePath.hpp"
#include <array>
HUD::HUD()
{
    if (!_font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        // error...
    } else {
        _healthInfo.setFont(_font);
        _healthInfo.setCharacterSize(16);
        _abilityInfo.setFont(_font);
        _abilityInfo.setCharacterSize(16);
        _abilityInfo.setPosition(200, 0);
        _abilityDisplay = new AbilityDisplay(_font);
        _abilityDisplay->setPosition(300, 0);
    }
}

HUD::~HUD()
{
    delete _abilityDisplay;
}

void HUD::setInfo(Champion const &champion)
{
    int currentHealth = champion.getCurrentHealth();
    int maxHealth = champion.getMaxHealth();
    _healthInfo.setString("Current Health: " + std::to_string(currentHealth) + "/" + std::to_string(maxHealth));
    _abilityInfo.setString("Ability");
    
    _abilityDisplay->setInfo(champion);
}

void HUD::draw(sf::RenderTexture &texture)
{
    texture.draw(_healthInfo);
    texture.draw(_abilityInfo);
    _abilityDisplay->draw(texture);
}