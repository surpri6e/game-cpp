#pragma once 

#include <SFML/Audio.hpp>
#include <iostream>

#include "Constants.hpp"

class Musics {
private:
	sf::Music backgroundMusic;
public:
	Musics() {
		if (!this->backgroundMusic.openFromFile( consts::BACKGROUND_MUSIC_PATH_TO_SOUND )) {
			std::cout << consts::BACKGROUND_MUSIC_PATH_TO_SOUND << " is incorrect path!" << std::endl;
		}
	}

	// Memory and production problems
	sf::Music& getBackgroundMusic() {
		return this->backgroundMusic;
	};
};