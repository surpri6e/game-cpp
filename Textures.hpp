#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Constants.hpp"

class Textures {
private: 
	// Grass
	sf::Texture lightenGrassTexture;

	// Heros
	sf::Texture femaleHeroTexture;
	sf::Texture maleHeroTexture;

	// Rocks
	sf::Texture standartRockTexture;

	// Trees 
	sf::Texture smallDarkTreeTexture;

	// Menu
	sf::Texture menuExitTexture;
	sf::Texture menuSettingsTexture;
	sf::Texture menuPlayTexture;
	sf::Texture menuBackgroundTexture;
public:
	Textures() {
		if (!this->lightenGrassTexture.loadFromFile( consts::LIGHTEN_GRASS_PATH_TO_TEXTURE )) {
				std::cout << consts::LIGHTEN_GRASS_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->femaleHeroTexture.loadFromFile( consts::FEMALE_HERO_PATH_TO_TEXTURE )) {
			std::cout << consts::FEMALE_HERO_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->maleHeroTexture.loadFromFile( consts::MALE_HERO_PATH_TO_TEXTURE )) {
			std::cout << consts::MALE_HERO_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->standartRockTexture.loadFromFile( consts::STANDART_ROCK_PATH_TO_TEXTURE )) {
			std::cout << consts::STANDART_ROCK_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->smallDarkTreeTexture.loadFromFile( consts::SMALL_DARK_TREE_PATH_TO_TEXTURE )) {
			std::cout << consts::SMALL_DARK_TREE_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->menuExitTexture.loadFromFile( consts::MENU_EXIT_PATH_TO_TEXTURE )) {
			std::cout << consts::MENU_EXIT_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->menuSettingsTexture.loadFromFile( consts::MENU_SETTINGS_PATH_TO_TEXTURE )) {
			std::cout << consts::MENU_SETTINGS_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->menuPlayTexture.loadFromFile( consts::MENU_PLAY_PATH_TO_TEXTURE )) {
			std::cout << consts::MENU_PLAY_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}

		if (!this->menuBackgroundTexture.loadFromFile( consts::MENU_BACKGROUND_PATH_TO_TEXTURE )) {
			std::cout << consts::MENU_BACKGROUND_PATH_TO_TEXTURE << " is incorrect path!" << std::endl;
		}
	}

	// Grass
	const sf::Texture& getLightenGrassTexture() const {
		return this->lightenGrassTexture;
	}

	// Heros
	const sf::Texture& getFemaleHeroTexture() const {
		return this->femaleHeroTexture;
	}

	const sf::Texture& getMaleHeroTexture() const {
		return this->maleHeroTexture;
	}

	// Rocks
	const sf::Texture& getStandartRockTexture() const {
		return this->standartRockTexture;
	}

	// Trees
	const sf::Texture& getSmallDarkTreeTexture() const {
		return this->smallDarkTreeTexture;
	}

	// Menu
	const sf::Texture& getMenuExitTexture() const {
		return this->menuExitTexture;
	}

	const sf::Texture& getMenuSettingsTexture() const {
		return this->menuSettingsTexture;
	}

	const sf::Texture& getMenuPlayTexture() const {
		return this->menuPlayTexture;
	}

	const sf::Texture& getMenuBackgroundTexture() const {
		return this->menuBackgroundTexture;
	}
};