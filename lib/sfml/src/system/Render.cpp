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
    auto entities_transform = _world.getEntities<component::Render, engine::component::Transform>();
    auto entities_size = _world.getEntities<component::Render, engine::component::Size>();

    for (auto& i : entities_transform) {
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        auto& pos = i.get().getComponent<engine::component::Transform>();
        
        render.sprite.setPosition(pos.position.x, pos.position.y);
    }
    for (auto& i : entities_size) {
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        auto& size = i.get().getComponent<engine::component::Size>();

        render.srcRect.width = size.width;
        render.srcRect.height = size.height;
        render.sprite.setScale(render.destRect.width / render.srcRect.width, 
        render.destRect.height / render.srcRect.height);
    }
}

void Render::render()
{
    auto entities = _world.getEntities<Render, engine::component::Transform>();

    if (!window.isOpen())
        return;
    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });

    window.clear();
    for (auto& i : entities) {
        auto& comp = i.get().getComponent<engine::component::ARender>();
        window.draw(dynamic_cast<component::Render&>(comp).sprite);
    }
    window.display();
}
