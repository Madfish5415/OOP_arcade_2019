/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

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