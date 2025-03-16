#pragma once 

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class ObjectGrass : public Object {
private:
public: 
	ObjectGrass( std::string signOnMap, float x, float y, const sf::Texture& texture )
		: Object( true, true, signOnMap, x, y, false ) {
		this->shape.setTexture( &texture );
	}
};