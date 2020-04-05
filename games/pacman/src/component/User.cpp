/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#include "User.hpp"

using namespace pacman;
using namespace component;

User::User(engine::ecs::Entity& entity): AUser(entity) {}

User::~User()
{
}