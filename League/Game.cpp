//
//  Game.cpp
//  League
//
//  Created by Chris England on 14/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "Game.h"

#include "ProjectileAbility.h"

Game::Game()
{
    ProjectileAbility *ability = new ProjectileAbility(1, 2, 300);
    _champion = new Champion(100, 100, 5, *ability);
}

Game::~Game()
{
    delete _champion;
}

void Game::update()
{
    _champion->update();
    std::vector<Projectile*>::iterator projIter;
    for (projIter = _registeredProjectiles.begin(); projIter != _registeredProjectiles.end();) {
        (*projIter)->update();
        if ((*projIter)->keepAlive()) {
            ++projIter;
        } else {
            _registeredProjectiles.erase(projIter);
            delete *projIter;
        }
    }
}

void Game::setChampionTarget(const sf::Vector2f &target)
{
    _champion->updateTargetPosition(target);
}

void Game::castChampionAbility(sf::Vector2f castLocation)
{
    _champion->castAbility(*this, castLocation);
}

void Game::draw(sf::RenderTexture &texture)
{
    texture.clear(sf::Color(35, 142, 35));
    _champion->draw(texture);
    std::vector<Projectile*>::iterator projIter;
    for (projIter = _registeredProjectiles.begin(); projIter != _registeredProjectiles.end(); ++projIter) {
        (*projIter)->draw(texture);
    }
    texture.display();
}

void Game::registerProjectile(Projectile &projectile)
{
    _registeredProjectiles.push_back(&projectile);
}

void Game::processProjectileCollisions()
{
    // iterate over all registered projectiles and call their collision functions
}