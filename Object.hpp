#pragma once 

#include <SFML/Graphics.hpp>
#include <string>

#include "Constants.hpp"

typedef unsigned int ui;

class Object {
protected:
	bool isBreakable;
	bool isWalkable; 
	std::string signOnMap;
	sf::RectangleShape shape;
public:
	Object( bool isBreakable, bool isWalkable, std::string signOnMap, float x, float y, bool isTransparent = false ) {
		this->isWalkable = isWalkable;
		this->isBreakable = isBreakable;
		this->signOnMap = signOnMap;

		sf::RectangleShape newShape( sf::Vector2f( (float)consts::HEIGHT_TILE, (float)consts::WIDTH_TILE ) );
		newShape.setPosition( sf::Vector2f( x, y ) );
		if (isTransparent) {
			newShape.setFillColor( sf::Color::Transparent );
		}
		this->shape = newShape;
	}

	void setNewTextureRect( sf::IntRect rect ) {
		this->shape.setTextureRect( rect );
	}

	void setNewPosition( float x, float y ) {
		this->shape.setPosition( sf::Vector2f( x, y ) );
	}

	void toDraw(sf::RenderWindow& window) {
		window.draw(this->shape);
	}

	const std::string& getSignOnMap() {
		return this->signOnMap;
	}

	bool getIsWalkable() {
		return this->isWalkable;
	}
};




