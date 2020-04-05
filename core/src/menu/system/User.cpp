/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.cpp
*/

#include "User.hpp"

#include <iostream>

#include "menu/component/User.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../core/Core.hpp"

using namespace menu;
using namespace system;

User::User(engine::ecs::World& world) : AUser(world)
{
}

User::~User() = default;

void User::init()
{
    _world.getUniverse().getEventBus().subscribe(*this, &User::inputSubscriber);
}

void User::update()
{
}

void User::render()
{
}

void User::inputSubscriber(engine::event::Input& event)
{
    auto entities = _world.getEntities<component::User, engine::component::Transform>();

    for (auto& ent : entities) {
        if (event.code == event.KEY_UP) {
            auto& userCmp = ent.get().getComponent<component::User>();
            auto& transformCmp = ent.get().getComponent<engine::component::Transform>();
            std::map<std::string, core::DynamicLib<game::IGame>*> games;

            for (auto& game : _world.getUniverse().getCore().getGames()) {
                if (game.first != _world.getUniverse().getCore().getCurrentGame().getName())
                    games.emplace(game);
            }

            if (userCmp.currentObserved.first == "graph") {
                if (_world.getUniverse().getCore().getGraphicals().size() == 0) continue;
            } else if (userCmp.currentObserved.first == "game") {
                if (games.size() == 0) continue;
            }

            userCmp.currentObserved.second -= 1;

            if (userCmp.currentObserved.second < 0) {
                auto& group = _world.getGroup(userCmp.currentObserved.first);
                userCmp.currentObserved.second = group.size() - 1;
            }

            int i = 0;
            auto button = ent;
            for (auto& group : _world.getGroup(userCmp.currentObserved.first)) {
                button = group;
                if (i == userCmp.currentObserved.second) break;
                i++;
            }

            if (&button != &ent) {
                auto &transformBut = button.get().getComponent<engine::component::Transform>();

                transformCmp.position.x = transformBut.position.x - 15;
                transformCmp.position.y = transformBut.position.y - 15;
            }
        } else if (event.code == event.KEY_DOWN) {
            auto& userCmp = ent.get().getComponent<component::User>();
            auto& transformCmp = ent.get().getComponent<engine::component::Transform>();
            std::map<std::string, core::DynamicLib<game::IGame>*> games;

            for (auto& game : _world.getUniverse().getCore().getGames()) {
                if (game.first != _world.getUniverse().getCore().getCurrentGame().getName())
                    games.emplace(game);
            }

            if (userCmp.currentObserved.first == "graph") {
                if (_world.getUniverse().getCore().getGraphicals().size() == 0) continue;
            } else if (userCmp.currentObserved.first == "game") {
                if (games.size() == 0) continue;
            }

            userCmp.currentObserved.second += 1;

            if (userCmp.currentObserved.second > int(_world.getGroup(userCmp.currentObserved.first).size() - 1)) {
                userCmp.currentObserved.second = 0;
            }

            int i = 0;
            auto button = ent;
            for (auto& group : _world.getGroup(userCmp.currentObserved.first)) {
                button = group;
                if (i == userCmp.currentObserved.second) break;
                i++;
            }

            if (&button != &ent) {
                auto &transformBut = button.get().getComponent<engine::component::Transform>();

                transformCmp.position.x = transformBut.position.x - 15;
                transformCmp.position.y = transformBut.position.y - 15;
            }
        } else if (event.code == event.KEY_LEFT || event.code == event.KEY_RIGHT) {
            auto& userCmp = ent.get().getComponent<component::User>();
            auto& transformCmp = ent.get().getComponent<engine::component::Transform>();

            std::map<std::string, core::DynamicLib<game::IGame>*> games;

            for (auto& game : _world.getUniverse().getCore().getGames()) {
                if (game.first != _world.getUniverse().getCore().getCurrentGame().getName())
                    games.emplace(game);
            }

            if (userCmp.currentObserved.first == "graph" && games.size() != 0)
                userCmp.currentObserved.first = "game";
            else if (userCmp.currentObserved.first == "game" && _world.getUniverse().getCore().getGraphicals().size() != 0)
                userCmp.currentObserved.first = "graph";

            auto& groups = _world.getGroup(userCmp.currentObserved.first);

            if (userCmp.currentObserved.second > int(groups.size() - 1))
                userCmp.currentObserved.second = int(groups.size() - 1);

            int i = 0;
            auto button = ent;
            for (auto& group : _world.getGroup(userCmp.currentObserved.first)) {
                button = group;
                if (i == userCmp.currentObserved.second) break;
                i++;
            }

            if (&button != &ent) {
                auto &transformBut = button.get().getComponent<engine::component::Transform>();

                transformCmp.position.x = transformBut.position.x - 15;
                transformCmp.position.y = transformBut.position.y - 15;
            }
        } else if (event.code == event.KEY_ENTER || event.code == event.KEY_SPACE) {
            auto& userCmp = ent.get().getComponent<component::User>();

            int i = 0;
            auto button = ent;
            for (auto& group : _world.getGroup(userCmp.currentObserved.first)) {
                button = group;
                if (i == userCmp.currentObserved.second) break;
                i++;
            }

            if (&button == &ent)
                continue;

            std::string libname;
            std::string cmp = button.get().getComponent<engine::component::AText>().text;

            if (userCmp.currentObserved.first == "graph") {
                for (auto& graph : _world.getUniverse().getCore().getGraphicals()) {
                    std::string tmp = graph.first;
                    std::for_each(tmp.begin(), tmp.end(), [](char& c) {
                      c = ::toupper(c);
                    });

                    if (tmp == cmp)
                        libname = graph.first;
                }
            } else if (userCmp.currentObserved.first == "game") {
                for (auto& game : _world.getUniverse().getCore().getGames()) {
                    std::string tmp = game.first;
                    std::for_each(tmp.begin(), tmp.end(), [](char& c) {
                      c = ::toupper(c);
                    });

                    if (tmp == cmp)
                        libname = game.first;
                }
            }

            auto eventSwitch = new engine::event::Switch(userCmp.currentObserved.first, libname);

            _world.getUniverse().getEventBus().publish(*eventSwitch);

            delete eventSwitch;
        }
    }
}
