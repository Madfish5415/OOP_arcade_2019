/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#include "Game.hpp"
#include "../../../engine/system/AAI.hpp"
#include "../../../engine/system/AAnimations.hpp"
#include "../../../engine/system/AAudio.hpp"
#include "../../../engine/system/ARender.hpp"
#include "../../../engine/system/AUser.hpp"
#include "../../../engine/system/Movement.hpp"
#include "../../../engine/system/Physics.hpp"
#include "../../../engine/component/Size.hpp"
#include "../../../engine/component/AUser.hpp"
#include "../../../engine/component/Animations.hpp"
#include "../../../engine/component/AAI.hpp"
#include "../system/AI.hpp"
#include "../system/User.hpp"
#include "../component/AI.hpp"
// #include "../component/User.hpp"

using namespace pacman;

Game::Game(engine::ecs::Universe& universe): AGame(universe, "pacman") {}

Game::~Game()
{
}

void Game::init()
{
    engine::ecs::World& main_game = this->_universe.createWorld("main_game");
    engine::ecs::Entity& my_pacman = main_game.createEntity();
    engine::ecs::Entity& red_ghost = main_game.createEntity();
    engine::ecs::Entity& blue_ghost = main_game.createEntity();
    engine::ecs::Entity& pink_ghost = main_game.createEntity();
    engine::ecs::Entity& orange_ghost = main_game.createEntity();

    main_game.addSystem<system::AI>();
    main_game.addSystem<engine::system::AAnimations>();
    main_game.addSystem<engine::system::AAudio>();
    main_game.addSystem<engine::system::ARender>();
    main_game.addSystem<system::User>();
    main_game.addSystem<engine::system::Movement>();
    main_game.addSystem<engine::system::Physics>();

    my_pacman.addComponent<engine::component::ARender>();
    my_pacman.addComponent<engine::component::Hitbox>(20, 20);
    my_pacman.addComponent<engine::component::Motion>(2, 0);
    my_pacman.addComponent<engine::component::Size>(20, 20);
    my_pacman.addComponent<engine::component::Transform>(0, 1);
    my_pacman.addComponent<engine::component::Animations>();
    my_pacman.addComponent<engine::component::AAudio>();
    my_pacman.addComponent<component::User>();
    
    red_ghost.addComponent<engine::component::ARender>();
    red_ghost.addComponent<engine::component::Hitbox>(20, 20);
    red_ghost.addComponent<engine::component::Motion>();
    red_ghost.addComponent<engine::component::Size>();
    red_ghost.addComponent<engine::component::Transform>();
    red_ghost.addComponent<engine::component::Animations>();
    red_ghost.addComponent<engine::component::AAudio>();
    red_ghost.addComponent<component::AI>();

    blue_ghost.addComponent<engine::component::ARender>();
    blue_ghost.addComponent<engine::component::Hitbox>(20, 20);
    blue_ghost.addComponent<engine::component::Motion>();
    blue_ghost.addComponent<engine::component::Size>();
    blue_ghost.addComponent<engine::component::Transform>();
    blue_ghost.addComponent<engine::component::Animations>();
    blue_ghost.addComponent<engine::component::AAudio>();
    blue_ghost.addComponent<engine::component::AAI>();

    pink_ghost.addComponent<engine::component::ARender>();
    pink_ghost.addComponent<engine::component::Hitbox>(20, 20);
    pink_ghost.addComponent<engine::component::Motion>();
    pink_ghost.addComponent<engine::component::Size>();
    pink_ghost.addComponent<engine::component::Transform>();
    pink_ghost.addComponent<engine::component::Animations>();
    pink_ghost.addComponent<engine::component::AAudio>();
    pink_ghost.addComponent<engine::component::AAI>();

    orange_ghost.addComponent<engine::component::ARender>();
    orange_ghost.addComponent<engine::component::Hitbox>(20, 20);
    orange_ghost.addComponent<engine::component::Motion>();
    orange_ghost.addComponent<engine::component::Size>();
    orange_ghost.addComponent<engine::component::Transform>();
    orange_ghost.addComponent<engine::component::Animations>();
    orange_ghost.addComponent<engine::component::AAudio>();
    orange_ghost.addComponent<engine::component::AAI>();

    main_game.addToGroup(my_pacman, "pacman");
    main_game.addToGroup(red_ghost, "ghost");
    main_game.addToGroup(blue_ghost, "ghost");
    main_game.addToGroup(pink_ghost, "ghost");
    main_game.addToGroup(orange_ghost, "ghost");
}

void Game::destroy()
{
}