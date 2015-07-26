//
//  AbilityDisplay.h
//  League
//
//  Created by Chris England on 26/07/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__AbilityDisplay__
#define __League__AbilityDisplay__
#include <SFML/Graphics.hpp>
class Champion;

class AbilityDisplay : public sf::Transformable {
    sf::Text _cooldownInfo;
    sf::RectangleShape _cooldownBox;
    sf::Text _text;
    sf::Font _font;
    
public:
    AbilityDisplay(sf::Font);
    ~AbilityDisplay();
    void draw(sf::RenderTexture &texture);
    void setInfo(Champion const &champion);
};

#endif /* defined(__League__AbilityDisplay__) */
