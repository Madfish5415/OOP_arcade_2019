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
    std::vector<std::pair<int, int>> wallsPosition = {{0, 0}, {40, 0}, {80, 0}, {120, 0}, {160, 0}, {200, 0}, {240, 0}, {280, 0}, {320, 0}, {360, 0}, {400, 0}, {440, 0}, {480, 0}, {520, 0}, {560, 0}, {600, 0}, {640, 0}, {680, 0}, {720, 0}, {760, 0}, {800, 0}, {840, 0}, {880, 0}, {920, 0}, {960, 0}, {1000, 0}, {1040, 0}, {1080, 0}, {1120, 0}, {1160, 0}, {1200, 0}, {1240, 0}, {1280, 0}, {1320, 0}, {1360, 0}, {1400, 0}, {1440, 0}, {1480, 0}, {1520, 0}, {1560, 0}, {1600, 0}, {1640, 0}, {1680, 0}, {1720, 0}, {1760, 0}, {1800, 0}, {1840, 0}, {1880, 0},
                                                        {0, 1040}, {40, 1040}, {80, 1040}, {120, 1040}, {160, 1040}, {200, 1040}, {240, 1040}, {280, 1040}, {320, 1040}, {360, 1040}, {400, 1040}, {440, 1040}, {480, 1040}, {520, 1040}, {560, 1040}, {600, 1040}, {640, 1040}, {680, 1040}, {720, 1040}, {760, 1040}, {800, 1040}, {840, 1040}, {880, 1040}, {920, 1040}, {960, 1040}, {1000, 1040}, {1040, 1040}, {1080, 1040}, {1120, 1040}, {1160, 1040}, {1200, 1040}, {1240, 1040}, {1280, 1040}, {1320, 1040}, {1360, 1040}, {1400, 1040}, {1440, 1040}, {1480, 1040}, {1520, 1040}, {1560, 1040}, {1600, 1040}, {1640, 1040}, {1680, 1040}, {1720, 1040}, {1760, 1040}, {1800, 1040}, {1840, 1040}, {1880, 1040},
                                                        {0, 40}, {1880, 40}, {0, 80}, {1880, 80}, {0, 120}, {1880, 120}, {0, 160}, {1880, 160}, {0, 200}, {1880, 200}, {0, 240}, {1880, 240}, {0, 280}, {1880, 280}, {0, 320}, {1880, 320}, {0, 360}, {1880, 360}, {0, 400}, {1880, 400}, {0, 440}, {1880, 440}, {0, 480}, {1880, 480}, {0, 520}, {1880, 520}, {0, 560}, {1880, 560}, {0, 600}, {1880, 600}, {0, 640}, {1880, 640}, {0, 680}, {1880, 680}, {0, 720}, {1880, 720}, {0, 760}, {1880, 760}, {0, 800}, {1880, 800}, {0, 840}, {1880, 840}, {0, 880}, {1880, 880}, {0, 920}, {1880, 920}, {0, 960}, {1880, 960}, {0, 1000}, {1880, 1000}, {0, 1040}, {1880, 1040}};

    engine::ecs::World& mainGame = this->_universe.createWorld("mainGamePacman");
    engine::ecs::Entity& pacmanEntity = mainGame.createEntity();
    engine::ecs::Entity& redGhost = mainGame.createEntity();
    engine::ecs::Entity& blueGhost = mainGame.createEntity();
    engine::ecs::Entity& pinkGhost = mainGame.createEntity();
    engine::ecs::Entity& orangeGhost = mainGame.createEntity();

    std::vector<std::string> pathsWall {("assets/wall.png")};

    for (int i = 0; i < 148; i++) {
        engine::ecs::Entity& wall = mainGame.createEntity();
        engine::type::Vector2D wallPosition(wallsPosition[i].first, wallsPosition[i].second);
        wall.addComponent<engine::component::ARender>(pathsWall);
        wall.addComponent<engine::component::Hitbox>(40, 40);
        wall.addComponent<engine::component::Size>(40, 40);
        wall.addComponent<engine::component::Transform>(wallPosition, 1);
        mainGame.addToGroup(wall, "wall");
    }

    std::vector<std::string> pathsPacman {("assets/test_pacman.png")};
    std::vector<std::string> pathsRed {("assets/test_red.png")};
    std::vector<std::string> pathsBlue {("assets/test_blue.png")};
    std::vector<std::string> pathsPink {("assets/test_pink.png")};
    std::vector<std::string> pathsOrange {("assets/test_orange.png")};
    engine::type::Vector2D orangeVelocity(0, 1);
    engine::type::Vector2D orangeAcceleration(0, 0);
    engine::type::Vector2D orangePosition(1100, 900);

    mainGame.addSystem<system::AI>();
    mainGame.addSystem<engine::system::ARender>();
    mainGame.addSystem<system::User>();
    mainGame.addSystem<engine::system::Movement>();
    mainGame.addSystem<engine::system::Physics>();

    pacmanEntity.addComponent<engine::component::ARender>(pathsPacman);
    pacmanEntity.addComponent<engine::component::Hitbox>(40, 40);
    pacmanEntity.addComponent<engine::component::Motion>(engine::type::Vector2D(1, 0), engine::type::Vector2D(0, 0));
    pacmanEntity.addComponent<engine::component::Size>(40, 40);
    pacmanEntity.addComponent<engine::component::Transform>(engine::type::Vector2D(40, 40), 1);
    pacmanEntity.addComponent<component::User>();
    
    redGhost.addComponent<engine::component::ARender>(pathsRed);
    redGhost.addComponent<engine::component::Hitbox>(40, 40);
    redGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    redGhost.addComponent<engine::component::Size>(40, 40);
    redGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(200, 400), 1);
    redGhost.addComponent<component::AI>();

    blueGhost.addComponent<engine::component::ARender>(pathsBlue);
    blueGhost.addComponent<engine::component::Hitbox>(40, 40);
    blueGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    blueGhost.addComponent<engine::component::Size>(40, 40);
    blueGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(500, 800), 1);
    blueGhost.addComponent<component::AI>();

    pinkGhost.addComponent<engine::component::ARender>(pathsPink);
    pinkGhost.addComponent<engine::component::Hitbox>(40, 40);
    pinkGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    pinkGhost.addComponent<engine::component::Size>(40, 40);
    pinkGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1400, 300), 1);
    pinkGhost.addComponent<component::AI>();

    orangeGhost.addComponent<engine::component::ARender>(pathsOrange);
    orangeGhost.addComponent<engine::component::Hitbox>(40, 40);
    orangeGhost.addComponent<engine::component::Motion>(engine::type::Vector2D(0, 1), engine::type::Vector2D(0, 0));
    orangeGhost.addComponent<engine::component::Size>(40, 40);
    orangeGhost.addComponent<engine::component::Transform>(engine::type::Vector2D(1100, 900), 1);
    orangeGhost.addComponent<component::AI>();

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