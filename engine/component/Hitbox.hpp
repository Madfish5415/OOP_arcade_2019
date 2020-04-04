/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Hitbox.hpp
*/

#ifndef OOP_ARCADE_2019_HITBOX_HPP
#define OOP_ARCADE_2019_HITBOX_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

class Hitbox : public ecs::AComponent {
   public:
    explicit Hitbox(ecs::Entity& entity, int width = 0, int height = 0);
    ~Hitbox() override;

   public:
    int width;
    int height;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_HITBOX_HPP
