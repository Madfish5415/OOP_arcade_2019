/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ASystem.hpp
*/

#ifndef OOP_ARCADE_2019_ASYSTEM_HPP
#define OOP_ARCADE_2019_ASYSTEM_HPP

#include "World.hpp"
#include "EventBus.hpp"

namespace ecs {

class ASystem {
   public:
    ASystem() = default;
    virtual ~ASystem() = default;
    virtual void init(EventBus& eventbus) = 0;
    virtual void update(World& world) = 0;
    virtual void render(World& world) = 0;
};

}

#endif // OOP_ARCADE_2019_ASYSTEM_HPP
