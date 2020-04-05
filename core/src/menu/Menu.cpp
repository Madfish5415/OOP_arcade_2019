/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

#include <ctime>
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
#include "component/User.hpp"
#include "system/User.hpp"

using namespace menu;

Menu::Menu(engine::ecs::Universe& universe, std::string name) : game::AGame(universe, name)
{
}

Menu::~Menu() = default;

void Menu::init()
{
    auto& world = _universe.createWorld(getName());

    int i = 0;

    for (auto& graph : _universe.getCore().getGraphicals()) {
        auto& entity = world.createEntity();
        int x = 0;
        int y = 0;
        int libSize = _universe.getCore().getGraphicals().size();
        int offset = (libSize > 4) ? 30 : 75;
        int gridSize = (150 * libSize + offset * libSize);

        std::vector<std::string> tmp;
        if (getName() == "Menu")
            tmp = {"./assets/button.png", "./assets/button.png", "ressource_button"};
        else if (getName() == "Menuv2")
            tmp = {"./assets/button2.png", "./assets/button2.png", "ressource_button2"};
        else
            tmp = {"./assets/button3.jpg", "./assets/button3.jpg", "ressource_button3"};

        const std::vector<std::string> pathsRender = tmp;
        entity.addComponent<engine::component::ARender>(pathsRender);
        const std::vector<std::string> pathsText {"./assets/game_over.ttf", "./assets/game_over.ttf", "font_button"};
        std::string name = graph.first;
        std::for_each(name.begin(), name.end(), [](char& c) { c = ::toupper(c); });
        const std::string text = name;
        entity.addComponent<engine::component::AText>(text, pathsText);
        entity.addComponent<engine::component::Size>(400, 150);
        x = 440;
        y = (1080 - gridSize) / 2 + (gridSize / libSize) / 2 - 150 / 2 + (gridSize / libSize * (i));
        entity.addComponent<engine::component::Transform>(engine::type::Vector2D(x, y), 10);

        world.addToGroup(entity, "graph");
        i++;
    }

    i = 0;

    std::map<std::string, core::DynamicLib<game::IGame>*> games;

    for (auto& game : _universe.getCore().getGames()) {
        if (game.first != _universe.getCore().getCurrentGame().getName()) games.emplace(game);
    }

    for (auto& game : games) {
        auto& entity = world.createEntity();
        int x = 0;
        int y = 0;
        int libSize = games.size();
        int offset = (libSize > 4) ? 30 : 75;
        int gridSize = (150 * libSize + offset * libSize);

        std::vector<std::string> tmp;
        if (getName() == "Menu")
            tmp = {"./assets/button.png", "./assets/button.png", "ressource_button"};
        else if (getName() == "Menuv2")
            tmp = {"./assets/button2.png", "./assets/button2.png", "ressource_button2"};
        else
            tmp = {"./assets/button3.jpg", "./assets/button3.jpg", "ressource_button3"};

        const std::vector<std::string> pathsRender = tmp;
        entity.addComponent<engine::component::ARender>(pathsRender);
        const std::vector<std::string> pathsText {"./assets/game_over.ttf", "./assets/game_over.ttf", "font_button"};
        std::string name = game.first;
        std::for_each(name.begin(), name.end(), [](char& c) { c = ::toupper(c); });
        const std::string text = name;
        entity.addComponent<engine::component::AText>(text, pathsText);
        entity.addComponent<engine::component::Size>(400, 150);
        x = 1920 - 440 - 400;
        y = (1080 - gridSize) / 2 + (gridSize / libSize) / 2 - 150 / 2 + (gridSize / libSize * (i));
        entity.addComponent<engine::component::Transform>(engine::type::Vector2D(x, y), 10);

        world.addToGroup(entity, "game");
        i++;
    }

    auto& selector = world.createEntity();
    std::vector<std::string> tmp;
    if (getName() == "Menu")
        tmp = {"./assets/selector.png", "./assets/selector.png", "ressource_selector"};
    else if (getName() == "Menuv2")
        tmp = {"./assets/selector2.png", "./assets/selector2.png", "ressource_selector2"};
    else
        tmp = {"./assets/selector3.png", "./assets/selector3.png", "ressource_selector3"};
    const std::vector<std::string> paths = tmp;
    selector.addComponent<engine::component::ARender>(paths);
    selector.addComponent<engine::component::Size>(430, 180);
    auto& graphGroup = world.getGroup("graph");
    int x = graphGroup.begin()->get().getComponent<engine::component::Transform>().position.x - 15;
    int y = graphGroup.begin()->get().getComponent<engine::component::Transform>().position.y - 15;
    selector.addComponent<engine::component::Transform>(engine::type::Vector2D(x, y), 11);
    if (getName() == "Menu") {
        auto list =
            new const std::map<std::string, engine::type::Animation> {std::make_pair("OnSelect", engine::type::Animation(0, 14, 100))};
        selector.addComponent<engine::component::Animations>(*list);
    }
    selector.addComponent<menu::component::User>();

    auto& wallpaper = world.createEntity();
    const std::vector<std::string> wppaths {"./assets/arcade-wp.jpg", "./assets/arcade-wp.jpg", "ressource_selector"};
    wallpaper.addComponent<engine::component::ARender>(wppaths);
    wallpaper.addComponent<engine::component::Size>(1920, 1080);
    wallpaper.addComponent<engine::component::Transform>(engine::type::Vector2D(0, 0), 1);

    world.addSystem<menu::system::User>();
    world.addSystem<engine::system::AAnimations>();
    world.addSystem<engine::system::ARender>();
    world.addSystem<engine::system::Movement>();
    world.addSystem<engine::system::Physics>();

    std::srand(std::time(NULL));

    _universe.setCurrentWorld(getName());
}

void Menu::destroy()
{
    _universe.deleteWorld(getName());
}