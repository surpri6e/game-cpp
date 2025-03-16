#pragma once 

#include <SFML/Audio.hpp>
#include <iostream>

#include "Constants.hpp"

class Sounds {
private: 
	sf::SoundBuffer walkOnGrassBuffer;
public:
	Sounds() {
		if (!this->walkOnGrassBuffer.loadFromFile( consts::WALK_ON_GRASS_PATH_TO_SOUND )) {
			std::cout << consts::WALK_ON_GRASS_PATH_TO_SOUND << " is incorrect path!" << std::endl;
		}
	}

	// Memory and production problems
	const sf::Sound getWalkOnGrass() const {
		return sf::Sound( walkOnGrassBuffer );
	};
};