#pragma once

#include <string>

typedef unsigned int ui;

namespace consts {
	const ui HEIGHT_TILE = 128;
	const ui WIDTH_TILE = 128;

	const ui HEIGHT_WINDOW = 1080;
	const ui WIDTH_WINDOW = 1920;

	const std::string AIR_SIGN = "0";

    const std::string LIGHTEN_GRASS_SIGN = "1";
	const std::string STANDART_ROCK_SIGN = "2";
	const std::string HERO_SIGN = "3";

	const std::string SMALL_DARK_TREE_TOP_SIGN = "4";
	const std::string SMALL_DARK_TREE_BOTTOM_SIGN = "5";



	const std::string STANDART_ROCK_PATH_TO_TEXTURE = "images/rocks/standart_rock.png";
	const std::string LIGHTEN_GRASS_PATH_TO_TEXTURE = "images/grass/lighten_grass.png";
	const std::string FEMALE_HERO_PATH_TO_TEXTURE = "images/heros/female_hero.png";

	const std::string SMALL_DARK_TREE_TOP_PATH_TO_TEXTURE = "images/trees/small_tree_dark/top_tree.png";
	const std::string SMALL_DARK_TREE_BOTTOM_PATH_TO_TEXTURE = "images/trees/small_tree_dark/bottom_tree.png";

	const std::string WALK_ON_GRASS_PATH_TO_SOUND = "audios/walkOnGrass.wav";

	const std::string BACKGROUND_MUSIC_PATH_TO_SOUND = "audios/backgroundMusic.mp3";

	const std::string MENU_EXIT_PATH_TO_TEXTURE = "images/text/exit.png";
	const std::string MENU_SETTINGS_PATH_TO_TEXTURE = "images/text/settings.png";
	const std::string MENU_PLAY_PATH_TO_TEXTURE = "images/text/play.png";
	const std::string MENU_BACKGROUND_PATH_TO_TEXTURE = "images/menu_background.png";
}

