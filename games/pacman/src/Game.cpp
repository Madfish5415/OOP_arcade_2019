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
                                                        {480, 790}, {520, 790}, {560, 790}, {600, 790}, {640, 790}, {680, 790}, {720, 790}, {760, 790}, {800, 790}, {840, 790}, {880, 790}, {920, 790}, {960, 790}, {1000, 790}, {1040, 790}, {1080, 790}, {1120, 790}, {1160, 790}, {1200, 790}, {1240, 790}, {1280, 790}, {1320, 790}, {1360, 790}, {1400, 790}, {1440, 790},
                                                        {480, 310}, {1440, 310}, {480, 350}, {1440, 350}, {480, 390}, {1440, 390}, {480, 430}, {1440, 430}, {480, 470}, {1440, 470}, {480, 510}, {1440, 510}, {480, 550}, {1440, 550}, {480, 590}, {1440, 590}, {480, 630}, {1440, 630}, {480, 670}, {1440, 670}, {480, 710}, {1440, 710}, {480, 750}, {1440, 750},
                                                        {560, 350}, {600, 350}, {680, 350}, {720, 350}, {800, 350}, {840, 350}, {880, 350}, {920, 350}, {1000, 350}, {1040, 350}, {1080, 350}, {1120, 350}, {1200, 350}, {1240, 350}, {1320, 350}, {1360, 350},
                                                        {560, 390}, {600, 390}, {680, 390}, {1240, 390}, {1320, 390}, {1360, 390},
                                                        {680, 430}, {760, 430}, {840, 430}, {880, 430}, {920, 430}, {1000, 430}, {1040, 430}, {1080, 430}, {1160, 430}, {1240, 430},
                                                        {520, 470}, {560, 470}, {600, 470}, {760, 470}, {840, 470}, {1080, 470}, {1160, 470}, {1320, 470}, {1360, 470}, {1400, 470},
                                                        {680, 510}, {840, 510}, {1080, 510}, {1240, 510},
                                                        {680, 550}, {760, 550}, {840, 550}, {1080, 550}, {1160, 550}, {1240, 550},
                                                        {520, 590}, {560, 590}, {600, 590}, {760, 590}, {840, 590}, {1080, 590}, {1160, 590}, {1320, 590}, {1360, 590}, {1400, 590},
                                                        {680, 630}, {840, 630}, {880, 630}, {920, 630}, {960, 630}, {1000, 630}, {1040, 630}, {1080, 630}, {1240, 630},
                                                        {560, 670}, {600, 670}, {680, 670}, {720, 670}, {760, 670}, {1160, 670}, {1200, 670}, {1240, 670}, {1320, 670}, {1360, 670},
                                                        {560, 710}, {760, 710}, {800, 710}, {840, 710}, {880, 710}, {920, 710}, {1000, 710}, {1040, 710}, {1080, 710}, {1120, 710}, {1160, 710}, {1360, 710},
                                                        {640, 750}, {680, 750}, {1240, 750}, {1280, 750}};

    // std::vector<std::pair<int, int>> pacgumsPosition = {};

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

    // const std::vector<std::string> pathsPacgums{"assets/little_dat.png", "assets/little_dat.png", "ressource_pacgums"};
    // for (size_t i = 0; i < pacgumsPosition.size(); i++) {
    //      engine::ecs::Entity& pacgum = mainGame.createEntity();
    //      pacgum.addComponent<engine::component::ARender(pathsPacgums);
    //      pacgum.addComponent<engine::component::Hitbox(10, 10);
    //      pacgum.addComponent<engine::component::Size(10, 10);
    //      pacgum.addComponent<engine::component::Transform>(engine::type::Vector2D(pacgumsPosition[i].first, pacgumsPosition[i].second), 1);
    //      mainGame.addToGroup(pacgum, "pacgum");
    // }

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