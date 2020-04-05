/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Universe.cpp
*/

#include <exception>

#include "Universe.hpp"

using namespace engine;
using namespace ecs;

Universe::Universe()
{
    _core = nullptr;
    _currentWorld = "none";
    _worlds["none"] = new World(*this);
    _eventbus = eventbus::EventBus();
}

Universe::Universe(core::Core& core) : _core(&core)
{

}

Universe::~Universe()
{
    for (auto& e : _worlds) {
        delete e.second;
    }
    _worlds.clear();
}

void Universe::init()
{
    if (_worlds.count(_currentWorld) == 0) return;
    if (_worlds.at(_currentWorld) == nullptr) return;

    _worlds.at(_currentWorld)->init();
}

void Universe::update()
{
    if (_worlds.count(_currentWorld) == 0) return;
    if (_worlds.at(_currentWorld) == nullptr) return;

    _worlds.at(_currentWorld)->update();
}

void Universe::render()
{
    if (_worlds.count(_currentWorld) == 0) return;
    if (_worlds.at(_currentWorld) == nullptr) return;

    _worlds.at(_currentWorld)->render();
}

eventbus::EventBus& Universe::getEventBus()
{
    return _eventbus;
}

core::Core& Universe::getCore()
{
    if (_core == nullptr)
        throw std::exception();

    return *_core;
}

World& Universe::createWorld(const std::string& name)
{
    if (_worlds.count(name) > 0)
        throw std::exception();

    auto newWorld = new World(*this);

    _worlds[name] = newWorld;

    return *newWorld;
}

bool Universe::hasWorld(const std::string& name) const
{
    return _worlds.count(name) > 0;
}

World& Universe::getWorld(const std::string& name) const
{
    if (_worlds.count(name) == 0)
        throw std::exception();
    if (_worlds.at(name) == nullptr)
        throw std::exception();

    return *_worlds.at(name);
}

World& Universe::getCurrentWorld() const
{
    if (_worlds.count(_currentWorld) == 0)
        throw std::exception();
    if (_worlds.at(_currentWorld) == nullptr)
        throw std::exception();

    return *_worlds.at(_currentWorld);
}

void Universe::setCurrentWorld(const std::string& name)
{
    if (_worlds.count(name) == 0)
        throw std::exception();
    if (_worlds.at(name) == nullptr)
        throw std::exception();

    _currentWorld = name;
}

void Universe::deleteWorld(const std::string& name)
{
    if (_worlds.count(name) == 0)
        throw std::exception();
    if (_worlds.at(name) == nullptr)
        throw std::exception();

    delete _worlds[name];
    _worlds.erase(name);
}

std::vector<std::string> Universe::getWorldNames() const
{
    std::vector<std::string> names;

    for (auto& pair: _worlds) {
        names.push_back(pair.first);
    }

    return names;
}
