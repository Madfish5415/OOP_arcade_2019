/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Physics.hpp
*/

#ifndef OOP_ARCADE_2019_PHYSICS_HPP
#define OOP_ARCADE_2019_PHYSICS_HPP

#include "../component/Hitbox.hpp"
#include "../component/Transform.hpp"
#include "../ecs/ASystem.hpp"
#include "../event/Collision.hpp"

namespace engine {

namespace system {

class Physics : public ecs::ASystem {
   public:
    explicit Physics(ecs::World& world);
    ~Physics() override;

   public:
    void init() override;
    void update() override;
    void render() override;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_PHYSICS_HPP
