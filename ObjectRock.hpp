#pragma once 

#include <SFML/Graphics.hpp>

#include "Object.hpp"

typedef unsigned int ui;

class ObjectRock : public Object {
private:
	ui stepForBroke;
public:
	ObjectRock( std::string signOnMap, float x, float y, sf::Texture& texture, ui stepForBroke)
		: Object( true, false, signOnMap, x, y, false ) { 
		this->stepForBroke = stepForBroke;
		this->shape.setTexture( &texture );
	}
};