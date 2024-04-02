/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml.cpp
*/

#include "Sfml.hpp"
#define SFML_STATIC

Sfml::Sfml()
{
    this->_window.create(sf::VideoMode(800, 600), "Arcade");
    this->_window.setFramerateLimit(60);
}

Sfml::~Sfml()
{
    this->_window.close();
}

bool Sfml::isWindowOpen() const
{
    return this->_window.isOpen();
}

void Sfml::closeWindow()
{
    this->_window.close();
}

void Sfml::clearWindow()
{
    this->_window.clear();
}

int Sfml::getKeyEvent() //while loop
{
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window.close();
    }
    return 0;
}

void Sfml::displayWindow()
{
    this->_window.display();
}

void Sfml::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    this->loadTexture(entities);
    for (auto &entity : entities) {
        sf::Sprite sprite;
        sprite.setTexture(this->_textures[0]);
        sprite.setPosition(entity->getPos()[0], entity->getPos()[1]);
        this->_window.draw(sprite);
    }
    (void)entities;
}

void Sfml::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        sf::Text sfmlText;
        sf::Font font;
        font.loadFromFile(text->getFontPath());
        sfmlText.setFont(font);
        sfmlText.setString(text->getText());
        sfmlText.setCharacterSize(text->getSize());
        sfmlText.setFillColor(sf::Color::White);
        sfmlText.setPosition(text->getPos()[0], text->getPos()[1]);
        this->_window.draw(sfmlText);
    }
}

void Sfml::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    for (auto &sound : sounds) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(sound->getPathSound())) {
            std::cerr << "Error loading sound file" << std::endl;
            continue;
        }
        sf::Sound sfmlSound;
        sfmlSound.setBuffer(buffer);
        sfmlSound.play();
        while (sfmlSound.getStatus() == sf::Sound::Playing) {
            sf::sleep(sf::milliseconds(100));
        }
    }
}

void Sfml::loadTexture(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        sf::Texture texture;
        texture.loadFromFile(entity->getPath());
        this->_textures.push_back(texture);
    }
}

// void Sfml::loadSound(std::vector<std::shared_ptr<IEntity>> entities)
// {
//     (void)entities;
// }

// void Sfml::loadFont(std::vector<std::shared_ptr<IEntity>> entities)
// {
//     (void)entities;
// }

// void Sfml::loadText(std::shared_ptr<IText> text)
// {
//     (void)text;
// }

extern "C" {
    IGraphic *loadGraphicInstance()
    {
        return new Sfml();
    }
}
