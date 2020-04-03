/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

#include <iostream>

#include "../../../engine/component/ARender.hpp"
#include "../../../engine/component/Size.hpp"
#include "../../../engine/component/Transform.hpp"
#include "../../../engine/system/Movement.hpp"
#include "../../../engine/system/Physics.hpp"
#include "../../../engine/type/Vector2D.hpp"
#include "../core/Core.hpp"

using namespace menu;

Menu::Menu(engine::ecs::Universe& universe) : game::AGame(universe, "menu")
{
}

Menu::~Menu() = default;

void Menu::init()
{
    std::cout << "HAAAN" << std::endl;

    auto& world = _universe.createWorld("menu");

    int i = 0;

    for (auto& graph : _universe.getCore().getGraphicals()) {
        (void) graph;

        auto &entity = world.createEntity();

        const std::vector<std::string> paths {"./assets/button.png", "./assets/button.png", "ressource_button"};
        entity.addComponent<engine::component::ARender>(paths);
        entity.addComponent<engine::component::Size>(200, 100);
        entity.addComponent<engine::component::Transform>(engine::type::Vector2D(100, 100 * i + 50), 1);

        world.addToGroup(entity, "graph");
        i++;
    }

    i = 0;

    for (auto& game : _universe.getCore().getGames()) {
        (void) game;

        auto &entity = world.createEntity();

        const std::vector<std::string> paths {"./assets/button.png", "./assets/button.png", "ressource_button"};
        entity.addComponent<engine::component::ARender>(paths);
        entity.addComponent<engine::component::Size>(200, 100);
        entity.addComponent<engine::component::Transform>(engine::type::Vector2D(600, 100 * i + 50), 1);

        world.addToGroup(entity, "game");
        i++;
    }

    world.addSystem<engine::system::ARender>();
    world.addSystem<engine::system::Movement>();
    world.addSystem<engine::system::Physics>();

    _universe.setCurrentWorld("menu");
}

void Menu::destroy()
{
    _universe.deleteWorld("menu");
}