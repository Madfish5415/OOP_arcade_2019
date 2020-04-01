/*
** EPITECH PROJECT, 2020
** engine
** File description:
** AUser.cpp
*/

#include "AUser.hpp"

using namespace engine;
using namespace component;

AUser::AUser(ecs::Entity& entity) : AComponent(entity) {}

AUser::~AUser() = default;