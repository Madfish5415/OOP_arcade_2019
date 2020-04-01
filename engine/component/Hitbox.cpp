/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Hitbox.cpp
*/

#include "Hitbox.hpp"

using namespace engine;
using namespace component;

Hitbox::Hitbox(ecs::Entity& entity, int width, int height) : ecs::AComponent(entity), width(width), height(height) {}

Hitbox::~Hitbox() = default;