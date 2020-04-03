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
    auto entities_transform = _world.getEntities<engine::component::ARender, engine::component::Transform>();
    auto entities_size = _world.getEntities<engine::component::ARender, engine::component::Size>();

    for (auto& i : entities_transform) {
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        auto& pos = i.get().getComponent<engine::component::Transform>();
        
        render.sprite.setPosition(pos.position.x, pos.position.y);
    }
    for (auto& i : entities_size) {
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        auto& size = i.get().getComponent<engine::component::Size>();

        render.destRect.width = size.width;
        render.destRect.height = size.height;
        std::cout << "Size : " << size.width << " " << size.height << std::endl;
        std::cout << "Size 1: " << render.srcRect.width << " " << render.srcRect.height << std::endl;
        std::cout << "Size 2 : " << float(render.destRect.width) / float(render.srcRect.width) << " " << float(render.destRect.height) / float(render.srcRect.height) << std::endl;
        render.sprite.setScale(float(render.destRect.width) / float(render.srcRect.width),
                               float(render.destRect.height) / float(render.srcRect.height));
    }
}

void Render::render()
{
    auto entities = _world.getEntities<engine::component::ARender, engine::component::Transform>();

    if (!window.isOpen())
        return;
    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });

    window.clear();
    for (auto& i : entities) {
        auto& transform = i.get().getComponent<engine::component::Transform>();
        std::cout << transform.position.x << " " << transform.position.y << std::endl;
        auto& comp = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        window.draw(comp.sprite);
    }
    window.display();
}
