#pragma once 

#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>

#include "Object.hpp"
#include "ObjectHero.hpp"
#include "Constants.hpp"
#include "Menu.hpp"
#include "Utils.hpp"

#include <iostream>

void keyboardObserver(General& G) {
    auto& normalLayer = G.getNormalLayerObjects();


    // Leave it out from this function
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Escape )) {
        G.setIsMenuActive( true );
    }

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left )) {
        if ((int)ObjectHero::getXCoord() - 1 >= 0 && normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1].get()->getIsWalkable()) {
            ui counterOfFrames = 1;
            ui leftCoordToFrame = 96;

            G.getClock().restart();
            std::uint32_t time = G.getClock().getElapsedTime().asMilliseconds();

            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                sf::IntRect( sf::Vector2i( 128, 0 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) )
            );

            
            while (time <= consts::ANIMATION_DURATION) {
                time = G.getClock().getElapsedTime().asMilliseconds();

                if (time <= consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1)) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition(
                        (ObjectHero::getXCoord() - 1) * consts::WIDTH_TILE + (consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1), ObjectHero::getYCoord() * consts::HEIGHT_TILE
                    );

                    Utils::setNewCoords( G.getCamera(), { (int)((consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1) - consts::HEIGHT_TILE), 0  } );
                }

                if (time > (consts::ANIMATION_DURATION / consts::FRAMES_COUNTER) * counterOfFrames) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                        sf::IntRect( sf::Vector2i( leftCoordToFrame, 0 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) )
                    );

                    if (leftCoordToFrame == 160) {
                        leftCoordToFrame = 96;
                    }

                    leftCoordToFrame += 32;
                    counterOfFrames++;
                }

                rerender( G );
            }
            

            // Incorrect swap of position | BUG
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( (ObjectHero::getXCoord() - 1) * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );


            // Needed operations!
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );


            // This is hardcode - GOD OBJECT
            ObjectHero::setDirectionOfView( "LEFT" );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() - 1] );
            ObjectHero::setXCoord( ObjectHero::getXCoord() - 1 );
            Utils::setNewCoords( G.getCamera() );

            rerender( G );
        }
    }

    
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right )) {
        if ((int)ObjectHero::getXCoord() + 1 < normalLayer[ObjectHero::getYCoord()].size() && normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1].get()->getIsWalkable()) {
            ui counterOfFrames = 1;
            ui leftCoordToFrame = 96;

            G.getClock().restart();
            std::uint32_t time = G.getClock().getElapsedTime().asMilliseconds();

            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                sf::IntRect( sf::Vector2i( 128, 32 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) )
            );


            while (time <= consts::ANIMATION_DURATION) {
                time = G.getClock().getElapsedTime().asMilliseconds();

                if (time <= consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1)) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition(
                        (ObjectHero::getXCoord() + 1) * consts::WIDTH_TILE - (consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1), ObjectHero::getYCoord() * consts::HEIGHT_TILE
                    );

                    Utils::setNewCoords( G.getCamera(), { -(int)((consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1) - consts::HEIGHT_TILE), 0 } );
                }

                if (time > (consts::ANIMATION_DURATION / consts::FRAMES_COUNTER) * counterOfFrames) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                        sf::IntRect( sf::Vector2i( leftCoordToFrame, 32 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) )
                    );

                    if (leftCoordToFrame == 160) {
                        leftCoordToFrame = 96;
                    }

                    leftCoordToFrame += 32;
                    counterOfFrames++;
                }

                rerender( G );
            }


            // Incorrect swap of position | BUG
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( (ObjectHero::getXCoord() + 1) * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );


            // Needed operations!
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );


            // This is hardcode - GOD OBJECT
            ObjectHero::setDirectionOfView( "LEFT" );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord() + 1] );
            ObjectHero::setXCoord( ObjectHero::getXCoord() + 1 );
            Utils::setNewCoords( G.getCamera() );

            rerender( G );
        }
    }
    

    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up )) {
        if ((int)ObjectHero::getYCoord() - 1 >= 0 && normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->getIsWalkable()) {

            ui counterOfFrames = 1;
            ui leftCoordToFrame = 0;

            G.getClock().restart();
            std::uint32_t time = G.getClock().getElapsedTime().asMilliseconds();

            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                sf::IntRect( sf::Vector2i( 32, 32 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) )
            );

            while (time <= consts::ANIMATION_DURATION) {
                time = G.getClock().getElapsedTime().asMilliseconds();

                if (time <= consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1)) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition(
                        ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() - 1) * consts::HEIGHT_TILE + (consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1)
                    );

                    Utils::setNewCoords( G.getCamera(), { 0, (int)((consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1) - consts::HEIGHT_TILE) } );
                }
                
                if (time > (consts::ANIMATION_DURATION / consts::FRAMES_COUNTER) * counterOfFrames) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                        sf::IntRect( sf::Vector2i( leftCoordToFrame, 32 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) ) 
                    );

                    if (leftCoordToFrame == 64) {
                        leftCoordToFrame = 0;
                    }

                    leftCoordToFrame += 32;
                    counterOfFrames++;
                }

                rerender( G );
            }

            // Incorrect swap of position | BUG
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() - 1) * consts::HEIGHT_TILE );
            
            // Needed operations!
            normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );


            // This is hardcode - GOD OBJECT
            ObjectHero::setDirectionOfView( "TOP" );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord() - 1][ObjectHero::getXCoord()] );
            ObjectHero::setYCoord( ObjectHero::getYCoord() - 1 );
            Utils::setNewCoords( G.getCamera() );

            rerender( G );
        }
    }

    
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down )) {
        if ((int)ObjectHero::getYCoord() + 1 < normalLayer.size() && normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()].get()->getIsWalkable()) {
            ui counterOfFrames = 1;
            ui leftCoordToFrame = 0;

            G.getClock().restart();
            std::uint32_t time = G.getClock().getElapsedTime().asMilliseconds();

            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                sf::IntRect( sf::Vector2i( 32, 0 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) )
            );

            while (time <= consts::ANIMATION_DURATION) {
                time = G.getClock().getElapsedTime().asMilliseconds();

                if (time <= consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1)) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition(
                        ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() + 1) * consts::HEIGHT_TILE - (consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1)
                    );

                    Utils::setNewCoords( G.getCamera(), { 0, -(int)((consts::HEIGHT_TILE * (consts::FRAMES_COUNTER + 1) - time) / (consts::FRAMES_COUNTER + 1) - consts::HEIGHT_TILE) });
                }

                if (time > (consts::ANIMATION_DURATION / consts::FRAMES_COUNTER) * counterOfFrames) {
                    normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewTextureRect(
                        sf::IntRect( sf::Vector2i( leftCoordToFrame, 0 ), sf::Vector2i( consts::STANDART_WIDTH_TILE, consts::STANDART_HEIGHT_TILE ) )
                    );

                    if (leftCoordToFrame == 64) {
                        leftCoordToFrame = 0;
                    }

                    leftCoordToFrame += 32;
                    counterOfFrames++;
                }

                rerender( G );
            }

            // Incorrect swap of position | BUG
            normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, (ObjectHero::getYCoord() + 1) * consts::HEIGHT_TILE );

            // Needed operations!
            normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()].get()->setNewPosition( ObjectHero::getXCoord() * consts::WIDTH_TILE, ObjectHero::getYCoord() * consts::HEIGHT_TILE );


            // This is hardcode - GOD OBJECT
            ObjectHero::setDirectionOfView( "BOTTOM" );

            std::swap( normalLayer[ObjectHero::getYCoord()][ObjectHero::getXCoord()], normalLayer[ObjectHero::getYCoord() + 1][ObjectHero::getXCoord()] );
            ObjectHero::setYCoord( ObjectHero::getYCoord() + 1 );
            Utils::setNewCoords( G.getCamera() );

            rerender( G );
        }
    }
}
