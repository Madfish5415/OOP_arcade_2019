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
#include "../../../engine/type/Vector2D.hpp"
#include "../../../engine/type/Animation.hpp"
#include "../system/AI.hpp"
#include "../system/User.hpp"
#include "../component/AI.hpp"
#include "../component/User.hpp"

using namespace pacman;

Game::Game(engine::ecs::Universe& universe): AGame(universe, "pacman") {}

Game::~Game()
{
}

void Game::init()
{
    std::vector<std::pair<int, int>> wallsPosition = {{480, 270}, {520, 270}, {560, 270}, {600, 270}, {640, 270}, {680, 270}, {720, 270}, {760, 270}, {800, 270}, {840, 270}, {880, 270}, {920, 270}, {960, 270}, {1000, 270}, {1040, 0}, {1080, 270}, {1120, 270}, {1160, 270}, {1200, 270}, {1240, 270}, {1280, 270}, {1320, 270}, {1360, 270}, {1400, 270}, {1440, 270},
                                                        {480, 830}, {520, 830}, {560, 830}, {600, 830}, {640, 830}, {680, 830}, {720, 830}, {760, 830}, {800, 830}, {840, 830}, {880, 830}, {920, 830}, {960, 830}, {1000, 830}, {1040, 830}, {1080, 830}, {1120, 830}, {1160, 830}, {1200, 830}, {1240, 830}, {1280, 830}, {1320, 830}, {1360, 830}, {1400, 830}, {1440, 830},
                                                        {480, 270}, {1440, 270}, {480, 310}, {1440, 310}, {480, 350}, {1440, 350}, {480, 390}, {1440, 390}, {480, 430}, {1440, 430}, {480, 470}, {1440, 470}, {480, 510}, {1440, 510}, {480, 550}, {1440, 550}, {480, 590}, {1440, 590}, {480, 630}, {1440, 630}, {480, 670}, {1440, 670}, {480, 710}, {1440, 710}, {480, 750}, {1440, 750}, {480, 790}, {1440, 790}, {480, 830}, {1440, 830}};

    engine::ecs::World& mainGame = this->_universe.createWorld("mainGamePacman");
    mainGame.addSystem<system::AI>();
    mainGame.addSystem<engine::system::ARender>();
    mainGame.addSystem<system::User>();
    mainGame.addSystem<engine::system::Movement>();
    mainGame.addSystem<engine::system::Physics>();
    
    engine::ecs::Entity& pacmanEntity = mainGame.createEntity();
    const std::vector<std::string> pathsPacman{"assets/test_pacman.png", "assets/test_pacman.png", "ressource_pacman"};
    pacmanEntity.addComponent<engine::component::ARender>(pathsPacman);
    pacmanEntity.addComponent<engine::component::Hitbox>(40, 40);
    pacmanEntity.addComponent<engine::component::Motion>(engine::type::Vector2D(1, 0), engine::type::Vector2D(0, 0));
    pacmanEntity.addComponent<engine::component::Size>(40, 40);
    pacmanEntity.addComponent<engine::component::Transform>(engine::type::Vector2D(40, 40), 3);
    pacmanEntity.addComponent<component::User>();

    engine::ecs::Entity& redGhost = mainGame.createEntity();
    const std::vector<std::string> pathsRed{"assets/test_red.png", "assets/test_red.png", "ressource_red_ghost"};
    redGhost.addComponent<engine::component::ARender>(pathsRed);
    redGhost.addComponent<engine::component::Hitbox>(40, 40);
    redGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    redGhost.addComponent<engine::component::Size>(40, 40);
    redGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(200, 400), 2);
    redGhost.addComponent<component::AI>();

    engine::ecs::Entity& blueGhost = mainGame.createEntity();
    const std::vector<std::string> pathsBlue{"assets/test_blue.png", "assets/test_blue.png", "ressource_blue_ghost"};
    blueGhost.addComponent<engine::component::ARender>(pathsBlue);
    blueGhost.addComponent<engine::component::Hitbox>(40, 40);
    blueGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    blueGhost.addComponent<engine::component::Size>(40, 40);
    blueGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(500, 800), 2);
    blueGhost.addComponent<component::AI>();

    engine::ecs::Entity& pinkGhost = mainGame.createEntity();
    const std::vector<std::string> pathsPink{"assets/test_pink.png", "assets/test_pink.png", "ressource_pink_ghost"};
    pinkGhost.addComponent<engine::component::ARender>(pathsPink);
    pinkGhost.addComponent<engine::component::Hitbox>(40, 40);
    pinkGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    pinkGhost.addComponent<engine::component::Size>(40, 40);
    pinkGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1400, 300), 2);
    pinkGhost.addComponent<component::AI>();

    engine::ecs::Entity& orangeGhost = mainGame.createEntity();
    const std::vector<std::string> pathsOrange{"assets/test_orange.png", "assets/test_orange.png", "ressource_orange_ghost"};
    orangeGhost.addComponent<engine::component::ARender>(pathsOrange);
    orangeGhost.addComponent<engine::component::Hitbox>(40, 40);
    orangeGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    orangeGhost.addComponent<engine::component::Size>(40, 40);
    orangeGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1100, 900), 2);
    orangeGhost.addComponent<component::AI>();

    const std::vector<std::string> pathsWall{"assets/wall.png", "assets/wall.png", "ressource_wall"};
    for (size_t i = 0; i < wallsPosition.size(); i++) {
        engine::ecs::Entity& wall = mainGame.createEntity();
        wall.addComponent<engine::component::ARender>(pathsWall);
        wall.addComponent<engine::component::Hitbox>(40, 40);
        wall.addComponent<engine::component::Size>(40, 40);
        wall.addComponent<engine::component::Transform>(engine::type::Vector2D(wallsPosition[i].first, wallsPosition[i].second), 1);
        mainGame.addToGroup(wall, "wall");
    }

    mainGame.addToGroup(pacmanEntity, "pacman");
    mainGame.addToGroup(redGhost, "ghost");
    mainGame.addToGroup(blueGhost, "ghost");
    mainGame.addToGroup(pinkGhost, "ghost");
    mainGame.addToGroup(orangeGhost, "ghost");
}

void Game::destroy()
{
    this->_universe.deleteWorld("mainGamePacman");
}