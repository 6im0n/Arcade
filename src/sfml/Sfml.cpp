/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml.cpp
*/

#include "Sfml.hpp"
#include <filesystem>
#define SFML_STATIC

Arcade::Sfml::Sfml()
{
    this->_window.create(sf::VideoMode(725, 899), "Arcade");
    this->_window.setFramerateLimit(60);
}

Arcade::Sfml::~Sfml()
{
    this->_window.close();
}

bool Arcade::Sfml::isWindowOpen() const
{
    return this->_window.isOpen();
}

void Arcade::Sfml::closeWindow()
{
    this->_window.close();
}

void Arcade::Sfml::clearWindow()
{
    this->_window.clear();
}

int Arcade::Sfml::getKeyEvent() //while loop
{
    static std::map<sf::Keyboard::Key, int> keyMap = {
        {sf::Keyboard::Escape, Arcade::Keys::ESCAPE},
        {sf::Keyboard::Return, Arcade::Keys::ENTER},
        {sf::Keyboard::Space, Arcade::Keys::SPACE},
        {sf::Keyboard::Up, Arcade::Keys::UP},
        {sf::Keyboard::Down, Arcade::Keys::DOWN},
        {sf::Keyboard::Left, Arcade::Keys::LEFT},
        {sf::Keyboard::Right, Arcade::Keys::RIGHT},
        {sf::Keyboard::A, Arcade::Keys::A},
        {sf::Keyboard::B, Arcade::Keys::B},
        {sf::Keyboard::C, Arcade::Keys::C},
        {sf::Keyboard::D, Arcade::Keys::D},
        {sf::Keyboard::E, Arcade::Keys::E},
        {sf::Keyboard::F, Arcade::Keys::F},
        {sf::Keyboard::G, Arcade::Keys::G},
        {sf::Keyboard::H, Arcade::Keys::H},
        {sf::Keyboard::I, Arcade::Keys::I},
        {sf::Keyboard::J, Arcade::Keys::J},
        {sf::Keyboard::K, Arcade::Keys::K},
        {sf::Keyboard::L, Arcade::Keys::L},
        {sf::Keyboard::M, Arcade::Keys::M},
        {sf::Keyboard::N, Arcade::Keys::N},
        {sf::Keyboard::O, Arcade::Keys::O},
        {sf::Keyboard::P, Arcade::Keys::P},
        {sf::Keyboard::Q, Arcade::Keys::Q},
        {sf::Keyboard::R, Arcade::Keys::R},
        {sf::Keyboard::S, Arcade::Keys::S},
        {sf::Keyboard::T, Arcade::Keys::T},
        {sf::Keyboard::U, Arcade::Keys::U},
        {sf::Keyboard::V, Arcade::Keys::V},
        {sf::Keyboard::W, Arcade::Keys::W},
        {sf::Keyboard::X, Arcade::Keys::X},
        {sf::Keyboard::Y, Arcade::Keys::Y},
        {sf::Keyboard::Z, Arcade::Keys::Z},
        {sf::Keyboard::Num0, Arcade::Keys::ZERO},
        {sf::Keyboard::Num1, Arcade::Keys::ONE},
        {sf::Keyboard::Num2, Arcade::Keys::TWO},
        {sf::Keyboard::Num3, Arcade::Keys::THREE},
        {sf::Keyboard::Num4, Arcade::Keys::FOUR},
        {sf::Keyboard::Num5, Arcade::Keys::FIVE},
        {sf::Keyboard::Num6, Arcade::Keys::SIX},
        {sf::Keyboard::Num7, Arcade::Keys::SEVEN},
        {sf::Keyboard::Num8, Arcade::Keys::EIGHT},
        {sf::Keyboard::Num9, Arcade::Keys::NINE},
    };
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window.close();
        if (this->_event.type == sf::Event::KeyPressed) {
            if (keyMap.find(this->_event.key.code) != keyMap.end())
                return keyMap[this->_event.key.code];
        }
        if (this->_event.type == sf::Event::MouseButtonPressed) {
            if (this->_event.mouseButton.button == sf::Mouse::Left)
                return Arcade::Keys::MOUSE_LEFT;
            if (this->_event.mouseButton.button == sf::Mouse::Right)
                return Arcade::Keys::MOUSE_RIGHT;
        }
    }
    return -1;
}

void Arcade::Sfml::displayWindow()
{
    this->_window.display();
}

void Arcade::Sfml::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    this->loadTexture(entities);
    for (auto &entity : entities) {
        if (entity->getPath().empty())
            continue;
        float width = static_cast<int>(entity->getSize()[0]);
        float height = static_cast<int>(entity->getSize()[1]);
        sf::RectangleShape sprite(sf::Vector2f(width, height));
        sf::Texture texture;
        texture.loadFromFile(entity->getPath() + ".png");
        sprite.setOrigin(width / 2, height / 2);
        sprite.setTexture(&texture);
        sprite.setRotation(entity->getRotation());
        sprite.setPosition(entity->getPos()[0] * 29 + entity->getSize()[0] / 2, entity->getPos()[1] * 29 + entity->getSize()[1] / 2);
        // sprite.setSize(sf::Vector2f(entity->getSize()[0], entity->getSize()[1]));
        this->_window.draw(sprite);
    }
}

void Arcade::Sfml::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        if (text->getFontPath().empty())
            continue;
        sf::Text sfmlText;
        sf::Font font;
        font.loadFromFile(text->getFontPath() + ".ttf"); // Load the font
        sfmlText.setFont(font);
        sfmlText.setString(text->getText());
        sfmlText.setCharacterSize(text->getSize());
        sf::Color color(text->getColor()->getR(), text->getColor()->getG(), text->getColor()->getB(), text->getColor()->getA());
        sfmlText.setFillColor(color);
        sfmlText.setPosition(text->getPos()[0] * 29, text->getPos()[1] * 29);
        this->_window.draw(sfmlText);
    }
}

void Arcade::Sfml::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    for (auto &sound : sounds) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(sound->getPathSound() + ".mp3")) {
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

void Arcade::Sfml::loadTexture(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        if (entity->getPath().empty()) // Check if the path is empty or does not exist
            continue;
        if (!std::filesystem::exists(entity->getPath() + ".png")) // add the extension
            continue;
        sf::Texture texture;
        if (this->_entitiesPath.find(entity->getPath() + ".png") != this->_entitiesPath.end()) {
            this->_textures.push_back(this->_entitiesPath[entity->getPath() + ".png"]);
            continue;
        }
        _entitiesPath[entity->getPath() + ".png"] = texture;
        texture.loadFromFile(entity->getPath() + ".png");
        this->_textures.push_back(texture);
    }
}

std::pair<int, int> Arcade::Sfml::getMousePosition()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(this->_window);
    return std::make_pair<int, int>(mousePos.x / 29, mousePos.y / 29);
}

extern "C" {
    __attribute__((constructor))
    void constructor()
    {
    }

    __attribute__((destructor))
    void destructor()
    {
    }

    Arcade::IGraphic *loadGraphicInstance()
    {
        return new Arcade::Sfml();
    }
}
