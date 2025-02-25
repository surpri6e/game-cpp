#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Constants.hpp"

class Texture {
private: 
	// Grass
	sf::Texture lightenGrassTexture;

	// Heros
	sf::Texture femaleHeroTexture;

	// Rocks
	sf::Texture standartRockTexture;
public:
	Texture() {
		if (!this->lightenGrassTexture.loadFromFile( consts::LIGHTEN_GRASS_PATH_TO_TEXTURE )) {
				std::cout << consts::LIGHTEN_GRASS_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->femaleHeroTexture.loadFromFile( consts::FEMALE_HERO_PATH_TO_TEXTURE )) {
			std::cout << consts::FEMALE_HERO_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->standartRockTexture.loadFromFile( consts::STANDART_ROCK_PATH_TO_TEXTURE )) {
			std::cout << consts::STANDART_ROCK_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}
	}

	// Grass
	sf::Texture& getLightenGrassTexture() {
		return this->lightenGrassTexture;
	}

	// Heros
	sf::Texture& getFemaleHeroTexture() {
		return this->femaleHeroTexture;
	}

	// Rocks
	sf::Texture& getStandartRockTexture() {
		return this->standartRockTexture;
	}

};