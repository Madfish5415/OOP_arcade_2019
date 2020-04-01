/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Movement.hpp
*/

#ifndef OOP_ARCADE_2019_MOVEMENT_HPP
#define OOP_ARCADE_2019_MOVEMENT_HPP

#include "../component/Motion.hpp"
#include "../component/Transform.hpp"
#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {

class Movement : public ecs::ASystem {
   public:
    explicit Movement(ecs::World& world);
    ~Movement() override;

   public:
    void init() override;
    void update() override;
    void render() override;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_MOVEMENT_HPP
