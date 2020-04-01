/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Motion.cpp
*/

#include "Motion.hpp"

using namespace engine;
using namespace component;

Motion::Motion(ecs::Entity& entity, type::Vector2D velocity, type::Vector2D acceleration)
    : ecs::AComponent(entity), velocity(velocity), acceleration(acceleration)
{
}

Motion::~Motion() = default;