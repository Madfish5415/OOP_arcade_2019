/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#include "Game.hpp"

#include <string>
#include <vector>
#include <iostream>

#include "../../../../engine/component/AAI.hpp"
#include "../../../../engine/component/AUser.hpp"
#include "../../../../engine/component/Animations.hpp"
#include "../../../../engine/component/Size.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/system/AAI.hpp"
#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/system/AAudio.hpp"
#include "../../../../engine/system/ARender.hpp"
#include "../../../../engine/system/AUser.hpp"
#include "../../../../engine/system/Movement.hpp"
#include "../../../../engine/system/Physics.hpp"
#include "../../../../engine/type/Animation.hpp"
#include "../../../../engine/type/Vector2D.hpp"
#include "../component/AI.hpp"
#include "../component/User.hpp"
#include "../system/AI.hpp"
#include "../system/User.hpp"

using namespace pacman;

Game::Game(engine::ecs::Universe& universe) : AGame(universe, "pacman")
{
}

Game::~Game()
{
}

void Game::init()
{
    std::vector<std::pair<int, int>> wallsPosition = {{480, 270}, {520, 270}, {560, 270}, {600, 270}, {640, 270}, {680, 270}, {720, 270}, {760, 270}, {800, 270}, {840, 270}, {880, 270}, {920, 270}, {960, 270}, {1000, 270}, {1040, 270}, {1080, 270}, {1120, 270}, {1160, 270}, {1200, 270}, {1240, 270}, {1280, 270}, {1320, 270}, {1360, 270}, {1400, 270}, {1440, 270},
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

    std::vector<std::pair<int, int>> pacgumsPosition = {{495, 325}, {535, 325}, {615, 325}, {655, 325}, {695, 325}, {735, 325}, {775, 325}, {815, 325}, {855, 325}, {895, 325}, {935, 325}, {975, 325}, {1015, 325}, {1055, 325}, {1095, 325}, {1135, 325}, {1175, 325}, {1215, 325}, {1255, 325}, {1295, 325}, {1335, 325}, {1375, 325},
                                                        {495, 365}, {615, 365}, {735, 365}, {935, 365}, {1135, 365}, {1255, 365}, {1375, 365},
                                                        {495, 405}, {615, 405}, {695, 405}, {735, 405}, {775, 405}, {815, 405}, {855, 405}, {895, 405}, {935, 405}, {975, 405}, {1015, 405}, {1055, 405}, {1095, 405}, {1135, 405}, {1255, 405}, {1375, 405},
                                                        {495, 445}, {535, 445}, {575, 445}, {615, 445}, {695, 445}, {775, 445}, {935, 445}, {1095, 445}, {1175, 445}, {1255, 445}, {1295, 445}, {1335, 445}, {1375, 445},
                                                        {615, 485}, {655, 485}, {695, 485}, {775, 485}, {1095, 485}, {1175, 485}, {1215, 485}, {1255, 485},
                                                        {615, 525}, {695, 525}, {735, 525}, {775, 525}, {1095, 525}, {1135, 525}, {1175, 525}, {1255, 525},
                                                        {615, 565}, {695, 565}, {775, 565}, {1095, 565}, {1175, 565}, {1255, 565},
                                                        {615, 605}, {695, 605}, {775, 605}, {1095, 605}, {1175, 605}, {1215, 605}, {1255, 605},
                                                        {495, 645}, {535, 645}, {575, 645}, {615, 645}, {695, 645}, {735, 645}, {775, 645}, {1095, 645}, {1135, 645}, {1175, 645}, {1255, 645}, {1295, 645}, {1335, 645}, {1375, 645},
                                                        {495, 685}, {615, 685}, {775, 685}, {815, 685}, {855, 685}, {895, 685}, {935, 685}, {975, 685}, {1015, 685}, {1055, 685}, {1095, 685}, {1255, 685}, {1375, 685},
                                                        {495, 725}, {575, 725}, {615, 725}, {655, 725}, {695, 725}, {935, 725}, {1175, 725}, {1215, 725}, {1255, 725}, {1295, 725}, {1375, 725},
                                                        {495, 765}, {535, 765}, {575, 765}, {695, 765}, {735, 765}, {775, 765}, {815, 765}, {855, 765}, {895, 765}, {935, 765}, {975, 765}, {1015, 765}, {1055, 765}, {1095, 765}, {1135, 765}, {1175, 765}, {1335, 765}, {1375, 765}};

    std::vector<std::pair<int, int>> pacgumsSpecialPosition = {{575, 325}, {1175, 405}, {655, 605}, {1295, 765}};

    engine::ecs::World& mainGame = this->_universe.createWorld("mainGamePacman");
    mainGame.addSystem<system::AI>();
    mainGame.addSystem<engine::system::ARender>();
    mainGame.addSystem<system::User>();
    mainGame.addSystem<engine::system::Movement>();
    mainGame.addSystem<engine::system::Physics>();

    engine::ecs::Entity& pacmanEntity = mainGame.createEntity();
    const std::vector<std::string> pathsPacman {"assets/test_pacman.png", "assets/test_pacman.png", "ressource_pacman"};
    pacmanEntity.addComponent<engine::component::ARender>(pathsPacman);
    pacmanEntity.addComponent<engine::component::Hitbox>(40, 40);
    pacmanEntity.addComponent<engine::component::Motion>(engine::type::Vector2D(1, 0), engine::type::Vector2D(0, 0));
    pacmanEntity.addComponent<engine::component::Size>(40, 40);
    pacmanEntity.addComponent<engine::component::Transform>(engine::type::Vector2D(960, 670), 3);
    pacmanEntity.addComponent<component::User>();

    engine::ecs::Entity& redGhost = mainGame.createEntity();
    const std::vector<std::string> pathsRed {"assets/test_red.png", "assets/test_red.png", "ressource_red_ghost"};
    redGhost.addComponent<engine::component::ARender>(pathsRed);
    redGhost.addComponent<engine::component::Hitbox>(40, 40);
    redGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    redGhost.addComponent<engine::component::Size>(40, 40);
    redGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(920, 470), 2);
    redGhost.addComponent<component::AI>();

    engine::ecs::Entity& blueGhost = mainGame.createEntity();
    const std::vector<std::string> pathsBlue {"assets/test_blue.png", "assets/test_blue.png", "ressource_blue_ghost"};
    blueGhost.addComponent<engine::component::ARender>(pathsBlue);
    blueGhost.addComponent<engine::component::Hitbox>(40, 40);
    blueGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    blueGhost.addComponent<engine::component::Size>(40, 40);
    blueGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1040, 470), 2);
    blueGhost.addComponent<component::AI>();

    engine::ecs::Entity& pinkGhost = mainGame.createEntity();
    const std::vector<std::string> pathsPink {"assets/test_pink.png", "assets/test_pink.png", "ressource_pink_ghost"};
    pinkGhost.addComponent<engine::component::ARender>(pathsPink);
    pinkGhost.addComponent<engine::component::Hitbox>(40, 40);
    pinkGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    pinkGhost.addComponent<engine::component::Size>(40, 40);
    pinkGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(880, 550), 2);
    pinkGhost.addComponent<component::AI>();

    engine::ecs::Entity& orangeGhost = mainGame.createEntity();
    const std::vector<std::string> pathsOrange {"assets/test_orange.png", "assets/test_orange.png", "ressource_orange_ghost"};
    orangeGhost.addComponent<engine::component::ARender>(pathsOrange);
    orangeGhost.addComponent<engine::component::Hitbox>(40, 40);
    orangeGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    orangeGhost.addComponent<engine::component::Size>(40, 40);
    orangeGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1000, 550), 2);
    orangeGhost.addComponent<component::AI>();

    const std::vector<std::string> pathsWall {"assets/wall.png", "assets/wall.png", "ressource_wall"};
    for (size_t i = 0; i < wallsPosition.size(); i++) {
        engine::ecs::Entity& wall = mainGame.createEntity();
        wall.addComponent<engine::component::ARender>(pathsWall);
        wall.addComponent<engine::component::Hitbox>(40, 40);
        wall.addComponent<engine::component::Size>(40, 40);
        wall.addComponent<engine::component::Transform>(engine::type::Vector2D(wallsPosition[i].first, wallsPosition[i].second), 1);
        mainGame.addToGroup(wall, "wall");
    }

    const std::vector<std::string> pathsPacgums {"assets/little_dat.png", "assets/little_dat.png", "ressource_pacgum"};
    for (size_t i = 0; i < pacgumsPosition.size(); i++) {
        engine::ecs::Entity& pacgum = mainGame.createEntity();
        pacgum.addComponent<engine::component::ARender>(pathsPacgums);
        pacgum.addComponent<engine::component::Hitbox>(10, 10);
        pacgum.addComponent<engine::component::Size>(10, 10);
        pacgum.addComponent<engine::component::Transform>(engine::type::Vector2D(pacgumsPosition[i].first, pacgumsPosition[i].second), 1);
        mainGame.addToGroup(pacgum, "pacgum");
    }

    const std::vector<std::string> pathsPacgumsSpecial {"assets/big_dat.png", "assets/big_dat.png", "ressource_pacgum_special"};
    for (size_t i = 0; i < pacgumsSpecialPosition.size(); i++) {
        engine::ecs::Entity& pacgumSpecial = mainGame.createEntity();
        pacgumSpecial.addComponent<engine::component::ARender>(pathsPacgumsSpecial);
        pacgumSpecial.addComponent<engine::component::Hitbox>(10, 10);
        pacgumSpecial.addComponent<engine::component::Size>(10, 10);
        pacgumSpecial.addComponent<engine::component::Transform>(engine::type::Vector2D(pacgumsSpecialPosition[i].first, pacgumsSpecialPosition[i].second), 1);
        mainGame.addToGroup(pacgumSpecial, "pacgumSpecial");
    }

    mainGame.addToGroup(pacmanEntity, "pacman");
    mainGame.addToGroup(redGhost, "ghost");
    mainGame.addToGroup(blueGhost, "ghost");
    mainGame.addToGroup(pinkGhost, "ghost");
    mainGame.addToGroup(orangeGhost, "ghost");

    _universe.setCurrentWorld("mainGamePacman");

    _universe.getEventBus().subscribe(*this, &pacman::Game::receiveCollision);
}

