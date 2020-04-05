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

    /** \brief The Class used to manage the position of entities */
class Transform : public ecs::AComponent {
   public:
    /** \brief Constructor of the Transform
   * \param entity the Entity which the component belongs to
   * \param position a Vector2D that represents the x and y position of the entity on screen
   * \param layer an int that represent the order for display (the components having this layer at 0 will be the first to be drawn)
   **/
    explicit Transform(ecs::Entity& entity, type::Vector2D position = type::Vector2D(), int layer = 0);

    /** \brief Destructor of the Transform set as default*/
    ~Transform() override;

   public:
    /** \brief position a Vector2D that represents the x and y position of the entity on screen*/
    type::Vector2D position;

    /** \brief layer an int that represent the order for display (the components having this layer at 0 will be the first to be drawn)*/
    int layer;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_TRANSFORM_HPP
