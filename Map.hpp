#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Parcer.hpp"
#include "Object.hpp"
#include "Constants.hpp"
#include "Textures.hpp"

#include "ObjectRock.hpp"
#include "ObjectGrass.hpp"
#include "ObjectHero.hpp"
#include "ObjectTree.hpp"

typedef unsigned int ui;

class Map {
private:
    InfoAboutLayer topLayer;
    std::vector<std::vector<std::string>> topLayerMap;

    InfoAboutLayer normalLayer;
    std::vector<std::vector<std::string>> normalLayerMap;

    InfoAboutLayer bottomLayer;
    std::vector<std::vector<std::string>> bottomLayerMap;
public:
    Map(const std::vector<InfoAboutLayer>&  arr) {
        this->bottomLayer = arr[0];
        this->normalLayer = arr[1];
        this->topLayer = arr[2];

        this->bottomLayerMap= this->bottomLayer.getMap();
        this->normalLayerMap = this->normalLayer.getMap();
        this->topLayerMap = this->topLayer.getMap();
    }
    
    
    std::vector<std::vector<std::shared_ptr<Object>>> getMapOfObjectsTopLayer( const std::shared_ptr<const Textures>& allTextures ) {
        std::vector<std::vector<std::shared_ptr<Object>>> result = {};

        float positionX = 0;
        float positionY = 0;

        for (auto i = 0; i < this->topLayer.getHeight(); i++) {
            std::vector<std::shared_ptr<Object>> arrLine = {};
            positionX = 0;

            for (auto k = 0; k < this->topLayer.getWidth(); k++) {
                if (this->topLayerMap[i][k] == consts::AIR_SIGN) {
                    arrLine.push_back( std::make_shared<Object>( Object( true, true, consts::AIR_SIGN, positionX, positionY, true ) ) );
                }

                // Top layer - can i break it? How it need working
                if (this->topLayerMap[i][k] == consts::SMALL_DARK_TREE_TOP_SIGN) {
                    arrLine.push_back( 
                        std::make_shared<Object>( 
                            ObjectTree( 
                                consts::SMALL_DARK_TREE_TOP_SIGN, 
                                positionX, 
                                positionY, 
                                allTextures.get()->getSmallDarkTreeTexture(), 
                                sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE)), 
                                5 
                            ) 
                        ) 
                    );
                }

                positionX += consts::WIDTH_TILE;
            }

            result.push_back( arrLine );
            positionY += consts::HEIGHT_TILE;
        }

        return result;
    }
    
  

    std::vector<std::vector<std::shared_ptr<Object>>> getMapOfObjectsNormalLayer( const std::shared_ptr<const Textures>& allTextures ) {
        std::vector<std::vector<std::shared_ptr<Object>>> result = {};

        float positionX = 0;
        float positionY = 0;

        for (auto i = 0; i < this->normalLayer.getHeight(); i++) {
            std::vector<std::shared_ptr<Object>> arrLine = {};
            positionX = 0;

            for (auto k = 0; k < this->normalLayer.getWidth(); k++) {
                if (this->normalLayerMap[i][k] == consts::AIR_SIGN) {
                    arrLine.push_back( std::make_shared<Object>( Object( true, true, consts::AIR_SIGN, positionX, positionY, true ) ) );
                }

                // Top layer - can i break it? How it need working
                if (this->normalLayerMap[i][k] == consts::STANDART_ROCK_SIGN) {
                    arrLine.push_back( std::make_shared<Object>( ObjectRock( consts::STANDART_ROCK_SIGN, positionX, positionY, allTextures.get()->getStandartRockTexture(), 10)));
                }

                if (this->normalLayerMap[i][k] == consts::HERO_SIGN) {
                    arrLine.push_back( std::make_shared<Object>( 
                        ObjectHero( consts::HERO_SIGN, positionX, positionY, 100, allTextures.get()->getMaleHeroTexture() ) 
                    ));
                }

                if (this->normalLayerMap[i][k] == consts::SMALL_DARK_TREE_BOTTOM_SIGN) {
                    arrLine.push_back( 
                        std::make_shared<Object>( 
                            ObjectTree( 
                                consts::SMALL_DARK_TREE_BOTTOM_SIGN, 
                                positionX, 
                                positionY, 
                                allTextures.get()->getSmallDarkTreeTexture(),
                                sf::IntRect(sf::Vector2i(0, 32), sf::Vector2i(consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE)),
                                5 
                            ) 
                        ) 
                    );
                }

                positionX += consts::WIDTH_TILE;
            }

            result.push_back( arrLine );
            positionY += consts::HEIGHT_TILE;
        }

        return result;
    }
    

    std::vector<std::vector<std::shared_ptr<Object>>> getMapOfObjectsBottomLayer( const std::shared_ptr<const Textures>& allTextures ) {
        std::vector<std::vector<std::shared_ptr<Object>>> result = {};

        float positionX = 0;
        float positionY = 0;

        for (auto i = 0; i < this->bottomLayer.getHeight(); i++) {
            std::vector<std::shared_ptr<Object>> arrLine = {};
            positionX = 0;

            for (auto k = 0; k < this->bottomLayer.getWidth(); k++) {
                if (this->bottomLayerMap[i][k] == consts::LIGHTEN_GRASS_SIGN) {
                    arrLine.push_back( std::make_shared<Object>( ObjectGrass( consts::LIGHTEN_GRASS_SIGN, positionX, positionY, allTextures.get()->getLightenGrassTexture()  ) ) );
                }

                positionX += consts::WIDTH_TILE;
            }

            result.push_back( arrLine );
            positionY += consts::HEIGHT_TILE;
        }

        return result;
    }

};