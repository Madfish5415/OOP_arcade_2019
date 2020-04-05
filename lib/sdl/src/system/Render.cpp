/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include <algorithm>
#include <iostream>

#include "../../../engine/component/Transform.hpp"
#include "../../../engine/component/Size.hpp"
#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../component/Render.hpp"
#include "../component/Text.hpp"

using namespace sdl;
using namespace system;

Render::Render(engine::ecs::World& world,  SDL_Renderer *rdr) : ARender(world), renderer(*rdr)
{
}

Render::~Render() = default;

void Render::init()
{
}

void Render::update()
{

    auto entities_transform = _world.getEntities<engine::component::Transform>();
    auto entities_size = _world.getEntities<engine::component::Size>();

    for (auto& i : entities_transform) {
        if (i.get().hasComponents<engine::component::ARender>()) {
            auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
            auto& pos = i.get().getComponent<engine::component::Transform>();

            render.destRect.x = pos.position.x;
            render.destRect.y = pos.position.y;
        }
        if (i.get().hasComponents<engine::component::AText>()) {
            auto& text = dynamic_cast<component::Text&>(i.get().getComponent<engine::component::AText>());
            auto& pos = i.get().getComponent<engine::component::Transform>();

            text.destRect.x = pos.position.x;
            text.destRect.y = pos.position.y;
        }
    }

    for (auto& i : entities_size) {
        if (i.get().hasComponents<engine::component::ARender>()) {
            auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
            auto& size = i.get().getComponent<engine::component::Size>();

            render.destRect.w = size.width;
            render.destRect.h = size.height;
        }
        if (i.get().hasComponents<engine::component::AText>()) {
            auto& text = dynamic_cast<component::Text&>(i.get().getComponent<engine::component::AText>());
            auto& size = i.get().getComponent<engine::component::Size>();


            text.destRect.w = int(float(size.width) / 3);
            text.destRect.h = int(float(size.height) / 2);

            text.destRect.x = text.destRect.x + ((size.width / 2) - (text.destRect.w / 2));
            text.destRect.y = text.destRect.y + ((size.height / 2) - (text.destRect.h / 2));
        }
    }
}

void Render::render()
{
    auto entities = _world.getEntities<engine::component::Transform>();

    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });

    SDL_RenderClear(&renderer);
    for (auto& i : entities) {
        if (i.get().hasComponents<engine::component::ARender>()) {
            auto& comp = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
            SDL_RenderCopyEx(&renderer, comp.texture, &(comp.srcRect), &(comp.destRect), comp.angle, nullptr, comp.spriteFlip);
        }
        if (i.get().hasComponents<engine::component::AText>()) {
            auto& text = dynamic_cast<component::Text&>(i.get().getComponent<engine::component::AText>());

            SDL_RenderCopyEx(&renderer, text.texture, nullptr, &(text.destRect), text.angle, nullptr, text.spriteFlip);
        }
    }
    SDL_RenderPresent(&renderer);
}
