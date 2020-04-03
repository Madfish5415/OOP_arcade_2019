/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Transform.cpp
*/

#include "Transform.hpp"

using namespace engine;
using namespace component;

Transform::Transform(ecs::Entity& entity, type::Vector2D position, int layer) : ecs::AComponent(entity), position(position), layer(layer)
{
}

Transform::~Transform() = default;