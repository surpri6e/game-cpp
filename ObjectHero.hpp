#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Constants.hpp"

typedef unsigned int ui;

class ObjectHero : public Object {
private:
    static inline ui coordsOnMapX;
    static inline ui coordsOnMapY;
    ui HP;
    // ����������� �������
public:
    ObjectHero( std::string signOnMap, float x, float y, ui HP, const sf::Texture& texture )
        : Object( false, false, signOnMap, x, y, false ) {

        coordsOnMapX = x / consts::WIDTH_TILE;
        coordsOnMapY = y / consts::HEIGHT_TILE;

        this->HP = HP;

        this->shape.setTexture( &texture );
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