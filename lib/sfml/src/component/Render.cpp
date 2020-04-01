/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.cpp
*/

#include "../../../engine/component/ARender.hpp"
#include "Render.hpp"

sfml::component::Render::Render(engine::ecs::Entity &entity, const std::vector<std::string> &paths)  : engine::component::ARender(entity, paths) {
    if (texture.loadFromFile(paths[graphical::IGraphical::GRAPHIC]))
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
    angle = 0.0;
}

sfml::component::Render::~Render() = default;
