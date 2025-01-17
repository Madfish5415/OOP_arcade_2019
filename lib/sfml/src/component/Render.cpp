/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include "../../../engine/component/ARender.hpp"

#include <iostream>

using namespace sfml;
using namespace component;

Render::Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths)
    : engine::component::ARender(entity, paths)
{
    if (texture.loadFromFile(paths[graphical::GRAPHIC]))
        sprite.setTexture(texture);

    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.width = texture.getSize().x;
    srcRect.height = texture.getSize().y;

    destRect.left = 0;
    destRect.top = 0;
    destRect.width = texture.getSize().x;
    destRect.height = texture.getSize().y;

    spriteFlip = NONE;

    sprite.setTextureRect(srcRect);

    angle = 0.0;
}

Render::~Render() = default;
