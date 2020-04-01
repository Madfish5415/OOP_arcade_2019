/*
** EPITECH PROJECT, 2020
** engine
** File description:
** AAI.cpp
*/

#include "AAI.hpp"

using namespace engine;
using namespace system;

AAI::AAI(ecs::World& world) : ecs::ASystem(world)
{
}

AAI::~AAI() = default;