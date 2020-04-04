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
    font = TTF_OpenFont(paths[graphical::GRAPHIC].c_str(), 25);
    surface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    spriteFlip = SDL_FLIP_NONE;

    angle = 0.0;

    color.r = 255;
    color.g = 255;
    color.b = 255;
}

Text::~Text()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}