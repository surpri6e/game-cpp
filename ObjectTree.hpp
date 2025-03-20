#pragma once 

#include <SFML/Graphics.hpp>

#include "Object.hpp"

typedef unsigned int ui;

class ObjectTree : public Object {
private:
	ui stepForBroke;
public:
	ObjectTree( std::string signOnMap, float x, float y, const sf::Texture& texture, sf::IntRect rect, ui stepForBroke )
		: Object( true, false, signOnMap, x, y, false ) {
		this->stepForBroke = stepForBroke;
		this->shape.setTexture( &texture );
		this->shape.setTextureRect( rect );
	}
};