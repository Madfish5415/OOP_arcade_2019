/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(Universe& universe): AGame(universe, "pacman") {}

Game::~Game()
{
}

void Game::init()
{
    engine::ecs::World game = this->_universe.createWorld("main_game");
    engine::ecs::Entity pacman = game.createEntity();
    engine::ecs::Entity red_ghost = game.createEntity();
    engine::ecs::Entity blue_ghost = game.createEntity();
    engine::ecs::Entity pink_ghost = game.createEntity();
    engine::ecs::Entity orange_ghost = game.createEntity();

    game.addToGroup(pacman, "pacman");
    game.addToGroup(red_ghost, "ghost");
    game.addToGroup(blue_ghost, "ghost");
    game.addToGroup(pink_ghost, "ghost");
    game.addToGroup(orange_ghost, "ghost");
}

void Game::destroy()
{
}