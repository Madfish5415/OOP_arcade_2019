/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include <algorithm>

#include "../../../engine/component/Transform.hpp"
#include "../../../engine/component/Size.hpp"
#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../component/Render.hpp"

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
    auto entities_transform = _world.getEntities<component::Render, engine::component::Transform>();
    auto entities_size = _world.getEntities<component::Render, engine::component::Size>();

    for (auto& i : entities_transform) {
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        auto& pos = i.get().getComponent<engine::component::Transform>();

        render.destRect.x = pos.position.x;
        render.destRect.y = pos.position.y;
    }
    for (auto& i : entities_size) {
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        auto& size = i.get().getComponent<engine::component::Size>();

        render.destRect.w = size.width;
        render.destRect.h = size.height;
    }
}

void Render::render()
{
    auto entities = _world.getEntities<Render, engine::component::Transform>();

    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });

    SDL_RenderClear(&renderer);
    for (auto& i : entities) {
        auto& comp = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        SDL_RenderCopyEx(&renderer, comp.texture, &(comp.srcRect), &(comp.destRect), comp.angle, nullptr, comp.spriteFlip);
    }
    SDL_RenderPresent(&renderer);
}
