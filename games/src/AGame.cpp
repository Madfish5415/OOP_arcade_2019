/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame
*/

#include "AGame.hpp"

AGame::AGame(engine::ecs::Universe& universe, const std::string name): _universe(universe), _name(name) {}

const std::string AGame::getName() const
{
    return _name;
}