#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <memory>

#include "Map.hpp"
#include "Parcer.hpp"
#include "Constants.hpp"
#include "Texture.hpp"
#include "Object.hpp"
#include "Rerender.hpp"
#include "Keyboard.hpp"


typedef unsigned int ui;


int main( int argc, char* argv[] ) {
    sf::RenderWindow window( sf::VideoMode( { consts::WIDTH_WINDOW, consts::HEIGHT_WINDOW } ), "2D Game", sf::Style::Close );
    window.setKeyRepeatEnabled( false );

    auto allTextures = std::make_shared<Texture>( Texture() );

    std::string fileToLocation = "start_location.tmx";
    auto parcedInformation = parcedInfo(fileToLocation);

    auto mapping = std::make_shared<Map>(Map( parcedInformation ));

    auto bottomLayerObjects = mapping.get()->getMapOfObjectsBottomLayer( allTextures, window );
    auto normalLayerObjects = mapping.get()->getMapOfObjectsNormalLayer( allTextures );
    auto topLayerObjects = mapping.get()->getMapOfObjectsTopLayer( allTextures );

    rerender( window, bottomLayerObjects, normalLayerObjects, topLayerObjects);

    // unsigned long long COUNTER_OF_STEPS = 0;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            keyboardObserver(window, bottomLayerObjects, normalLayerObjects, topLayerObjects);
        }
    }
}
