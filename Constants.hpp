#pragma once

#include <string>

typedef unsigned int ui;

namespace consts {
	const ui HEIGHT_TILE = 32;
	const ui WIDTH_TILE = 32;

	//const ui HEIGHT_TILE = 128;
	//const ui WIDTH_TILE = 128;

	const ui HEIGHT_WINDOW = 1080;
	const ui WIDTH_WINDOW = 1920;

	const std::string AIR_SIGN = "0";

    const std::string LIGHTEN_GRASS_SIGN = "1";
	const std::string STANDART_ROCK_SIGN = "2";
	const std::string HERO_SIGN = "3";



	const std::string STANDART_ROCK_PATH_TO_TEXTURE = "images/rocks/standart_rock.png";
	const std::string LIGHTEN_GRASS_PATH_TO_TEXTURE = "images/grass/lighten_grass.png";
	const std::string FEMALE_HERO_PATH_TO_TEXTURE = "images/heros/female_hero.png";
}

