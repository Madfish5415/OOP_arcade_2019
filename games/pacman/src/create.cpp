/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** create.cpp
*/

#include "game/Game.hpp"

extern "C" game::IGame* create(engine::ecs::Universe* universe)
{
    return new pacman::Game(*universe);
}