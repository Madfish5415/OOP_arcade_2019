/*
** EPITECH PROJECT, 2020
** engine
** File description:
** ASystem.cpp
*/

#include "ASystem.hpp"

using namespace engine;
using namespace ecs;

ASystem::ASystem(World& world) : _world(world)
{
}

ASystem::~ASystem() = default;

World& ASystem::getWorld() const
{
    return _world;
}
