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

using namespace core;

Core::Core()
{
    _currentGame = "";
    _currentGraphical = "";
    _universe = new engine::ecs::Universe(*this);
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

    if (_games.size()) {
        _currentGame = _games.begin()->first;
    }
}

void Core::loadGraphics()
{
    std::string path = "./lib/";
    std::regex regex(R"((^./lib/lib_arcade_.*\.so))");

    for (auto& file : std::filesystem::directory_iterator(path)) {
        if (std::regex_match(file.path().string(), regex)) {
            std::string name = file.path().string().substr(21, (file.path().string().length() - 24));

            _graphicals.emplace(name, new DynamicLib<graphical::IGraphical>(file.path().string(), &_universe->getEventBus()));
        }
    }

    if (_graphicals.size()) {
        _currentGraphical = _graphicals.begin()->first;
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

    _currentGraphical = name;
}
