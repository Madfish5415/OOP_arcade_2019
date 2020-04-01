/*
** EPITECH PROJECT, 2020
** engine
** File description:
** AAudio.cpp
*/

#include "AAudio.hpp"

using namespace engine;
using namespace component;

AAudio::AAudio(ecs::Entity& entity, const std::vector<std::string>& paths) : ecs::AComponent(entity), paths(paths) {}

AAudio::~AAudio() = default;