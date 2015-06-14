//
//  Game.cpp
//  League
//
//  Created by Chris England on 14/06/2015.
//  Copyright (c) 2015 Chris England. All rights reserved.
//

#include "Game.h"

#include "SpeedBoostAbility.h"

Game::Game()
{
    SpeedBoostAbility *ability = new SpeedBoostAbility(1, 2, 300);
    _champion = new Champion(100, 100, 5, *ability);
}

Game::~Game()
{
    delete _champion;
}

void Game::update()
{
    _champion->update();
    // update projectiles?
}

void Game::setChampionTarget(const sf::Vector2f &target)
{
    _champion->updateTargetPosition(target);
}

void Game::castChampionAbility(sf::Vector2f castLocation)
{
    _champion->castAbility(castLocation);
}

void Game::draw(sf::RenderTexture &texture)
{
    _champion->draw(texture);
}

void Game::registerProjectile(Projectile &projectile)
{
    _registeredProjectiles.push_back(&projectile);
}