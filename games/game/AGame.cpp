/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame
*/

#include "AGame.hpp"

using namespace game;

AGame::AGame(engine::ecs::Universe& universe, const std::string& name): _universe(universe), _name(name) {}

AGame::~AGame() = default;

std::string AGame::getName()
{
    return _name;
}