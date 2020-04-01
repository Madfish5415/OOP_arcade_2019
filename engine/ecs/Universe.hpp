/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.hpp
*/
#ifndef OOP_ARCADE_2019_UNIVERSE_HPP
#define OOP_ARCADE_2019_UNIVERSE_HPP

#include <functional>
#include <map>
#include <string>

namespace core {
class Core;
}

#include "../eventbus/EventBus.hpp"
#include "World.hpp"

namespace engine {

namespace ecs {

class Universe {
   private:
    std::map<std::string, World*> _worlds {};
    std::string _currentWorld;
    eventbus::EventBus _eventbus;
    core::Core *_core;

   public:
    Universe();
    Universe(core::Core& core);
    ~Universe();

   public:
    void init();
    void update();
    void render();

   public:
    eventbus::EventBus& getEventBus();
    core::Core& getCore();

   public:
    World& createWorld(const std::string& name);
    bool hasWorld(const std::string& name) const;
    World& getWorld(const std::string& name) const;
    World& getCurrentWorld() const;
    void setCurrentWorld(const std::string& name);
    void deleteWorld(const std::string& name);
};

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_UNIVERSE_HPP
