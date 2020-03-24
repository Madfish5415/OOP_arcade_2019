/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity.hpp
*/

#ifndef OOP_ARCADE_2019_ENTITY_HPP
#define OOP_ARCADE_2019_ENTITY_HPP

#include "World.hpp"
#include "AComponent.hpp"

namespace ecs {

class Entity {
   private:
    World& _world;
    bool _active;
    std::set<std::unique_ptr<AComponent>> _components {};

   public:
    Entity(World& world) : _world(world), _active(true) {};

    ~Entity() = default;

    bool isActive() { return _active };

    void disable() { _active = false };

    template <typename T>
    bool hasComponent() {

    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs) {

    }

    template <typename T>
    T& getComponent() {
         
    }
}

}

#endif // OOP_ARCADE_2019_ENTITY_HPP
