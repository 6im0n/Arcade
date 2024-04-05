/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl.cpp
*/

#include "sdl.hpp"

Arcade::Sdl::Sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(84);
    }
    this->_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 725, 899, SDL_WINDOW_SHOWN);
    if (this->_window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->_renderer == nullptr) {
        SDL_DestroyWindow(this->_window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }
}

bool Arcade::Sdl::isWindowOpen() const
{
    return true;
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
            if (event.key.keysym.sym == SDLK_ESCAPE)
                return Arcade::Keys::ESCAPE;
            if (event.key.keysym.sym == SDLK_TAB)
                return Arcade::Keys::TAB;
        }
    }
    return -1;
}

void Arcade::Sdl::displayWindow()
{
    SDL_RenderPresent(this->_renderer);
}

void Arcade::Sdl::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        SDL_Rect rect = {(int)entity->getPos().at(0), (int)entity->getPos().at(1), (int)entity->getSize().at(0), (int)entity->getSize().at(1)};
        SDL_SetRenderDrawColor(this->_renderer, entity->getColor()->getR(), entity->getColor()->getG(), entity->getColor()->getB(), entity->getColor()->getA());
        SDL_RenderFillRect(this->_renderer, &rect);
    }
}

void Arcade::Sdl::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        TTF_Font *font = TTF_OpenFont("assets/arial.ttf", 50);
        SDL_Color color = {(Uint8)text->getColor()->getR(), (Uint8)text->getColor()->getG(), (Uint8)text->getColor()->getB(), (Uint8)text->getColor()->getA()};
        SDL_Surface *surface = TTF_RenderText_Solid(font, text->getText().c_str(), color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL_Rect rect = {(int)text->getPos().at(0), (int)text->getPos().at(1), surface->w, surface->h};

        SDL_RenderCopy(this->_renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        TTF_CloseFont(font);
    }
}

void Arcade::Sdl::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void)sounds;
}

std::pair<int, int> Arcade::Sdl::getMousePosition()
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    return std::make_pair(x, y);
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
