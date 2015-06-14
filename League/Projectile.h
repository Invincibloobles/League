//
//  Projectile.h
//  League
//
//  Created by Chris England on 07/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__Projectile__
#define __League__Projectile__

#include <SFML/Graphics.hpp>
#include <iostream>

class Projectile {
    sf::Vector2f _position;
    sf::Vector2f _velocity;
    int _hitRadius;
public:
    Projectile(sf::Vector2f position, sf::Vector2f velocity, int hitRadius);
    virtual ~Projectile();
    virtual void update();
    virtual void draw(sf::RenderTexture &texture);
};

#endif /* defined(__League__Projectile__) */
