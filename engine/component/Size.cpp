/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Size.cpp
*/

#include "Size.hpp"

using namespace engine;
using namespace component;

Size::Size(ecs::Entity& entity, int width, int height) : ecs::AComponent(entity), width(width), height(height)
{
}

Size::~Size() = default;