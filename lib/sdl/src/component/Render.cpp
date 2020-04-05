/*
** EPITECH PROJECT, 2020
** sdl
** File description:
** Render.cpp
*/

#include <SDL2/SDL_image.h>
#include "Render.hpp"


using namespace sdl;
using namespace component;

Render::Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths, SDL_Renderer *renderer)
    : engine::component::ARender(entity, paths)
{
    surface = IMG_Load(paths[graphical::GRAPHIC].c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);


    srcRect.x = 0;
    srcRect.y = 0;
    SDL_QueryTexture(texture, nullptr, nullptr, &(srcRect.w), &(srcRect.h));


    destRect.x = 0;
    destRect.y = 0;
    SDL_QueryTexture(texture, nullptr, nullptr, &(destRect.w), &(destRect.h));

    spriteFlip = SDL_FLIP_NONE;

    angle = 0.0;
}

Render::~Render()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
