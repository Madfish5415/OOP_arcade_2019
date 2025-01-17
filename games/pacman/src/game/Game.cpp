/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#include "Game.hpp"

#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::pair<int, int>> wallsPosition = {{480, 270}, {520, 270}, {560, 270}, {600, 270}, {640, 270}, {680, 270}, {720, 270},
        {760, 270}, {800, 270}, {840, 270}, {880, 270}, {920, 270}, {960, 270}, {1000, 270}, {1040, 270}, {1080, 270}, {1120, 270},
        {1160, 270}, {1200, 270}, {1240, 270}, {1280, 270}, {1320, 270}, {1360, 270}, {1400, 270}, {1440, 270}, {480, 790}, {520, 790},
        {560, 790}, {600, 790}, {640, 790}, {680, 790}, {720, 790}, {760, 790}, {800, 790}, {840, 790}, {880, 790}, {920, 790}, {960, 790},
        {1000, 790}, {1040, 790}, {1080, 790}, {1120, 790}, {1160, 790}, {1200, 790}, {1240, 790}, {1280, 790}, {1320, 790}, {1360, 790},
        {1400, 790}, {1440, 790}, {480, 310}, {1440, 310}, {480, 350}, {1440, 350}, {480, 390}, {1440, 390}, {480, 430}, {1440, 430},
        {480, 470}, {1440, 470}, {480, 510}, {1440, 510}, {480, 550}, {1440, 550}, {480, 590}, {1440, 590}, {480, 630}, {1440, 630},
        {480, 670}, {1440, 670}, {480, 710}, {1440, 710}, {480, 750}, {1440, 750}, {560, 350}, {600, 350}, {680, 350}, {720, 350},
        {800, 350}, {840, 350}, {880, 350}, {920, 350}, {1000, 350}, {1040, 350}, {1080, 350}, {1120, 350}, {1200, 350}, {1240, 350},
        {1320, 350}, {1360, 350}, {560, 390}, {600, 390}, {680, 390}, {1240, 390}, {1320, 390}, {1360, 390}, {680, 430}, {760, 430},
        {840, 430}, {880, 430}, {920, 430}, {1000, 430}, {1040, 430}, {1080, 430}, {1160, 430}, {1240, 430}, {520, 470}, {560, 470},
        {600, 470}, {760, 470}, {840, 470}, {1080, 470}, {1160, 470}, {1320, 470}, {1360, 470}, {1400, 470}, {680, 510}, {840, 510},
        {1080, 510}, {1240, 510}, {680, 550}, {760, 550}, {840, 550}, {1080, 550}, {1160, 550}, {1240, 550}, {520, 590}, {560, 590},
        {600, 590}, {760, 590}, {840, 590}, {1080, 590}, {1160, 590}, {1320, 590}, {1360, 590}, {1400, 590}, {680, 630}, {840, 630},
        {880, 630}, {920, 630}, {960, 630}, {1000, 630}, {1040, 630}, {1080, 630}, {1240, 630}, {560, 670}, {600, 670}, {680, 670},
        {720, 670}, {760, 670}, {1160, 670}, {1200, 670}, {1240, 670}, {1320, 670}, {1360, 670}, {560, 710}, {760, 710}, {800, 710},
        {840, 710}, {880, 710}, {920, 710}, {1000, 710}, {1040, 710}, {1080, 710}, {1120, 710}, {1160, 710}, {1360, 710}, {640, 750},
        {680, 750}, {1240, 750}, {1280, 750}};

    std::vector<std::pair<int, int>> pacgumsPosition = {{535, 325}, {575, 325}, {655, 325}, {695, 325}, {735, 325}, {775, 325}, {815, 325},
        {855, 325}, {895, 325}, {935, 325}, {975, 325}, {1015, 325}, {1055, 325}, {1095, 325}, {1135, 325}, {1175, 325}, {1215, 325},
        {1255, 325}, {1295, 325}, {1335, 325}, {1375, 325}, {1415, 325}, {535, 365}, {655, 365}, {775, 365}, {975, 365}, {1175, 365},
        {1295, 365}, {1415, 365}, {535, 405}, {655, 405}, {735, 405}, {775, 405}, {815, 405}, {855, 405}, {895, 405}, {935, 405},
        {975, 405}, {1015, 405}, {1055, 405}, {1095, 405}, {1135, 405}, {1175, 405}, {1295, 405}, {1415, 405}, {535, 445}, {575, 445},
        {615, 445}, {655, 445}, {735, 445}, {815, 445}, {975, 445}, {1135, 445}, {1215, 445}, {1295, 445}, {1335, 445}, {1375, 445},
        {1415, 445}, {655, 485}, {695, 485}, {735, 485}, {815, 485}, {1135, 485}, {1215, 485}, {1255, 485}, {1295, 485}, {655, 525},
        {735, 525}, {775, 525}, {815, 525}, {1135, 525}, {1175, 525}, {1215, 525}, {1295, 525}, {655, 565}, {735, 565}, {815, 565},
        {1135, 565}, {1215, 565}, {1295, 565}, {655, 605}, {735, 605}, {815, 605}, {1135, 605}, {1215, 605}, {1255, 605}, {1295, 605},
        {535, 645}, {575, 645}, {615, 645}, {655, 645}, {735, 645}, {775, 645}, {815, 645}, {1135, 645}, {1175, 645}, {1215, 645},
        {1295, 645}, {1335, 645}, {1375, 645}, {1415, 645}, {535, 685}, {655, 685}, {815, 685}, {855, 685}, {895, 685}, {935, 685},
        {975, 685}, {1015, 685}, {1055, 685}, {1095, 685}, {1135, 685}, {1295, 685}, {1415, 685}, {535, 725}, {615, 725}, {655, 725},
        {695, 725}, {735, 725}, {975, 725}, {1215, 725}, {1255, 725}, {1295, 725}, {1335, 725}, {1415, 725}, {535, 765}, {575, 765},
        {615, 765}, {735, 765}, {775, 765}, {815, 765}, {855, 765}, {895, 765}, {935, 765}, {975, 765}, {1015, 765}, {1055, 765},
        {1095, 765}, {1135, 765}, {1175, 765}, {1215, 765}, {1375, 765}, {1415, 765}};

    std::vector<std::pair<int, int>> pacgumsSpecialPosition = {{610, 320}, {1210, 400}, {690, 600}, {1330, 760}};

    std::vector<std::pair<int, int>> intersectionsPosition = {{640, 310}, {760, 310}, {960, 310}, {1160, 310}, {1280, 310}, {760, 390},
        {800, 390}, {960, 390}, {1120, 390}, {1160, 390}, {640, 430}, {1280, 430}, {640, 470}, {720, 470}, {1200, 470},
        {1280, 470}, {720, 510}, {800, 510}, {1120, 510}, {1200, 510}, {640, 590}, {720, 590}, {1200, 590}, {1280, 590}, {640, 630},
        {800, 630}, {1120, 630}, {1280, 630}, {960, 670}, {640, 710}, {1280, 710}, {960, 750}};

    engine::ecs::World& mainGame = this->_universe.createWorld("mainGamePacman");
    mainGame.addSystem<system::AI>();
    mainGame.addSystem<engine::system::ARender>();
    mainGame.addSystem<system::User>();
    mainGame.addSystem<engine::system::Movement>();
    mainGame.addSystem<engine::system::Physics>();

    engine::ecs::Entity& pacmanEntity = mainGame.createEntity();
    const std::vector<std::string> pathsPacman {"assets/test_pacman.png", "assets/test_pacman.png", "ressource_pacman"};
    pacmanEntity.addComponent<engine::component::ARender>(pathsPacman);
    pacmanEntity.addComponent<engine::component::Hitbox>(38, 38);
    pacmanEntity.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 0), engine::type::Vector2D(0, 0));
    pacmanEntity.addComponent<engine::component::Size>(40, 40);
    pacmanEntity.addComponent<engine::component::Transform>(engine::type::Vector2D(960, 670), 5);
    pacmanEntity.addComponent<component::User>();

    engine::ecs::Entity& redGhost = mainGame.createEntity();
    const std::vector<std::string> pathsRed {"assets/test_red.png", "assets/test_red.png", "ressource_red_ghost"};
    redGhost.addComponent<engine::component::ARender>(pathsRed);
    redGhost.addComponent<engine::component::Hitbox>(38, 38);
    redGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, -1), engine::type::Vector2D(0, 0));
    redGhost.addComponent<engine::component::Size>(40, 40);
    redGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(880, 550), 4);
    redGhost.addComponent<component::AI>();

    engine::ecs::Entity& blueGhost = mainGame.createEntity();
    const std::vector<std::string> pathsBlue {"assets/test_blue.png", "assets/test_blue.png", "ressource_blue_ghost"};
    blueGhost.addComponent<engine::component::ARender>(pathsBlue);
    blueGhost.addComponent<engine::component::Hitbox>(38, 38);
    blueGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, -1), engine::type::Vector2D(0, 0));
    blueGhost.addComponent<engine::component::Size>(40, 40);
    blueGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(920, 550), 4);
    blueGhost.addComponent<component::AI>();

    engine::ecs::Entity& pinkGhost = mainGame.createEntity();
    const std::vector<std::string> pathsPink {"assets/test_pink.png", "assets/test_pink.png", "ressource_pink_ghost"};
    pinkGhost.addComponent<engine::component::ARender>(pathsPink);
    pinkGhost.addComponent<engine::component::Hitbox>(38, 38);
    pinkGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, -1), engine::type::Vector2D(0, 0));
    pinkGhost.addComponent<engine::component::Size>(40, 40);
    pinkGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1000, 550), 4);
    pinkGhost.addComponent<component::AI>();

    engine::ecs::Entity& orangeGhost = mainGame.createEntity();
    const std::vector<std::string> pathsOrange {"assets/test_orange.png", "assets/test_orange.png", "ressource_orange_ghost"};
    orangeGhost.addComponent<engine::component::ARender>(pathsOrange);
    orangeGhost.addComponent<engine::component::Hitbox>(38, 38);
    orangeGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, -1), engine::type::Vector2D(0, 0));
    orangeGhost.addComponent<engine::component::Size>(40, 40);
    orangeGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1040, 550), 4);
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
        pacgum.addComponent<engine::component::Transform>(engine::type::Vector2D(pacgumsPosition[i].first, pacgumsPosition[i].second), 3);
        mainGame.addToGroup(pacgum, "pacgum");
    }

    const std::vector<std::string> pathsPacgumsSpecial {"assets/big_dat.png", "assets/big_dat.png", "ressource_pacgum_special"};
    for (size_t i = 0; i < pacgumsSpecialPosition.size(); i++) {
        engine::ecs::Entity& pacgumSpecial = mainGame.createEntity();
        pacgumSpecial.addComponent<engine::component::ARender>(pathsPacgumsSpecial);
        pacgumSpecial.addComponent<engine::component::Hitbox>(20, 20);
        pacgumSpecial.addComponent<engine::component::Size>(20, 20);
        pacgumSpecial.addComponent<engine::component::Transform>(
            engine::type::Vector2D(pacgumsSpecialPosition[i].first, pacgumsSpecialPosition[i].second), 3);
        mainGame.addToGroup(pacgumSpecial, "pacgumSpecial");
    }

    //const std::vector<std::string> pathsIntersect {"assets/button.png", "assets/button.png", "ressource_wall"};
    for (size_t i = 0; i < intersectionsPosition.size(); i++) {
        engine::ecs::Entity& intersect = mainGame.createEntity();
        //intersect.addComponent<engine::component::ARender>(pathsIntersect);
        intersect.addComponent<engine::component::Hitbox>(40, 40);
        intersect.addComponent<engine::component::Size>(40, 40);
        intersect.addComponent<engine::component::Transform>(
            engine::type::Vector2D(intersectionsPosition[i].first, intersectionsPosition[i].second), 2);
        mainGame.addToGroup(intersect, "intersect");
    }

    mainGame.addToGroup(pacmanEntity, "pacman");
    mainGame.addToGroup(redGhost, "ghost");
    mainGame.addToGroup(blueGhost, "ghost");
    mainGame.addToGroup(pinkGhost, "ghost");
    mainGame.addToGroup(orangeGhost, "ghost");

    _universe.setCurrentWorld("mainGamePacman");

    _universe.getEventBus().subscribe(*this, &pacman::Game::receiveWallCollision);
}

