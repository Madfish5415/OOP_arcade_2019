/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.cpp
*/

#include "User.hpp"

menu::component::User::User(engine::ecs::Entity& entity) : AUser(entity)
{
    observedGroups = {"graph", "game"};
    currentObserved = std::make_pair("graph", 0);
}

menu::component::User::~User() = default;
