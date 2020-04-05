/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Motion.hpp
*/

#ifndef OOP_ARCADE_2019_MOTION_HPP
#define OOP_ARCADE_2019_MOTION_HPP

#include "../ecs/AComponent.hpp"
#include "../type/Vector2D.hpp"

namespace engine {

namespace component {

    /** \brief The Class used to manage the movement of entities */
class Motion : public ecs::AComponent {
   public:
    /** \brief Constructor of the Motion
    * \param entity the Entity which the component belongs to
    * \param velocity a Vector2D representing the speed in x and y
    * \param acceleration a Vector2D representing the acceleration in x and y
    **/
    explicit Motion(ecs::Entity& entity, type::Vector2D velocity = type::Vector2D(), type::Vector2D acceleration = type::Vector2D());

    /** \brief Destructor of the Motion set as default*/
    ~Motion() override;

   public:
    /** \brief a Vector2D representing the speed in x and y*/
    type::Vector2D velocity;

    /** \brief a Vector2D representing the acceleration in x and y */
    type::Vector2D acceleration;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_MOTION_HPP
