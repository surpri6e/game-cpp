#pragma once 

#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>

#include "Object.hpp"
#include "ObjectHero.hpp"


#include <iostream>
#include "Constants.hpp"
// bool isCLicked = false;

void keyboardObserver( 
    sf::RenderWindow& window,
    std::vector<std::vector<std::shared_ptr<Object>>>& bottomLayer,
    std::vector<std::vector<std::shared_ptr<Object>>>& normalLayer,
    std::vector<std::vector<std::shared_ptr<Object>>>& topLayer ) {

    // Maybe i need to delete shared_ptr<>
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left )) {
        if (normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( (ObjectHero::getXCoord() - 1) * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1] );

            ObjectHero::setXCoord( ObjectHero::getXCoord() - 1 );


            rerender( window, bottomLayer, normalLayer, topLayer );
        }




    }

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right )) {
        if (normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( (ObjectHero::getXCoord() + 1) * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1] );

            ObjectHero::setXCoord( ObjectHero::getXCoord() + 1 );


            rerender( window, bottomLayer, normalLayer, topLayer );
        }




    }

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up )) {
        if (normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->getSignOnMap() == consts::STANDART_ROCK_SIGN) {
            std::cout << "ROCK!!!" << std::endl;
            std::cout << normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->getIsWalkable() << std::endl;
        }
        if (normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() - 1) * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()] );

            ObjectHero::setYCoord( ObjectHero::getYCoord() - 1 );


            rerender( window, bottomLayer, normalLayer, topLayer );
        }




    }
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down )) {
        if (normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()].get()->getIsWalkable()) {
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() + 1) * consts::HEIGHT_TILE );
            normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()] );

            ObjectHero::setYCoord( ObjectHero::getYCoord() + 1 );


            rerender( window, bottomLayer, normalLayer, topLayer );
        }
    }
}