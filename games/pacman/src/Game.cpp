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
    engine::ecs::World& main_game = this->_universe.createWorld("main_game");
    engine::ecs::Entity& pacman = main_game.createEntity();
    engine::ecs::Entity& red_ghost = main_game.createEntity();
    engine::ecs::Entity& blue_ghost = main_game.createEntity();
    engine::ecs::Entity& pink_ghost = main_game.createEntity();
    engine::ecs::Entity& orange_ghost = main_game.createEntity();

    main_game.addSystem<engine::system::AI>();
    main_game.addSystem<engine::system::Animations>();
    main_game.addSystem<engine::system::Audio>();
    main_game.addSystem<engine::system::Render>();
    main_game.addSystem<engine::system::User>();
    main_game.addSystem<engine::system::Movement>();
    main_game.addSystem<engine::system::Physics>();

    pacman.addComponent<engine::component::Render>();
    pacman.addComponent<engine::component::Hitbox>(20, 20);
    pacman.addComponent<engine::component::Motion>();
    pacman.addComponent<engine::component::Size>();
    pacman.addComponent<engine::component::Transform>();
    pacman.addComponent<engine::component::Animation>();
    pacman.addComponent<engine::component::Audio>();
    pacman.addComponent<engine::component::User>();

    red_ghost.addComponent<engine::component::Render>();
    red_ghost.addComponent<engine::component::Hitbox>(20, 20);
    red_ghost.addComponent<engine::component::Motion>();
    red_ghost.addComponent<engine::component::Size>();
    red_ghost.addComponent<engine::component::Transform>();
    red_ghost.addComponent<engine::component::Animation>();
    red_ghost.addComponent<engine::component::Audio>();
    red_ghost.addComponent<engine::component::AI>();

    blue_ghost.addComponent<engine::component::Render>();
    blue_ghost.addComponent<engine::component::Hitbox>(20, 20);
    blue_ghost.addComponent<engine::component::Motion>();
    blue_ghost.addComponent<engine::component::Size>();
    blue_ghost.addComponent<engine::component::Transform>();
    blue_ghost.addComponent<engine::component::Animation>();
    blue_ghost.addComponent<engine::component::Audio>();
    blue_ghost.addComponent<engine::component::AI>();

    pink_ghost.addComponent<engine::component::Render>();
    pink_ghost.addComponent<engine::component::Hitbox>(20, 20);
    pink_ghost.addComponent<engine::component::Motion>();
    pink_ghost.addComponent<engine::component::Size>();
    pink_ghost.addComponent<engine::component::Transform>();
    pink_ghost.addComponent<engine::component::Animation>();
    pink_ghost.addComponent<engine::component::Audio>();
    pink_ghost.addComponent<engine::component::AI>();

    orange_ghost.addComponent<engine::component::Render>();
    orange_ghost.addComponent<engine::component::Hitbox>(20, 20);
    orange_ghost.addComponent<engine::component::Motion>();
    orange_ghost.addComponent<engine::component::Size>();
    orange_ghost.addComponent<engine::component::Transform>();
    orange_ghost.addComponent<engine::component::Animation>();
    orange_ghost.addComponent<engine::component::Audio>();
    orange_ghost.addComponent<engine::component::AI>();

    main_game.addToGroup(pacman, "pacman");
    main_game.addToGroup(red_ghost, "ghost");
    main_game.addToGroup(blue_ghost, "ghost");
    main_game.addToGroup(pink_ghost, "ghost");
    main_game.addToGroup(orange_ghost, "ghost");
}

void Game::destroy()
{
}