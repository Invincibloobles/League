//
//  HUD.h
//  League
//
//  Created by Chris England on 15/07/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__HUD__
#define __League__HUD__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "AbilityDisplay.h"
class Champion;

class HUD {
    sf::Text _healthInfo;
    sf::Text _abilityInfo;
    sf::Font _font;
    AbilityDisplay * _abilityDisplay;
public:
    HUD();
    ~HUD();
    
    void setInfo(Champion const &champion);
    void draw(sf::RenderTexture &texture);
};
#endif /* defined(__League__HUD__) */
