#pragma once 

#include "SFML/Graphics.hpp"

#include <memory>

#include "Textures.hpp"
#include "Constants.hpp"
#include "General.hpp"

class Menu {
private:
    int numOfMenu;

    sf::RectangleShape exitShape;
    sf::RectangleShape settingsShape;
    sf::RectangleShape playShape;
    sf::RectangleShape backgroundShape;

    // DANGER!!!
    sf::View temporaryCamera;
public:
    Menu(const std::shared_ptr<const Textures>& allTextures) {
        this->numOfMenu = 1;


        // DANGER!!!
        this->temporaryCamera.setCenter( sf::Vector2f(consts::WIDTH_WINDOW / 2, consts::HEIGHT_WINDOW / 2) );
        this->temporaryCamera.setSize( sf::Vector2f(consts::WIDTH_WINDOW, consts::HEIGHT_WINDOW) );

        this->exitShape.setSize(sf::Vector2f(84, 28)); // From github
        this->exitShape.setTexture( &allTextures.get()->getMenuExitTexture() );
        this->exitShape.setPosition( sf::Vector2f( 100, consts::HEIGHT_WINDOW - 100 ) );
        
        this->settingsShape.setSize(sf::Vector2f(168, 28)); // From github
        this->settingsShape.setTexture( &allTextures.get()->getMenuSettingsTexture() );
        this->settingsShape.setPosition( sf::Vector2f( 100, consts::HEIGHT_WINDOW - 148 ) );

        this->playShape.setSize(sf::Vector2f(88, 28)); // From github
        this->playShape.setTexture( &allTextures.get()->getMenuPlayTexture() );
        this->playShape.setPosition( sf::Vector2f( 100, consts::HEIGHT_WINDOW - 196 ) );

        this->backgroundShape.setSize(sf::Vector2f(consts::WIDTH_WINDOW, consts::HEIGHT_WINDOW));
        this->backgroundShape.setTexture( &allTextures.get()->getMenuBackgroundTexture() );
        this->backgroundShape.setPosition( sf::Vector2f( 0, 0 ) );
    }
    
    void showMenu(General& G) {
        G.getWindow().clear();

        // DANGER!!!
        G.getWindow().setView( temporaryCamera );

        playShape.setScale( sf::Vector2f( 1, 1 ) );
        settingsShape.setScale( sf::Vector2f( 1, 1 ) );
        exitShape.setScale( sf::Vector2f( 1, 1 ) );

        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up )) {
            if (numOfMenu - 1 != 0) {
                numOfMenu--;
            }
        }

        if(sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down )) {
            if (numOfMenu + 1 != 4) {
                numOfMenu++;
            }
        }

        if (numOfMenu == 1) {
            playShape.setScale( sf::Vector2f(1.2, 1.2) );
        }

        if (numOfMenu == 2) {
            settingsShape.setScale( sf::Vector2f( 1.2, 1.2 ) );
        }

        if (numOfMenu == 3) {
            exitShape.setScale( sf::Vector2f( 1.2, 1.2 ) );
        }

        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Enter )) {
            if (numOfMenu == 1) {
                G.setIsMenuActive( false );
                rerender( G );
                return;
            }
        }

        G.getWindow().draw( this->backgroundShape );

        G.getWindow().draw( this->playShape );
        G.getWindow().draw( this->settingsShape );
        G.getWindow().draw( this->exitShape );

        G.getWindow().display();
    }
};