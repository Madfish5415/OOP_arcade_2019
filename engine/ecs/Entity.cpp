/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

#include "../../core/src/Core.hpp"

using namespace engine;
using namespace ecs;

Entity::Entity(World& world) : _world(world)
{
}

Entity::~Entity() {
    for (auto& pair : _components) {
        delete &pair.second.get();
    }
    _components.clear();
}

World& Entity::getWorld() const
{
    return _world;
}

template <>
component::AAudio& Entity::addComponent<component::AAudio>(const std::vector<std::string>& paths) {
    std::type_index id = typeid(component::AAudio);

    for (auto &c : _components) {
        if (c.first == id)
            throw std::exception();
    }

    component::AAudio* component = _world.getUniverse().getCore().getCurrentGraphical().createAudio(*this, paths);

    std::reference_wrapper<AComponent> ref_wrap = std::ref(*component);

    _components.emplace(id, ref_wrap);

    return *component;
}

template <>
component::ARender& Entity::addComponent<component::ARender>(const std::vector<std::string>& paths) {
    std::type_index id = typeid(component::ARender);

    for (auto &c : _components) {
        if (c.first == id)
            throw std::exception();
    }

    component::ARender* component = _world.getUniverse().getCore().getCurrentGraphical().createRender(*this, paths);

    std::reference_wrapper<AComponent> ref_wrap = std::ref(*component);

    _components.emplace(id, ref_wrap);

    return *component;
}