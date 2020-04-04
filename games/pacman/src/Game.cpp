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
    int walls_position[148][2] = {{0, 0}, {40, 0}, {80, 0}, {120, 0}, {160, 0}, {200, 0}, {240, 0}, {280, 0}, {320, 0}, {360, 0}, {400, 0}, {440, 0}, {480, 0}, {520, 0}, {560, 0}, {600, 0}, {640, 0}, {680, 0}, {720, 0}, {760, 0}, {800, 0}, {840, 0}, {880, 0}, {920, 0}, {960, 0}, {1000, 0}, {1040, 0}, {1080, 0}, {1120, 0}, {1160, 0}, {1200, 0}, {1240, 0}, {1280, 0}, {1320, 0}, {1360, 0}, {1400, 0}, {1440, 0}, {1480, 0}, {1520, 0}, {1560, 0}, {1600, 0}, {1640, 0}, {1680, 0}, {1720, 0}, {1760, 0}, {1800, 0}, {1840, 0}, {1880, 0},
                                    {0, 1040}, {40, 1040}, {80, 1040}, {120, 1040}, {160, 1040}, {200, 1040}, {240, 1040}, {280, 1040}, {320, 1040}, {360, 1040}, {400, 1040}, {440, 1040}, {480, 1040}, {520, 1040}, {560, 1040}, {600, 1040}, {640, 1040}, {680, 1040}, {720, 1040}, {760, 1040}, {800, 1040}, {840, 1040}, {880, 1040}, {920, 1040}, {960, 1040}, {1000, 1040}, {1040, 1040}, {1080, 1040}, {1120, 1040}, {1160, 1040}, {1200, 1040}, {1240, 1040}, {1280, 1040}, {1320, 1040}, {1360, 1040}, {1400, 1040}, {1440, 1040}, {1480, 1040}, {1520, 1040}, {1560, 1040}, {1600, 1040}, {1640, 1040}, {1680, 1040}, {1720, 1040}, {1760, 1040}, {1800, 1040}, {1840, 1040}, {1880, 1040},
                                    {0, 40}, {1880, 40}, {0, 80}, {1880, 80}, {0, 120}, {1880, 120}, {0, 160}, {1880, 160}, {0, 200}, {1880, 200}, {0, 240}, {1880, 240}, {0, 280}, {1880, 280}, {0, 320}, {1880, 320}, {0, 360}, {1880, 360}, {0, 400}, {1880, 400}, {0, 440}, {1880, 440}, {0, 480}, {1880, 480}, {0, 520}, {1880, 520}, {0, 560}, {1880, 560}, {0, 600}, {1880, 600}, {0, 640}, {1880, 640}, {0, 680}, {1880, 680}, {0, 720}, {1880, 720}, {0, 760}, {1880, 760}, {0, 800}, {1880, 800}, {0, 840}, {1880, 840}, {0, 880}, {1880, 880}, {0, 920}, {1880, 920}, {0, 960}, {1880, 960}, {0, 1000}, {1880, 1000}, {0, 1040}, {1880, 1040}};

    engine::ecs::World& main_game = this->_universe.createWorld("main_game_pacman");
    engine::ecs::Entity& my_pacman = main_game.createEntity();
    engine::ecs::Entity& red_ghost = main_game.createEntity();
    engine::ecs::Entity& blue_ghost = main_game.createEntity();
    engine::ecs::Entity& pink_ghost = main_game.createEntity();
    engine::ecs::Entity& orange_ghost = main_game.createEntity();

    std::vector<std::string> paths_wall {("assets/wall.png")};

    for (int i = 0; i < 148; i++) {
        engine::ecs::Entity& wall = main_game.createEntity();
        engine::type::Vector2D wall_position(walls_position[i][0], walls_position[i][1]);
        wall.addComponent<engine::component::ARender>(paths_wall);
        wall.addComponent<engine::component::Hitbox>(40, 40);
        wall.addComponent<engine::component::Size>(40, 40);
        wall.addComponent<engine::component::Transform>(wall_position, 1);
        main_game.addToGroup(wall, "wall");
    }

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