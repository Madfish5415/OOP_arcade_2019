/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Motion.hpp
*/

#ifndef OOP_ARCADE_2019_MOTION_HPP
#define OOP_ARCADE_2019_MOTION_HPP

#include "../AComponent.hpp"
#include "../utils/Vector2d.hpp"

namespace ecs {

namespace component {

class Motion : public AComponent {
   public:
    utils::Vector2d velocity;
    utils::Vector2d acceleration;

   public:
    Motion(Entity& entity) : AComponent(entity){};
    ~Motion() = default;
};

}  // namespace component

}  // namespace ecs

#endif  // OOP_ARCADE_2019_MOTION_HPP
