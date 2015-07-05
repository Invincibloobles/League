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
    int _hitRadius;
    // function ptr to collision function
public:
    Projectile(sf::Vector2f position, int hitRadius);
    virtual ~Projectile();
    virtual void update()=0;
    virtual void draw(sf::RenderTexture &texture) const;
    void checkForCollisions();
    virtual bool keepAlive()=0;
    
    inline sf::Vector2f getPosition() const {return _position;};
    inline void setPosition(sf::Vector2f position) {_position = position;};
};

#endif /* defined(__League__Projectile__) */
