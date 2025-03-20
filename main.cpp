#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <memory>

#include "Map.hpp"
#include "Parcer.hpp"
#include "Constants.hpp"
#include "Rerender.hpp"
#include "Keyboard.hpp"
#include "General.hpp"
#include "Utils.hpp"
#include "Menu.hpp"

typedef unsigned int ui;

int main( int argc, char* argv[] ) {
    sf::RenderWindow window( sf::VideoMode( { consts::WIDTH_WINDOW, consts::HEIGHT_WINDOW } ), "2D Game", sf::State::Fullscreen );

   // window.setKeyRepeatEnabled( false );

    General G(window);
    Utils::setNewCoords( G.getCamera() );

    std::int32_t time = G.getClock().getElapsedTime().asMilliseconds();

    Menu menu( G.getAllTextures() );

    G.getAllMusics().get()->getBackgroundMusic().play();
    G.getAllMusics().get()->getBackgroundMusic().setVolume(1.f);
    G.getAllMusics().get()->getBackgroundMusic().setLooping(true);

    // Добавить звук хотьбы по траве
    // Настроить меню и игру
    // Сделать прозрачность у дерева и надпись патча в менюшке

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            time = G.getClock().getElapsedTime().asMilliseconds();

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
  
            if(!G.getIsMenuActive()) {
                if (time > consts::STEP_DELAY) {
                    keyboardObserver( G );
                }
            }  

            if (G.getIsMenuActive()) {
                menu.showMenu( G );
            }
        } 
    }
}