void Game::destroy()
{
    this->_universe.deleteWorld("mainGamePacman");
}

void Game::receiveCollision(engine::event::Collision& event)
{
    if (event.entity1.hasComponents<engine::component::Motion>()) {
        auto& motion = event.entity1.getComponent<engine::component::Motion>();
        auto& transform = event.entity1.getComponent<engine::component::Transform>();

        motion.velocity.x -= motion.acceleration.x;
        motion.velocity.y -= motion.acceleration.y;

        transform.position.x -= motion.velocity.x;
        transform.position.y -= motion.velocity.y;

        motion.velocity.x = 0;
        motion.acceleration.x = 0;
        motion.velocity.y = 0;
        motion.acceleration.y = 0;
    }

    if (event.entity2.hasComponents<engine::component::Motion>()) {
        auto& motion2 = event.entity2.getComponent<engine::component::Motion>();
        auto& transform2 = event.entity2.getComponent<engine::component::Transform>();

        motion2.velocity.x -= motion2.acceleration.x;
        motion2.velocity.y -= motion2.acceleration.y;

        transform2.position.x -= motion2.velocity.x;
        transform2.position.y -= motion2.velocity.y;

        motion2.velocity.x = 0;
        motion2.acceleration.x = 0;
        motion2.velocity.y = 0;
        motion2.acceleration.y = 0;
    }
}
