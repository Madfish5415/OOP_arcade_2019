/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Animations.cpp
*/

#include "Animations.hpp"

using namespace engine;
using namespace component;

Animations::Animations(ecs::Entity& entity, const std::map<std::string, type::Animation>& list) : ecs::AComponent(entity), list(list) {}

Animations::~Animations() = default;