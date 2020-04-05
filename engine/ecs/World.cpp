/*
** EPITECH PROJECT, 2020
** engine
** File description:
** World.cpp
*/

#include "World.hpp"

#include <algorithm>

#include "../../core/src/core/Core.hpp"

using namespace engine;
using namespace ecs;

World::World(Universe& universe) : _universe(universe)
{
}

World::~World()
{
    for (auto& ent_ref : _entities) {
        delete &ent_ref.get();
    }
    _entities.clear();

    for (auto& pair : _groups) {
        pair.second.clear();
    }
    _groups.clear();

    for (auto& pair : _systems) {
        delete &pair.second.get();
    }
    _systems.clear();
}

void World::init()
{
    for (auto& system : _systems) {
        system.second.get().init();
    }
}

void World::update()
{
    for (auto& system : _systems) {
        system.second.get().update();
    }
}

void World::render()
{
    for (auto& system : _systems) {
        system.second.get().render();
    }
}

Universe& World::getUniverse() const
{
    return _universe;
}

Entity& World::createEntity()
{
    auto entity = new Entity(*this);

    _entities.emplace_back(std::ref(*entity));

    return *entity;
}

void World::deleteEntity(Entity& entity)
{
    if (std::find_if(_entities.begin(), _entities.end(), [&entity](auto& ent) {
      return &ent.get() == &entity;
    }) == _entities.end()) return;

    for (auto& group : _groups) {
        if (hasGroup(entity, group.first)) {
            group.second.erase(std::find_if(group.second.begin(), group.second.end(), [&entity](auto& ent) {
              return &ent.get() == &entity;
            }));
        }
    }

    _entities.erase(std::find_if(_entities.begin(), _entities.end(), [&entity](auto& ent) {
      return &ent.get() == &entity;
    }));

    delete &entity;
}

void World::addToGroup(Entity& entity, const std::string& group)
{
    if (hasGroup(entity, group)) return;

    if (_groups.count(group) > 0) {
        _groups[group].emplace_back(entity);
    } else {
        std::vector<std::reference_wrapper<Entity>> list {};
        list.emplace_back(entity);
        _groups[group] = list;
    }
}

bool World::hasGroup(Entity& entity, const std::string& group) const
{
    if (_groups.count(group) == 0)
        return false;

    return std::find_if(_groups.at(group).begin(), _groups.at(group).end(), [&entity](auto& ent) {
      return &ent.get() == &entity;
    }) != _groups.at(group).end();
}

std::vector<std::reference_wrapper<Entity>>& World::getGroup(const std::string& group) const
{
    if (_groups.count(group) == 0)
        throw std::exception();

    return const_cast<std::vector<std::reference_wrapper<Entity>>&>(_groups.at(group));
}

void World::removeFromGroup(Entity& entity, const std::string& group)
{
    if (_groups.count(group) == 0)
        throw std::exception();

    auto ent_it = std::find_if(_groups.at(group).begin(), _groups.at(group).end(), [&entity](auto& ent) {
      return &ent.get() == &entity;
    });

    if (ent_it != _groups.at(group).end()) _groups.at(group).erase(ent_it);
}

template <>
engine::system::AAudio& World::addSystem<engine::system::AAudio>() {
    std::type_index id = typeid(engine::system::AAudio);

    for (auto& s : _systems) {
        if (s.first == id)
            throw std::exception();
    }

    engine::system::AAudio* system = &(getUniverse().getCore().getCurrentGraphical().createAudioSystem(*this));

    std::reference_wrapper<ASystem> ref_wrap = std::ref(*system);

    _systems.emplace(id, ref_wrap);

    return *system;
}

template <>
engine::system::AAnimations& World::addSystem<engine::system::AAnimations>() {
    std::type_index id = typeid(engine::system::AAnimations);

    for (auto& s : _systems) {
        if (s.first == id)
            throw std::exception();
    }

    engine::system::AAnimations* system = &(getUniverse().getCore().getCurrentGraphical().createAnimationsSystem(*this));

    std::reference_wrapper<ASystem> ref_wrap = std::ref(*system);

    _systems.emplace(id, ref_wrap);

    return *system;
}

template <>
engine::system::ARender& World::addSystem<engine::system::ARender>() {
    std::type_index id = typeid(engine::system::ARender);

    for (auto& s : _systems) {
        if (s.first == id)
            throw std::exception();
    }

    engine::system::ARender* system = &(getUniverse().getCore().getCurrentGraphical().createRenderSystem(*this));

    std::reference_wrapper<ASystem> ref_wrap = std::ref(*system);

    _systems.emplace(id, ref_wrap);

    return *system;
}