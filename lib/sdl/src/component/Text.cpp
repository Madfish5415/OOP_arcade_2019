/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

using namespace sdl;
using namespace component;

Text::Text(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths, SDL_Renderer *renderer)
    : AText(entity, text, paths)
{
    if ((font = TTF_OpenFont(paths[graphical::GRAPHIC].c_str(), 50)) == nullptr)
        throw std::exception();

    color.r = 255;
    color.g = 255;
    color.b = 255;

    if ((surface = TTF_RenderText_Solid(font, text.c_str(), color)) == nullptr)
        throw std::exception();

    if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == nullptr)
        throw std::exception();

    spriteFlip = SDL_FLIP_NONE;

    angle = 0.0;
}

Text::~Text()
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}