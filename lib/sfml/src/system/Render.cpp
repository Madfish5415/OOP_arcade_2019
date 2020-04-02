/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include <algorithm>

#include "../../../engine/component/Transform.hpp"
#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../component/Render.hpp"

using namespace sfml;
using namespace system;

Render::Render(engine::ecs::World& world, sf::RenderWindow& win) : ARender(world), window(win)
{
}

Render::~Render() = default;

void Render::init()
{
}

void Render::update()
{
    auto entities = _world.getEntities<component::Render, engine::component::Transform>();

    for (auto& i : entities) {
        auto& render = i.get().getComponent<component::Render>();
        auto& pos = i.get().getComponent<engine::component::Transform>();

        render.sprite.setPosition(pos.position.x, pos.position.y);
    }
}

void Render::render()
{
    auto entities = _world.getEntities<Render, engine::component::Transform>();

    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });

    if (!entities.empty()) {
        auto comp1 = entities[0].get().getComponent<component::Render>();
        window.clear();
    }

    for (auto& i : entities) {
        auto comp = i.get().getComponent<component::Render>();
        window.draw(comp.sprite);
    }

    if (!entities.empty()) {
        auto comp1 = entities[0].get().getComponent<component::Render>();
        window.display();
    }
}
