/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#include <string>
#include <vector>
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
#include "../component/User.hpp"
#include "../../../engine/type/Vector2D.hpp"
#include "../../../engine/type/Animation.hpp"

using namespace pacman;

Game::Game(engine::ecs::Universe& universe): AGame(universe, "pacman") {}

Game::~Game()
{
}

void Game::init()
{
    engine::ecs::World& main_game = this->_universe.createWorld("main_game_pacman");
    engine::ecs::Entity& my_pacman = main_game.createEntity();
    engine::ecs::Entity& red_ghost = main_game.createEntity();
    engine::ecs::Entity& blue_ghost = main_game.createEntity();
    engine::ecs::Entity& pink_ghost = main_game.createEntity();
    engine::ecs::Entity& orange_ghost = main_game.createEntity();

    std::vector<std::string> paths_pacman {("assets/test_pacman.png")};
    engine::type::Vector2D pacman_velocity(1, 0);
    engine::type::Vector2D pacman_acceleration(0, 0);
    engine::type::Vector2D pacman_position(0, 0);

    std::vector<std::string> paths_red {("assets/test_red.png")};
    engine::type::Vector2D red_velocity(0, 1);
    engine::type::Vector2D red_acceleration(0, 0);
    engine::type::Vector2D red_position(200, 400);

    std::vector<std::string> paths_blue {("assets/test_blue.png")};
    engine::type::Vector2D blue_velocity(0, 1);
    engine::type::Vector2D blue_acceleration(0, 0);
    engine::type::Vector2D blue_position(500, 800);

    std::vector<std::string> paths_pink {("assets/test_pink.png")};
    engine::type::Vector2D pink_velocity(0, 1);
    engine::type::Vector2D pink_acceleration(0, 0);
    engine::type::Vector2D pink_position(1400, 300);

    std::vector<std::string> paths_orange {("assets/test_orange.png")};
    engine::type::Vector2D orange_velocity(0, 1);
    engine::type::Vector2D orange_acceleration(0, 0);
    engine::type::Vector2D orange_position(1100, 900);

    main_game.addSystem<system::AI>();
    main_game.addSystem<engine::system::ARender>();
    main_game.addSystem<system::User>();
    main_game.addSystem<engine::system::Movement>();
    main_game.addSystem<engine::system::Physics>();

    my_pacman.addComponent<engine::component::ARender>(paths_pacman);
    my_pacman.addComponent<engine::component::Hitbox>(40, 40);
    my_pacman.addComponent<engine::component::Motion>(pacman_velocity, pacman_acceleration);
    my_pacman.addComponent<engine::component::Size>(40, 40);
    my_pacman.addComponent<engine::component::Transform>(pacman_position, 1);
    my_pacman.addComponent<component::User>();
    
    red_ghost.addComponent<engine::component::ARender>(paths_red);
    red_ghost.addComponent<engine::component::Hitbox>(40, 40);
    red_ghost.addComponent<engine::component::Motion>(red_velocity, red_acceleration);
    red_ghost.addComponent<engine::component::Size>(40, 40);
    red_ghost.addComponent<engine::component::Transform>(red_position, 1);
    red_ghost.addComponent<component::AI>();

    blue_ghost.addComponent<engine::component::ARender>(paths_blue);
    blue_ghost.addComponent<engine::component::Hitbox>(40, 40);
    blue_ghost.addComponent<engine::component::Motion>(blue_velocity, blue_acceleration);
    blue_ghost.addComponent<engine::component::Size>(40, 40);
    blue_ghost.addComponent<engine::component::Transform>(blue_position, 1);
    blue_ghost.addComponent<component::AI>();

    pink_ghost.addComponent<engine::component::ARender>(paths_pink);
    pink_ghost.addComponent<engine::component::Hitbox>(40, 40);
    pink_ghost.addComponent<engine::component::Motion>(pink_velocity, pink_acceleration);
    pink_ghost.addComponent<engine::component::Size>(40, 40);
    pink_ghost.addComponent<engine::component::Transform>(pink_position, 1);
    pink_ghost.addComponent<component::AI>();

    orange_ghost.addComponent<engine::component::ARender>(paths_orange);
    orange_ghost.addComponent<engine::component::Hitbox>(40, 40);
    orange_ghost.addComponent<engine::component::Motion>(orange_velocity, orange_acceleration);
    orange_ghost.addComponent<engine::component::Size>(40, 40);
    orange_ghost.addComponent<engine::component::Transform>(orange_position, 1);
    orange_ghost.addComponent<component::AI>();

    main_game.addToGroup(my_pacman, "pacman");
    main_game.addToGroup(red_ghost, "ghost");
    main_game.addToGroup(blue_ghost, "ghost");
    main_game.addToGroup(pink_ghost, "ghost");
    main_game.addToGroup(orange_ghost, "ghost");
}

void Game::destroy()
{
    this->_universe.deleteWorld("main_game_pacman");
}