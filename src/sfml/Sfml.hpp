/*
** EPITECH PROJECT, 2024
** Arcade_Proj
** File description:
** Sfml
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Interfaces/IGraphic.hpp"
#include "includes/Keys.hpp"

namespace Arcade {
    class Sfml: public Arcade::IGraphic {
        public:
            Sfml();
            ~Sfml() override;

            //Window
            bool isWindowOpen() const override;
            void closeWindow() override;
            void clearWindow() override;

            //Event
            int getKeyEvent() override;
            std::pair<int, int> getMousePosition() override;

            //Display
            void displayWindow() override;
            void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
            void displayText(std::vector<std::shared_ptr<IText>> texts) override;
            void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;

        private:
            sf::RenderWindow _window;
            sf::Event _event;
            std::vector<sf::Texture> _textures;
            std::vector<sf::Sprite> _sprites;
            std::vector<sf::Text> _texts;
            std::vector<sf::SoundBuffer> _soundBuffers;
            std::vector<sf::Sound> _sounds;
            std::map<std::string, sf::Texture> _entitiesPath;

            void loadTexture(std::vector<std::shared_ptr<IEntity>> entities);
            void loadSound(std::vector<std::shared_ptr<IEntity>> entities);
            void loadFont(std::vector<std::shared_ptr<IEntity>> entities);
            void loadText(std::shared_ptr<IText> text);
    };
}
