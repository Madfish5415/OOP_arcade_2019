/*
** EPITECH PROJECT, 2020
** engine
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

using namespace engine;
using namespace ecs;

AComponent::AComponent(Entity& entity) : _entity(entity)
{
}

AComponent::~AComponent() = default;

Entity& AComponent::getEntity() const
{
    return _entity;
}
