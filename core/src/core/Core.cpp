/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <dlfcn.h>

#include <filesystem>
#include <regex>
#include <iostream>

using namespace core;

Core::Core()
{
    _currentGame = "";
    _currentGraphical = "";
    _universe = new engine::ecs::Universe(*this);
    _run = true;

    _universe->getEventBus().subscribe(*this, &Core::closeSubscriber);
}

Core::~Core()
{
    delete _universe;

    for (auto& pair : _games) {
        delete pair.second;
    }
    _games.clear();

    for (auto& pair : _graphicals) {
        delete pair.second;
    }
    _graphicals.clear();
}

void Core::loadGames()
{
    std::string path = "./games/";
    std::regex regex(R"((^./games/lib_arcade_.*\.so))");

    for (auto& file : std::filesystem::directory_iterator(path)) {
        if (std::regex_match(file.path().string(), regex)) {
            std::string name = file.path().string().substr(23, (file.path().string().length() - 26));

            _games.emplace(name, new DynamicLib<game::IGame>(file.path().string(), _universe));
        }
    }

    _games.emplace("test1", new DynamicLib<game::IGame>(_universe));
    _games.emplace("test2", new DynamicLib<game::IGame>(_universe));
    _games.emplace("test3", new DynamicLib<game::IGame>(_universe));
    _games.emplace("menu", new DynamicLib<game::IGame>(_universe));

    _currentGame = "menu";
}

void Core::loadGraphics()
{
    std::string path = "./lib/";
    std::regex regex(R"((^./lib/lib_arcade_.*\.so))");

    for (auto& file : std::filesystem::directory_iterator(path)) {
        if (std::regex_match(file.path().string(), regex)) {
            std::string name = file.path().string().substr(17, (file.path().string().length() - 20));

            _graphicals.emplace(name, new DynamicLib<graphical::IGraphical>(file.path().string(), &_universe->getEventBus()));
        }
    }

    if (!_graphicals.empty()) {
        for (auto& graph : _graphicals)
            _currentGraphical = graph.first;
    }
}

engine::ecs::Universe& Core::getUniverse() const
{
    return *_universe;
}

bool Core::hasGame(const std::string& name) const
{
    return _games.count(name) != 0;
}

game::IGame& Core::getGame(const std::string& name) const
{
    if (hasGame(name))
        return _games.at(name)->get();

    throw std::exception();
}

game::IGame& Core::getCurrentGame() const
{
    if (hasGame(_currentGame))
        return _games.at(_currentGame)->get();

    throw std::exception();
}

void Core::setCurrentGame(const std::string& name)
{
    if (!_games.count(name))
        throw std::exception();

    _currentGame = name;
}

std::map<std::string, DynamicLib<game::IGame>*>& Core::getGames()
{
    return _games;
}

bool Core::hasGraphical(const std::string& name) const
{
    return _graphicals.count(name) != 0;
}

graphical::IGraphical& Core::getGraphical(const std::string& name) const
{
    if (hasGame(name))
        return _graphicals.at(name)->get();

    throw std::exception();
}

graphical::IGraphical& Core::getCurrentGraphical() const
{
    if (hasGraphical(_currentGraphical))
        return _graphicals.at(_currentGraphical)->get();

    throw std::exception();
}

void Core::setCurrentGraphical(const std::string& name)
{
    if (!_graphicals.count(name))
        throw std::exception();

    if (name == _currentGraphical)
        return;

    auto& lib = _graphicals[name]->get();
    auto& oldlib = _graphicals[_currentGraphical]->get();

    _currentGraphical = name;

    lib.init();

    for (auto& name : _universe->getWorldNames()) {
        auto& world = _universe->getWorld(name);

        auto entities = world.getEntities<engine::component::AAudio>();

        for (auto& ent_ref : entities) {
            auto& audio = ent_ref.get().getComponent<engine::component::AAudio>();
            const std::vector<std::string> path = audio.paths;
            ent_ref.get().removeComponent<engine::component::AAudio>();
            ent_ref.get().addComponent<engine::component::AAudio>(path);
        }

        entities = world.getEntities<engine::component::ARender>();

        for (auto& ent_ref : entities) {
            auto& render = ent_ref.get().getComponent<engine::component::ARender>();
            const std::vector<std::string> path = render.paths;
            ent_ref.get().removeComponent<engine::component::ARender>();
            ent_ref.get().addComponent<engine::component::ARender>(path);
        }

        if (world.hasSystems<engine::system::AAudio>()) {
            world.removeSystem<engine::system::AAudio>();
            world.addSystem<engine::system::AAudio>();
        }

        if (world.hasSystems<engine::system::AAnimations>()) {
            world.removeSystem<engine::system::AAnimations>();
            world.addSystem<engine::system::AAnimations>();
        }

        if (world.hasSystems<engine::system::ARender>()) {
            world.removeSystem<engine::system::ARender>();
            world.addSystem<engine::system::ARender>();
        }
    }

    oldlib.destroy();
}

std::map<std::string, DynamicLib<graphical::IGraphical>*>& Core::getGraphicals()
{
    return _graphicals;
}

void Core::closeSubscriber(engine::event::Close& event)
{
    (void) event;

    _run = false;
}
