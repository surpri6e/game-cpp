#pragma once 

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Object.hpp"

void rerender( sf::RenderWindow& window, 
    std::vector<std::vector<std::shared_ptr<Object>>>& bottomLayer,
    std::vector<std::vector<std::shared_ptr<Object>>>& normalLayer,
    std::vector<std::vector<std::shared_ptr<Object>>>& topLayer ) {


    for (auto i = 0; i < bottomLayer.size(); i++) {
        for (auto k = 0; k < bottomLayer[i].size(); k++) {
            bottomLayer[i][k].get()->toDraw(window);

        }
    }


    for (auto i = 0; i < normalLayer.size(); i++) {
        for (auto k = 0; k < normalLayer[i].size(); k++) {
            normalLayer[i][k].get()->toDraw( window );
        }
    }
    
    
    for (auto i = 0; i < topLayer.size(); i++) {
        for (auto k = 0; k < topLayer[i].size(); k++) {
            topLayer[i][k].get()->toDraw( window );
        }
    }

    window.display();
}