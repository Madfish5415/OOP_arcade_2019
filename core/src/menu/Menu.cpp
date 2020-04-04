/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

#include <iostream>


#include "../../../engine/component/ARender.hpp"
#include "../../../engine/component/Animations.hpp"
#include "../../../engine/component/Size.hpp"
#include "../../../engine/component/Transform.hpp"
#include "../../../engine/system/Movement.hpp"
#include "../../../engine/system/Physics.hpp"
#include "../../../engine/type/Vector2D.hpp"
#include "../core/Core.hpp"
#include "../core/DynamicLib.hpp"
#include "system/User.hpp"
#include "component/User.hpp"

using namespace menu;

Menu::Menu(engine::ecs::Universe& universe) : game::AGame(universe, "menu")
{
}

Menu::~Menu() = default;

void Menu::init()
{
    auto& world = _universe.createWorld("menu");

    int i = 0;

    for (auto& graph : _universe.getCore().getGraphicals()) {
        (void) graph;

        auto &entity = world.createEntity();
        int x = 0;
        int y = 0;
        int lib_size = _universe.getCore().getGraphicals().size();
        int offset = (lib_size > 4) ? 30 : 75;
        int gridSize = (150 * lib_size + offset * lib_size);

        const std::vector<std::string> paths {"./assets/button.png", "./assets/button.png", "ressource_button"};
        entity.addComponent<engine::component::ARender>(paths);
        entity.addComponent<engine::component::Size>(400, 150);
        x = 440;
        y = (1080 - gridSize) / 2 + (gridSize / lib_size) / 2 - 150 / 2 + (gridSize / lib_size * (i));
        entity.addComponent<engine::component::Transform>(engine::type::Vector2D(x, y), 1);

        world.addToGroup(entity, "graph");
        i++;
    }

    i = 0;

    std::map<std::string, core::DynamicLib<game::IGame>*> games;

    for (auto& game : _universe.getCore().getGames()) {
        if (game.first != _universe.getCore().getCurrentGame().getName())
            games.emplace(game);
    }

    for (auto& game : games) {
        (void) game;

        auto &entity = world.createEntity();
        int x = 0;
        int y = 0;
        int lib_size = games.size();
        int offset = (lib_size > 4) ? 30 : 75;
        int gridSize = (150 * lib_size + offset * lib_size);

        const std::vector<std::string> paths {"./assets/button.png", "./assets/button.png", "ressource_button"};
        entity.addComponent<engine::component::ARender>(paths);
        entity.addComponent<engine::component::Size>(400, 150);
        x = 1920 - 440 - 400;
        y = (1080 - gridSize) / 2 + (gridSize / lib_size) / 2 - 150 / 2 + (gridSize / lib_size * (i));
        entity.addComponent<engine::component::Transform>(engine::type::Vector2D(x, y), 1);

        world.addToGroup(entity, "game");
        i++;
    }

    auto& selector = world.createEntity();
    const std::vector<std::string> paths {"./assets/selector.png", "./assets/selector.png", "ressource_selector"};
    selector.addComponent<engine::component::ARender>(paths);
    selector.addComponent<engine::component::Size>(430, 180);
    auto& graphGroup = world.getGroup("graph");
    int x = graphGroup.begin()->get().getComponent<engine::component::Transform>().position.x - 15;
    int y = graphGroup.begin()->get().getComponent<engine::component::Transform>().position.y - 15;
    selector.addComponent<engine::component::Transform>(engine::type::Vector2D(x, y), 2);

    auto list = new const std::map<std::string, engine::type::Animation> {std::make_pair("OnSelect", engine::type::Animation(0, 5, 200))};
    selector.addComponent<engine::component::Animations>(*list);
    selector.addComponent<menu::component::User>();


    world.addSystem<menu::system::User>();
    world.addSystem<engine::system::AAnimations>();
    world.addSystem<engine::system::ARender>();
    world.addSystem<engine::system::Movement>();
    world.addSystem<engine::system::Physics>();

    _universe.setCurrentWorld("menu");
}

void Menu::destroy()
{
    _universe.deleteWorld("menu");
}