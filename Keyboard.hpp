#pragma once 

#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>

#include "Object.hpp"
#include "ObjectHero.hpp"
#include "Constants.hpp"
#include "Menu.hpp"
#include "Utils.hpp"

void keyboardObserver(General& G) {
    auto& normalLayer = G.getNormalLayerObjects();

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Escape )) {
        G.setIsMenuActive( true );
    }

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left )) {
        if ((int)ObjectHero::getXCoord() - 1 >= 0 && normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( (ObjectHero::getXCoord() - 1) * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1] );

            ObjectHero::setXCoord( ObjectHero::getXCoord() - 1 );

            Utils::setNewCoords( G.getCamera());

            G.getClock().restart();

            rerender( G);
        }
    }

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right )) {
        if ((int)ObjectHero::getXCoord() + 1 < normalLayer[ObjectHero::getYCoord()].size() && normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( (ObjectHero::getXCoord() + 1) * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1] );

            ObjectHero::setXCoord( ObjectHero::getXCoord() + 1 );

            Utils::setNewCoords( G.getCamera() );

            G.getClock().restart();

            rerender( G );
        }
    }

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up )) {
        if ((int)ObjectHero::getYCoord() - 1 >= 0 && normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() - 1) * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()] );

            ObjectHero::setYCoord( ObjectHero::getYCoord() - 1 );

            Utils::setNewCoords( G.getCamera() );

            G.getClock().restart();

            rerender( G );
        }
    }

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down )) {
        if ((int)ObjectHero::getYCoord() + 1 < normalLayer.size() && normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() + 1) * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()] );

            ObjectHero::setYCoord( ObjectHero::getYCoord() + 1 );

            Utils::setNewCoords( G.getCamera() );

            G.getClock().restart();

            rerender( G );
        }
    }
}
