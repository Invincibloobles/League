//
//  Game.h
//  League
//
//  Created by Chris England on 14/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#ifndef __League__Game__
#define __League__Game__

#include <iostream>
#include "Champion.h"
#include "Projectile.h"
#include "HUD.h"

class Game {
    Champion *_champion;
    // eventually will probably be a vector of each team
    // also the current selected champion. cast and setTarget calls will then be
    // called on the currently selected champion
    
    //collision lists possibly?
    std::vector<Projectile*> _registeredProjectiles;
    // HUD needs to be in it's own View
    HUD *_hud;
    
public:
    Game();
    ~Game();
    void setChampionTarget(const sf::Vector2f &target);
    void castChampionAbility(sf::Vector2f castLocation);
    void update();
    void draw(sf::RenderTexture &texture);
    
    void registerProjectile(Projectile &projectile);
    void processProjectileCollisions();
};

#endif /* defined(__League__Game__) */
