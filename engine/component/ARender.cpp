/*
** EPITECH PROJECT, 2020
** engine
** File description:
** ARender.cpp
*/

#include "ARender.hpp"

using namespace engine;
using namespace component;

ARender::ARender(ecs::Entity& entity, const std::vector<std::string>& paths) : ecs::AComponent(entity), paths(paths) {}

ARender::~ARender() = default;