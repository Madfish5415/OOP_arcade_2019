/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** systemStore.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEMSTORE_HPP
#define OOP_ARCADE_2019_SYSTEMSTORE_HPP

#include <tuple>

#include "../../../engine/ecs/World.hpp"

template <typename T, typename... TArgs>
class systemStore {
   public:
    systemStore(engine::ecs::World &world, TArgs... args) : _world(world), _args(args...)
    {
    }

    ~systemStore() = default;

   public:
    void addToWorld()
    {
        std::apply([this](auto... args) { this->_world.template addSystem<T>(args...); }, _args);
    }

    void removeFromWorld()
    {
        _world.removeSystem<T>();
    }

   private:
    engine::ecs::World& _world;
    std::tuple<TArgs...> _args;
};

template <>
void systemStore<engine::system::AAudio>::addToWorld()
{
    std::apply([this]() { this->_world.template addSystem<engine::system::AAudio>(); }, _args);
}

template <>
void systemStore<engine::system::ARender>::addToWorld()
{
    std::apply([this]() { this->_world.template addSystem<engine::system::ARender>(); }, _args);
}

template <>
void systemStore<engine::system::AAnimations>::addToWorld()
{
    std::apply([this]() { this->_world.template addSystem<engine::system::AAnimations>(); }, _args);
}

#endif  // OOP_ARCADE_2019_SYSTEMSTORE_HPP
