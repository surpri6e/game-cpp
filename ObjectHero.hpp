#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "Object.hpp"
#include "Constants.hpp"

typedef unsigned int ui;

class ObjectHero : public Object {
private:
    static inline ui coordsOnMapX;
    static inline ui coordsOnMapY;
    ui HP;
    // Направление взгляда
    static inline std::string directionOfView;
public:
    ObjectHero( std::string signOnMap, float x, float y, ui HP, const sf::Texture& texture )
        : Object( false, false, signOnMap, x, y, false ) {

        coordsOnMapX = x / consts::WIDTH_TILE;
        coordsOnMapY = y / consts::HEIGHT_TILE;

        this->HP = HP;

        this->shape.setTexture( &texture );

        // Standart direction is move top 
        this->shape.setTextureRect( sf::IntRect(sf::Vector2i(32, 32), sf::Vector2i(consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE)) );

        directionOfView = "TOP";
    }


    static std::string getDirectionOfView() {
        return directionOfView;
    }

    static void setDirectionOfView( std::string newDirectionOfView ) {
        directionOfView = newDirectionOfView;
    }

    static void setXCoord(ui newX) {
        coordsOnMapX = newX;
    }

    static void setYCoord( ui newY ) {
        coordsOnMapY = newY;
    }

    static ui getXCoord() {
        return coordsOnMapX;
    }

    static ui getYCoord() {
        return coordsOnMapY;
    }
};