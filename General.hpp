#pragma once 

#include "SFML/Graphics.hpp"

#include <memory>
#include <string>
#include <vector>

#include "Textures.hpp"
#include "Sounds.hpp"
#include "Musics.hpp"
#include "Utils.hpp"
#include "Map.hpp"
#include "Object.hpp"


typedef unsigned int ui;

class General {
private:
	const std::shared_ptr<const Textures> allTextures = std::make_shared<Textures>( Textures() );
	const std::shared_ptr<const Sounds> allSounds = std::make_shared<Sounds>( Sounds() );

	const std::shared_ptr<Musics> allMusics = std::make_shared<Musics>( Musics() );

	sf::RenderWindow& window;
	sf::View camera;
	sf::Clock clock;

	std::vector<std::vector<std::shared_ptr<Object>>> bottomLayerObjects;
	std::vector<std::vector<std::shared_ptr<Object>>> normalLayerObjects;
	std::vector<std::vector<std::shared_ptr<Object>>> topLayerObjects;

	ui COUNTER_OF_STEPS;
	bool isMenuActive;
public: 
	General(sf::RenderWindow& window) : window(window) {
		COUNTER_OF_STEPS = 0;
		isMenuActive = true;

		// Numbers check
		camera.setSize( sf::Vector2f( 1920, 1152 ) );

		// Change it
		std::string fileToLocation = "locations/start_location.tmx";
		auto parcedInformation = parcedInfo( fileToLocation );

		auto location = std::make_shared<Map>( Map( parcedInformation ) );

		this->bottomLayerObjects = location.get()->getMapOfObjectsBottomLayer( this->getAllTextures() );
		this->normalLayerObjects = location.get()->getMapOfObjectsNormalLayer( this->getAllTextures() );
		this->topLayerObjects = location.get()->getMapOfObjectsTopLayer( this->getAllTextures() );
	}

	std::vector<std::vector<std::shared_ptr<Object>>>& getBottomLayerObjects() {
		return this->bottomLayerObjects;
	}

	std::vector<std::vector<std::shared_ptr<Object>>>& getNormalLayerObjects() {
		return this->normalLayerObjects;
	}

	std::vector<std::vector<std::shared_ptr<Object>>>& getTopLayerObjects() {
		return this->topLayerObjects;
	}

	sf::View& getCamera() {
		return this->camera;
	}

	sf::Clock& getClock() {
		return this->clock;
	}

	sf::RenderWindow& getWindow() {
		return this->window;
	}

	const std::shared_ptr<Musics>& getAllMusics() {
		return this->allMusics;
	}

	const std::shared_ptr<const Sounds>& getAllSounds() {
		return this->allSounds;
	}

	const std::shared_ptr<const Textures>& getAllTextures() {
		return this->allTextures;
	}

	bool& getIsMenuActive() {
		return this->isMenuActive;
	}

	void setIsMenuActive(bool newState) {
		this->isMenuActive = newState;
	}
};