/*
** EPITECH PROJECT, 2020
** engine
** File description:
** ARender.cpp
*/

#include "ARender.hpp"

using namespace engine;
using namespace system;

ARender::ARender(ecs::World& world) : ecs::ASystem(world)
{
}

ARender::~ARender() = default;