/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl.cpp
*/

#include "Sdl.hpp"
#include "includes/Keys.hpp"
#include <map>

Arcade::Sdl::Sdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    this->_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 725, 899, SDL_WINDOW_SHOWN);
    this->_renderer = SDL_CreateRenderer(this->_window, -1,
        SDL_RENDERER_ACCELERATED);
    TTF_Init();
}

Arcade::Sdl::~Sdl()
{
    TTF_Quit();
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

bool Arcade::Sdl::isWindowOpen() const
{
    return this->_window != nullptr;
}

void Arcade::Sdl::closeWindow()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void Arcade::Sdl::clearWindow()
{
    SDL_RenderClear(this->_renderer);
}

int Arcade::Sdl::getKeyEvent()
{
    SDL_Event event;
    static std::map<SDL_Keycode, int> keyMap = {
        {SDLK_ESCAPE, Arcade::Keys::ESCAPE},
        {SDLK_RETURN, Arcade::Keys::ENTER},
        {SDLK_SPACE, Arcade::Keys::SPACE},
        {SDLK_UP, Arcade::Keys::UP},
        {SDLK_DOWN, Arcade::Keys::DOWN},
        {SDLK_LEFT, Arcade::Keys::LEFT},
        {SDLK_RIGHT, Arcade::Keys::RIGHT},
        {SDLK_a, Arcade::Keys::A},
        {SDLK_b, Arcade::Keys::B},
        {SDLK_c, Arcade::Keys::C},
        {SDLK_d, Arcade::Keys::D},
        {SDLK_e, Arcade::Keys::E},
        {SDLK_f, Arcade::Keys::F},
        {SDLK_g, Arcade::Keys::G},
        {SDLK_h, Arcade::Keys::H},
        {SDLK_i, Arcade::Keys::I},
        {SDLK_j, Arcade::Keys::J},
        {SDLK_k, Arcade::Keys::K},
        {SDLK_l, Arcade::Keys::L},
        {SDLK_m, Arcade::Keys::M},
        {SDLK_n, Arcade::Keys::N},
        {SDLK_o, Arcade::Keys::O},
        {SDLK_p, Arcade::Keys::P},
        {SDLK_q, Arcade::Keys::Q},
        {SDLK_r, Arcade::Keys::R},
        {SDLK_s, Arcade::Keys::S},
        {SDLK_t, Arcade::Keys::T},
        {SDLK_u, Arcade::Keys::U},
        {SDLK_v, Arcade::Keys::V},
        {SDLK_w, Arcade::Keys::W},
        {SDLK_x, Arcade::Keys::X},
        {SDLK_y, Arcade::Keys::Y},
        {SDLK_z, Arcade::Keys::Z},
        {SDLK_0, Arcade::Keys::ZERO},
        {SDLK_1, Arcade::Keys::ONE},
        {SDLK_2, Arcade::Keys::TWO},
        {SDLK_3, Arcade::Keys::THREE},
        {SDLK_4, Arcade::Keys::FOUR},
        {SDLK_5, Arcade::Keys::FIVE},
        {SDLK_6, Arcade::Keys::SIX},
        {SDLK_7, Arcade::Keys::SEVEN},
        {SDLK_8, Arcade::Keys::EIGHT},
        {SDLK_9, Arcade::Keys::NINE},
    };

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            if (keyMap.find(event.key.keysym.sym) != keyMap.end())
                return keyMap[event.key.keysym.sym];
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            return Arcade::Keys::MOUSE_LEFT;
        }
    }
    return -1;
}

std::pair<int, int> Arcade::Sdl::getMousePosition()
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    return std::make_pair(x, y);
}

void Arcade::Sdl::displayWindow()
{
    SDL_RenderPresent(this->_renderer);
}

void Arcade::Sdl::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        int width = static_cast<int>(entity->getSize()[0]);
        int height = static_cast<int>(entity->getSize()[1]);
        SDL_Rect rect = {static_cast<int>(entity->getPos()[0] * 29 ),
            static_cast<int>(entity->getPos()[1] * 29), width , height};
        std::string imagePath = entity->getPath() + ".png";
        std::unique_ptr<SDL_Surface, void(*)(SDL_Surface*)> surface(IMG_Load(imagePath.c_str()), SDL_FreeSurface);
        std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> texture(SDL_CreateTextureFromSurface(this->_renderer, surface.get()), SDL_DestroyTexture);
        double angle = entity->getRotation();
        SDL_Point center = {width / 2, height / 2};
        SDL_RenderCopyEx(this->_renderer, texture.get(), nullptr, &rect, angle, &center, SDL_FLIP_NONE);
    }
}

void Arcade::Sdl::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        std::string textToDisplay = text->getText();
        if (textToDisplay.length() == 0 || text->getFontPath().empty())
            continue;
        std::string fontPath = text->getFontPath() + ".ttf";
        SDL_Color color = {0, 0, 0, 0};
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> _font(TTF_OpenFont(fontPath.c_str(), text->getSize()), TTF_CloseFont);
        if (text->getColor()->getR() == -1);
        else {
            color = {static_cast<Uint8>(text->getColor()->getR()),
                static_cast<Uint8>(text->getColor()->getG()),
                static_cast<Uint8>(text->getColor()->getB()),
                static_cast<Uint8>(text->getColor()->getA())};
        }
        SDL_Surface *surface = TTF_RenderText_Solid(_font.get(), textToDisplay.c_str(), color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_Rect rect = {static_cast<int>(text->getPos()[0] * 29),
            static_cast<int>(text->getPos()[1] * 29), surface->w, surface->h};
        SDL_RenderCopy(this->_renderer, texture, nullptr, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}
void Arcade::Sdl::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void)sounds;
}

extern "C"
{
    __attribute__((constructor))
    void constructor()
    {
    }
    __attribute__((destructor))
    void destructor()
    {
    }
    Arcade::Sdl *loadGraphicInstance()
    {
        return new Arcade::Sdl();
    }
}