void Game::destroy()
{
    this->_universe.deleteWorld("mainGamePacman");
}

void Game::receiveWallCollision(engine::event::Collision& event)
{
    if (!event.entity1.getWorld().hasGroup(event.entity1, "wall") && !event.entity2.getWorld().hasGroup(event.entity2, "wall")) return;

    if (event.entity1.hasComponents<engine::component::Motion>()) {
        auto& motion = event.entity1.getComponent<engine::component::Motion>();
        auto& transform = event.entity1.getComponent<engine::component::Transform>();
        auto& hitbox = event.entity1.getComponent<engine::component::Hitbox>();
        auto& transform2 = event.entity2.getComponent<engine::component::Transform>();
        auto& hitbox2 = event.entity2.getComponent<engine::component::Hitbox>();

        if (transform.position.x + 2 < transform2.position.x + hitbox2.width &&
            transform2.position.x < transform.position.x + hitbox.width - 2 &&
            transform.position.y + 2 < transform2.position.y + hitbox2.height &&
            transform2.position.y < transform.position.y + hitbox.height - 2) {
            motion.velocity.x -= motion.acceleration.x;
            motion.velocity.y -= motion.acceleration.y;

            transform.position.x -= motion.velocity.x;
            transform.position.y -= motion.velocity.y;

            motion.velocity.x = 0;
            motion.acceleration.x = 0;
            motion.velocity.y = 0;
            motion.acceleration.y = 0;
        }
        return;
    }

    if (event.entity2.hasComponents<engine::component::Motion>()) {
        auto& transform = event.entity2.getComponent<engine::component::Transform>();
        auto& hitbox = event.entity2.getComponent<engine::component::Hitbox>();
        auto& motion = event.entity2.getComponent<engine::component::Motion>();
        auto& transform2 = event.entity1.getComponent<engine::component::Transform>();
        auto& hitbox2 = event.entity1.getComponent<engine::component::Hitbox>();

        if (transform.position.x + 2 < transform2.position.x + hitbox2.width &&
            transform2.position.x < transform.position.x + hitbox.width - 2 &&
            transform.position.y + 2 < transform2.position.y + hitbox2.height &&
            transform2.position.y < transform.position.y + hitbox.height - 2) {
            motion.velocity.x -= motion.acceleration.x;
            motion.velocity.y -= motion.acceleration.y;

            transform.position.x -= motion.velocity.x;
            transform.position.y -= motion.velocity.y;

            motion.velocity.x = 0;
            motion.acceleration.x = 0;
            motion.velocity.y = 0;
            motion.acceleration.y = 0;
        }
        return;
    }
}
