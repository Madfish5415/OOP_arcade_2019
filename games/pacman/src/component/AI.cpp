/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#include "AI.hpp"

using namespace pacman;
using namespace component;

AI::AI(engine::ecs::Entity& entity): AAI(entity) {
    oldVelocity.x = 0;
    oldVelocity.y = 0;
}

AI::~AI() = default;