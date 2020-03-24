/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** WorldManager.hpp
*/

#ifndef OOP_ARCADE_2019_WORLDMANAGER_HPP
#define OOP_ARCADE_2019_WORLDMANAGER_HPP

#include <vector>

#include "ASystem.hpp"
#include "EventBus.hpp"
#include "World.hpp"

namespace ecs {

class WorldManager {
   private:
    World& _world;
    std::vector<std::reference_wrapper<ASystem>> _systems{};
    EventBus _eventbus;

   public:
    WorldManager(World& world) : _world(world), _eventbus(EventBus()) {};

    ~WorldManager() = default;

    void addSystem(ASystem& system)
    {
        _systems.push_back(system);
    };

    EventBus& getEventBus()
    {
        return _eventbus;
    };

    void init()
    {
        for (std::reference_wrapper<ASystem> i : _systems) i.init();
    };

    void update()
    {
        for (std::reference_wrapper<ASystem> i : _systems) i.update();
    };

    void render()
    {
        for (std::reference_wrapper<ASystem> i : _systems) i.render();
    };
};

}  // namespace ecs

#endif  // OOP_ARCADE_2019_WORLDMANAGER_HPP
