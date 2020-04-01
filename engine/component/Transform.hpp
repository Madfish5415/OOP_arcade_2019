/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Transform.hpp
*/

#ifndef OOP_ARCADE_2019_TRANSFORM_HPP
#define OOP_ARCADE_2019_TRANSFORM_HPP

#include "../ecs/AComponent.hpp"
#include "../type/Vector2D.hpp"

namespace engine {

namespace component {

class Transform : public ecs::AComponent {
   public:
    explicit Transform(ecs::Entity& entity, type::Vector2D position = type::Vector2D(), int layer = 0);
    ~Transform() override;

   public:
    type::Vector2D position;
    int layer;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_TRANSFORM_HPP
