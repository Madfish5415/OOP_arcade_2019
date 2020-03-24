/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Transform.hpp
*/

#ifndef OOP_ARCADE_2019_TRANSFORM_HPP
#define OOP_ARCADE_2019_TRANSFORM_HPP

#include "../AComponent.hpp"
#include "../utils/Vector2d.hpp"

namespace ecs {

class Transform : public AComponent {
   public:
    utils::Vector2d position;

   public:
    Transform(Entity& entity) : AComponent(entity) {};
    ~Transform() = default;
};

}

#endif // OOP_ARCADE_2019_TRANSFORM_HPP
