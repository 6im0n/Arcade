/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml.cpp
*/

#include "Sfml.hpp"
#define SFML_STATIC

Arcade::Sfml::Sfml()
{
    this->_window.create(sf::VideoMode(800, 600), "Arcade");
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
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window.close();
        if (this->_event.type == sf::Event::KeyPressed) {
            if (this->_event.key.code == sf::Keyboard::A)
                return Arcade::Keys::A;
            if (this->_event.key.code == sf::Keyboard::B)
                return Arcade::Keys::B;
            if (this->_event.key.code == sf::Keyboard::C)
                return Arcade::Keys::C;
            if (this->_event.key.code == sf::Keyboard::D)
                return Arcade::Keys::D;
            if (this->_event.key.code == sf::Keyboard::E)
                return Arcade::Keys::E;
            if (this->_event.key.code == sf::Keyboard::F)
                return Arcade::Keys::F;
            if (this->_event.key.code == sf::Keyboard::G)
                return Arcade::Keys::G;
            if (this->_event.key.code == sf::Keyboard::H)
                return Arcade::Keys::H;
            if (this->_event.key.code == sf::Keyboard::I)
                return Arcade::Keys::I;
            if (this->_event.key.code == sf::Keyboard::J)
                return Arcade::Keys::J;
            if (this->_event.key.code == sf::Keyboard::K)
                return Arcade::Keys::K;
            if (this->_event.key.code == sf::Keyboard::L)
                return Arcade::Keys::L;
            if (this->_event.key.code == sf::Keyboard::M)
                return Arcade::Keys::M;
            if (this->_event.key.code == sf::Keyboard::N)
                return Arcade::Keys::N;
            if (this->_event.key.code == sf::Keyboard::O)
                return Arcade::Keys::O;
            if (this->_event.key.code == sf::Keyboard::P)
                return Arcade::Keys::P;
            if (this->_event.key.code == sf::Keyboard::Q)
                return Arcade::Keys::Q;
            if (this->_event.key.code == sf::Keyboard::R)
                return Arcade::Keys::R;
            if (this->_event.key.code == sf::Keyboard::S)
                return Arcade::Keys::S;
            if (this->_event.key.code == sf::Keyboard::T)
                return Arcade::Keys::T;
            if (this->_event.key.code == sf::Keyboard::U)
                return Arcade::Keys::U;
            if (this->_event.key.code == sf::Keyboard::V)
                return Arcade::Keys::V;
            if (this->_event.key.code == sf::Keyboard::W)
                return Arcade::Keys::W;
            if (this->_event.key.code == sf::Keyboard::X)
                return Arcade::Keys::X;
            if (this->_event.key.code == sf::Keyboard::Y)
                return Arcade::Keys::Y;
            if (this->_event.key.code == sf::Keyboard::Z)
                return Arcade::Keys::Z;
            if (this->_event.key.code == sf::Keyboard::Escape)
                return Arcade::Keys::ESCAPE;
            if (this->_event.key.code == sf::Keyboard::Tab)
                return Arcade::Keys::TAB;
            if (this->_event.key.code == sf::Keyboard::LShift || this->_event.key.code == sf::Keyboard::RShift)
                return Arcade::Keys::SHIFT;
            if (this->_event.key.code == sf::Keyboard::LControl || this->_event.key.code == sf::Keyboard::RControl)
                return Arcade::Keys::CONTROL;
            if (this->_event.key.code == sf::Keyboard::Space)
                return Arcade::Keys::SPACE;
            if (this->_event.key.code == sf::Keyboard::Enter)
                return Arcade::Keys::ENTER;
            if (this->_event.key.code == sf::Keyboard::BackSpace)
                return Arcade::Keys::BACKSPACE;
            if (this->_event.key.code == sf::Keyboard::Up)
                return Arcade::Keys::UP;
            if (this->_event.key.code == sf::Keyboard::Down)
                return Arcade::Keys::DOWN;
            if (this->_event.key.code == sf::Keyboard::Left)
                return Arcade::Keys::LEFT;
            if (this->_event.key.code == sf::Keyboard::Right)
                return Arcade::Keys::RIGHT;
            if (this->_event.key.code == sf::Keyboard::Num0 || this->_event.key.code == sf::Keyboard::Numpad0)
                return Arcade::Keys::ZERO;
            if (this->_event.key.code == sf::Keyboard::Num1 || this->_event.key.code == sf::Keyboard::Numpad1)
                return Arcade::Keys::ONE;
            if (this->_event.key.code == sf::Keyboard::Num2 || this->_event.key.code == sf::Keyboard::Numpad2)
                return Arcade::Keys::TWO;
            if (this->_event.key.code == sf::Keyboard::Num3 || this->_event.key.code == sf::Keyboard::Numpad3)
                return Arcade::Keys::THREE;
            if (this->_event.key.code == sf::Keyboard::Num4 || this->_event.key.code == sf::Keyboard::Numpad4)
                return Arcade::Keys::FOUR;
            if (this->_event.key.code == sf::Keyboard::Num5 || this->_event.key.code == sf::Keyboard::Numpad5)
                return Arcade::Keys::FIVE;
            if (this->_event.key.code == sf::Keyboard::Num6 || this->_event.key.code == sf::Keyboard::Numpad6)
                return Arcade::Keys::SIX;
            if (this->_event.key.code == sf::Keyboard::Num7 || this->_event.key.code == sf::Keyboard::Numpad7)
                return Arcade::Keys::SEVEN;
            if (this->_event.key.code == sf::Keyboard::Num8 || this->_event.key.code == sf::Keyboard::Numpad8)
                return Arcade::Keys::EIGHT;
            if (this->_event.key.code == sf::Keyboard::Num9 || this->_event.key.code == sf::Keyboard::Numpad9)
                return Arcade::Keys::NINE;
        }
    }
    return 0;
}

void Arcade::Sfml::displayWindow()
{
    this->_window.display();
}

void Arcade::Sfml::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
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

void Arcade::Sfml::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    (void)texts;
    // for (auto &text : texts) {
    //     sf::Text sfmlText;
    //     sf::Font font;
    //     font.loadFromFile(text->getFontPath());
    //     sfmlText.setFont(font);
    //     sfmlText.setString(text->getText());
    //     sfmlText.setCharacterSize(text->getSize());
    //     sfmlText.setFillColor(sf::Color::Black);
    //     sfmlText.setPosition(text->getPos()[0], text->getPos()[1]);
    //     this->_window.draw(sfmlText);
    // }
}

void Arcade::Sfml::playSound(std::vector<std::shared_ptr<ISound>> sounds)
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

void Arcade::Sfml::loadTexture(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        sf::Texture texture;
        texture.loadFromFile(entity->getPath());
        this->_textures.push_back(texture);
    }
}

// void Arcade::Sfml::loadSound(std::vector<std::shared_ptr<IEntity>> entities)
// {
//     (void)entities;
// }

// void Arcade::Sfml::loadFont(std::vector<std::shared_ptr<IEntity>> entities)
// {
//     (void)entities;
// }

// void Arcade::Sfml::loadText(std::shared_ptr<IText> text)
// {
//     (void)text;
// }

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
