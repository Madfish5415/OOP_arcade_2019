/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** WorldManager.hpp
*/

#ifndef OOP_ARCADE_2019_WORLDMANAGER_HPP
#define OOP_ARCADE_2019_WORLDMANAGER_HPP

#include "ASystem.hpp"
#include "EventBus.hpp"
#include "World.hpp"

namespace ecs {

class WorldManager {
   private:
    World& _world;
    std::vector<std::reference_wrapper<ASystem>> _systems{};
    ecs::EventBus& _eventbus;

   public:
    WorldManager(World& world) : _world(world)
    {
        auto* eventbus = new ecs::EventBus();
        _eventbus = *eventbus;
    }

    ~WorldManager() = default;

    void addSystem(ASystem& system)
    {
        _systems.push_back(system);
    }

    EventBus& getEventBus()
    {
        return _eventbus;
    }

    void init()
    {
        for (ASystem& i : _systems) i.init();
    }

    void update()
    {
        for (ASystem& i : _systems) i.update();
    }

    void render()
    {
        for (ASystem& i : _systems) i.render();
    }
}

}  // namespace ecs

#endif  // OOP_ARCADE_2019_WORLDMANAGER_HPP
