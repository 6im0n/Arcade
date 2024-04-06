/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl.cpp
*/

#include "Sdl.hpp"
#include "includes/Keys.hpp"

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

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return Arcade::Keys::ESCAPE;
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                return Arcade::Keys::ESCAPE;
            if (event.key.keysym.sym == SDLK_RETURN)
                return Arcade::Keys::ENTER;
            if (event.key.keysym.sym == SDLK_SPACE)
                return Arcade::Keys::SPACE;
            if (event.key.keysym.sym == SDLK_UP)
                return Arcade::Keys::UP;
            if (event.key.keysym.sym == SDLK_DOWN)
                return Arcade::Keys::DOWN;
            if (event.key.keysym.sym == SDLK_RIGHT)
                return Arcade::Keys::RIGHT;
            if (event.key.keysym.sym == SDLK_LEFT)
                return Arcade::Keys::LEFT;
            if (event.key.keysym.sym == SDLK_a)
                return Arcade::Keys::A;
            if (event.key.keysym.sym == SDLK_b)
                return Arcade::Keys::B;
            if (event.key.keysym.sym == SDLK_c)
                return Arcade::Keys::C;
            if (event.key.keysym.sym == SDLK_d)
                return Arcade::Keys::D;
            if (event.key.keysym.sym == SDLK_e)
                return Arcade::Keys::E;
            if (event.key.keysym.sym == SDLK_f)
                return Arcade::Keys::F;
            if (event.key.keysym.sym == SDLK_g)
                return Arcade::Keys::G;
            if (event.key.keysym.sym == SDLK_h)
                return Arcade::Keys::H;
            if (event.key.keysym.sym == SDLK_i)
                return Arcade::Keys::I;
            if (event.key.keysym.sym == SDLK_j)
                return Arcade::Keys::J;
            if (event.key.keysym.sym == SDLK_k)
                return Arcade::Keys::K;
            if (event.key.keysym.sym == SDLK_l)
                return Arcade::Keys::L;
            if (event.key.keysym.sym == SDLK_m)
                return Arcade::Keys::M;
            if (event.key.keysym.sym == SDLK_n)
                return Arcade::Keys::N;
            if (event.key.keysym.sym == SDLK_o)
                return Arcade::Keys::O;
            if (event.key.keysym.sym == SDLK_p)
                return Arcade::Keys::P;
            if (event.key.keysym.sym == SDLK_q)
                return Arcade::Keys::Q;
            if (event.key.keysym.sym == SDLK_r)
                return Arcade::Keys::R;
            if (event.key.keysym.sym == SDLK_s)
                return Arcade::Keys::S;
            if (event.key.keysym.sym == SDLK_t)
                return Arcade::Keys::T;
            if (event.key.keysym.sym == SDLK_u)
                return Arcade::Keys::U;
            if (event.key.keysym.sym == SDLK_v)
                return Arcade::Keys::V;
            if (event.key.keysym.sym == SDLK_w)
                return Arcade::Keys::W;
            if (event.key.keysym.sym == SDLK_x)
                return Arcade::Keys::X;
            if (event.key.keysym.sym == SDLK_y)
                return Arcade::Keys::Y;
            if (event.key.keysym.sym == SDLK_z)
                return Arcade::Keys::Z;
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
