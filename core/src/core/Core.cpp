/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <regex>

#include "componentStore.hpp"
#include "systemStore.hpp"

using namespace core;

Core::Core()
{
    _currentGame = "";
    _currentGraphical = "";
    _universe = new engine::ecs::Universe(*this);
    _run = true;

    _universe->getEventBus().subscribe(*this, &Core::closeSubscriber);
    _universe->getEventBus().subscribe(*this, &Core::switchSubscriber);
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

    _games.emplace("test1", new DynamicLib<game::IGame>(_universe, "test1"));
    _games.emplace("test2", new DynamicLib<game::IGame>(_universe, "test2"));
    _games.emplace("Menu", new DynamicLib<game::IGame>(_universe, "Menu"));

    _currentGame = "Menu";
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
        for (auto& graph : _graphicals) _currentGraphical = graph.first;
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
    if (hasGame(name)) return _games.at(name)->get();

    throw std::exception();
}

game::IGame& Core::getCurrentGame() const
{
    if (hasGame(_currentGame)) return _games.at(_currentGame)->get();

    throw std::exception();
}

void Core::setCurrentGame(const std::string& name)
{
    if (!_games.count(name)) throw std::exception();

    if (_currentGame == name) return;

    _games[_currentGame]->get().destroy();

    _currentGame = name;

    _universe->getEventBus().unsubscribe();
    _universe->getEventBus().subscribe(*this, &Core::closeSubscriber);
    _universe->getEventBus().subscribe(*this, &Core::switchSubscriber);

    _games[name]->get().init();

    _universe->init();
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
    if (hasGame(name)) return _graphicals.at(name)->get();

    throw std::exception();
}

graphical::IGraphical& Core::getCurrentGraphical() const
{
    if (hasGraphical(_currentGraphical)) return _graphicals.at(_currentGraphical)->get();

    throw std::exception();
}

void Core::setCurrentGraphical(const std::string& name)
{
    if (!_graphicals.count(name)) throw std::exception();

    if (name == _currentGraphical) return;

    auto& lib = _graphicals[name]->get();
    auto& oldlib = _graphicals[_currentGraphical]->get();

    _currentGraphical = name;

    std::vector<componentStore<engine::component::AAudio, std::vector<std::string>>*> audioComponent;
    std::vector<componentStore<engine::component::ARender, std::vector<std::string>>*> renderComponent;
    std::vector<componentStore<engine::component::AText, std::string, std::vector<std::string>>*> textComponent;

    std::vector<systemStore<engine::system::AAnimations>*> animationsSystem;
    std::vector<systemStore<engine::system::AAudio>*> audioSystem;
    std::vector<systemStore<engine::system::ARender>*> renderSystem;

    for (auto& worldName : _universe->getWorldNames()) {
        auto& world = _universe->getWorld(worldName);

        for (auto& ent_ref : world.getEntities<engine::component::AAudio>()) {
            audioComponent.push_back(new componentStore<engine::component::AAudio, std::vector<std::string>>(
                ent_ref.get(), ent_ref.get().getComponent<engine::component::AAudio>().paths));
            ent_ref.get().removeComponent<engine::component::AAudio>();
        }

        for (auto& ent_ref : world.getEntities<engine::component::ARender>()) {
            renderComponent.push_back(new componentStore<engine::component::ARender, std::vector<std::string>>(
                ent_ref.get(), ent_ref.get().getComponent<engine::component::ARender>().paths));
            ent_ref.get().removeComponent<engine::component::ARender>();
        }

        for (auto& ent_ref : world.getEntities<engine::component::AText>()) {
            textComponent.push_back(new componentStore<engine::component::AText, std::string, std::vector<std::string>>(ent_ref.get(),
                ent_ref.get().getComponent<engine::component::AText>().text, ent_ref.get().getComponent<engine::component::AText>().paths));
            ent_ref.get().removeComponent<engine::component::AText>();
        }

        if (world.hasSystems<engine::system::AAnimations>()) {
            animationsSystem.push_back(new systemStore<engine::system::AAnimations>(world));
            world.removeSystem<engine::system::AAnimations>();
        }

        if (world.hasSystems<engine::system::AAudio>()) {
            audioSystem.push_back(new systemStore<engine::system::AAudio>(world));
            world.removeSystem<engine::system::AAudio>();
        }

        if (world.hasSystems<engine::system::ARender>()) {
            renderSystem.push_back(new systemStore<engine::system::ARender>(world));
            world.removeSystem<engine::system::ARender>();
        }
    }

    oldlib.destroy();

    lib.init();

    for (auto component : audioComponent) {
        component->addToEntity();
        delete component;
    }
    audioComponent.clear();

    for (auto component : renderComponent) {
        component->addToEntity();
        delete component;
    }
    renderComponent.clear();

    for (auto component : textComponent) {
        component->addToEntity();
        delete component;
    }
    textComponent.clear();

    for (auto system : audioSystem) {
        system->addToWorld();
        delete system;
    }
    audioSystem.clear();

    for (auto system : renderSystem) {
        system->addToWorld();
        delete system;
    }
    renderSystem.clear();

    for (auto system : animationsSystem) {
        system->addToWorld();
        delete system;
    }
    animationsSystem.clear();
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

void Core::switchSubscriber(engine::event::Switch& event)
{
    sHandler.state = true;
    sHandler.type = event.type;
    sHandler.name = event.name;
}

void Core::switchChecker()
{
    if (sHandler.state) {
        sHandler.state = false;
        if (sHandler.type == "graph") {
            setCurrentGraphical(sHandler.name);
        } else if (sHandler.type == "game") {
            setCurrentGame(sHandler.name);
        }
    }
}
