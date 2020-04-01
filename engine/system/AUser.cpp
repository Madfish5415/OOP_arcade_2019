/*
** EPITECH PROJECT, 2020
** engine
** File description:
** AUser.cpp
*/

#include "AUser.hpp"

using namespace engine;
using namespace system;

AUser::AUser(ecs::World& world) : ecs::ASystem(world)
{
}

AUser::~AUser() = default;