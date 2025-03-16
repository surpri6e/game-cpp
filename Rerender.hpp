#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "General.hpp"

void rerender( General& G ) {
    G.getWindow().clear(sf::Color(27, 58, 10));

    G.getWindow().setView( G.getCamera() );

    for (auto i = 0; i < G.getBottomLayerObjects().size(); i++) {
        for (auto k = 0; k < G.getBottomLayerObjects()[i].size(); k++) {
            G.getBottomLayerObjects()[i][k].get()->toDraw( G.getWindow() );
        }
    }


    for (auto i = 0; i < G.getNormalLayerObjects().size(); i++) {
        for (auto k = 0; k < G.getNormalLayerObjects()[i].size(); k++) {
            G.getNormalLayerObjects()[i][k].get()->toDraw( G.getWindow() );
        }
    }
    
    
    for (auto i = 0; i < G.getTopLayerObjects().size(); i++) {
        for (auto k = 0; k < G.getTopLayerObjects()[i].size(); k++) {
            G.getTopLayerObjects()[i][k].get()->toDraw( G.getWindow() );
        }
    }
    
    G.getWindow().display();
}


