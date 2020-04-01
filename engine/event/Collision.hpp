/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision.hpp
*/

#ifndef OOP_ARCADE_2019_COLLISION_HPP
#define OOP_ARCADE_2019_COLLISION_HPP

#include "../ecs/Entity.hpp"
#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

class Collision : public eventbus::AEvent {
   public:
    Collision(ecs::Entity& ent1, ecs::Entity& ent2);
    ~Collision() override;

   public:
    ecs::Entity& entity1;
    ecs::Entity& entity2;
};

}  // namespace event

}  // namespace engine

#endif  // OOP_ARCADE_2019_COLLISION_HPP
