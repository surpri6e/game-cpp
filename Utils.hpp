#pragma once 

#include "SFML/Graphics.hpp"

#include "ObjectHero.hpp"
#include "Constants.hpp"

class Utils {
public:
    static void setNewCoords( sf::View& camera ) {
        // Why is it working?
        // Camera barrier
        camera.setCenter( sf::Vector2f( ObjectHero::getXCoord() * consts::WIDTH_TILE + consts::WIDTH_TILE / 2, ObjectHero::getYCoord() * consts::HEIGHT_TILE + consts::HEIGHT_TILE / 2 ) );
    }
};