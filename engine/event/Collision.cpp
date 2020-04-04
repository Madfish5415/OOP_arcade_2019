/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Collision.cpp
*/

#include "Collision.hpp"

using namespace engine;
using namespace event;

Collision::Collision(ecs::Entity& ent1, ecs::Entity& ent2) : entity1(ent1), entity2(ent2)
{
}

Collision::~Collision() = default;