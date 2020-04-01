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

sfml::system::Render::Render(engine::ecs::World &world, sf::RenderWindow &win) : ARender(world), window(win) {

}

sfml::system::Render::~Render() = default;

void sfml::system::Render::init() {

}

void sfml::system::Render::update() {
    auto entities = _world.getEntities<sfml::component::Render, engine::component::Transform>();

    for (auto& i : entities) {
        auto& render = i.get().getComponent<sfml::component::Render>();
        auto& pos = i.get().getComponent<engine::component::Transform>();
        render.sprite.setPosition(pos.position.x, pos.position.y);
    }
}

void sfml::system::Render::render() {
    auto entities = _world.getEntities<sfml::system::Render, engine::component::Transform>();
    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });
    if (!entities.empty()) {
        auto comp1 = entities[0].get().getComponent<sfml::component::Render>();
        window.clear();
    }
    for (auto& i : entities) {
        auto comp = i.get().getComponent<sfml::component::Render>();
        window.draw(comp.sprite);
    }
    if (!entities.empty()) {
        auto comp1 = entities[0].get().getComponent<sfml::component::Render>();
        window.display();
    }
}
