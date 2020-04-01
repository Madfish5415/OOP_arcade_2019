/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.cpp
*/

#include <algorithm>
#include "Render.hpp"
#include "../component/Render.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/component/Transform.hpp"

sfml::system::Render::Render(engine::ecs::World &world) : ARender(world) {

}

void sfml::system::Render::init() {

}

void sfml::system::Render::update() {
    auto& entities = _world.getEntities<sfml::component::Render, engine::ecs::Transform>();

    for (auto& i : entities) {
        auto render = i.getComponent<sfml::component::Render>;
        auto pos = i.getComponent<engine::ecs::Transform>;
        render.sprite.setPosition(pos.position[0], pos.position[1]);
    }
}

void sfml::system::Render::render() {
    auto entities = _world.getEntities<sfml::system::Render, engine::component::Transform>();
    std::sort(entities.begin(), entities.end(), [](const Entity& lhs, const Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });
    if (!entities.empty()) {
        auto comp1 = entities[0].getComponent<ecs::sfml::component::Render>;
        dynamic_cast<component::Render>(comp1).window.clear()
    }
    for (auto& i : entities) {
        auto comp = i.getComponent<sfml::component::Render>;
        comp.window.draw(comp.sprite);
    }
    if (!entities.empty()) {
        auto comp1 = entities[0].getComponent<ecs::sfml::component::Render>;
        comp1.window.display();
    }
}
