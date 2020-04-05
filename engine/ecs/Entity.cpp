/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

#include "../../core/src/core/Core.hpp"

using namespace engine;
using namespace ecs;

Entity::Entity(World& world) : _world(world)
{
}

Entity::~Entity() {
    for (auto& pair : _components) {
        delete& pair.second.get();
    }
    _components.clear();
}

World& Entity::getWorld() const
{
    return _world;
}

template <>
engine::component::AAudio& Entity::addComponent<engine::component::AAudio>(const std::vector<std::string>& paths) {
    std::type_index id = typeid(engine::component::AAudio);

    for (auto& c : _components) {
        if (c.first == id)
            throw std::exception();
    }

    engine::component::AAudio* component = &(_world.getUniverse().getCore().getCurrentGraphical().createAudio(*this, paths));

    std::reference_wrapper<AComponent> ref_wrap = std::ref(*component);

    _components.emplace(id, ref_wrap);

    return *component;
}

template <>
engine::component::ARender& Entity::addComponent<engine::component::ARender>(const std::vector<std::string>& paths) {
    std::type_index id = typeid(engine::component::ARender);

    for (auto& c : _components) {
        if (c.first == id)
            throw std::exception();
    }

    engine::component::ARender* component = &(_world.getUniverse().getCore().getCurrentGraphical().createRender(*this, paths));

    std::reference_wrapper<AComponent> ref_wrap = std::ref(*component);

    _components.emplace(id, ref_wrap);

    return *component;
}

template <>
engine::component::AText& Entity::addComponent<engine::component::AText>(const std::string& text, const std::vector<std::string>& paths)
{
    std::type_index id = typeid(engine::component::AText);

    for (auto& c : _components) {
        if (c.first == id)
            throw std::exception();
    }

    engine::component::AText* component = &(_world.getUniverse().getCore().getCurrentGraphical().createText(*this, text, paths));

    std::reference_wrapper<AComponent> ref_wrap = std::ref(*component);

    _components.emplace(id, ref_wrap);

    return *component;
}