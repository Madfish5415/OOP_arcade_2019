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

    /** \brief The Class used to manage the hitbox of entities */
class Hitbox : public ecs::AComponent {
   public:
    /** \brief Constructor of the Hitbox
     * \param entity the Entity which the component belongs to
     * \param width the size of the width of the hitbox
     * \param height the size of the height of the hitbox
     **/
    explicit Hitbox(ecs::Entity& entity, int width = 0, int height = 0);

    /** \brief Destructor of the Hitbox set as default*/
    ~Hitbox() override;

   public:
    /** \param width the size of the width of the hitbox */
    int width;

    /** \param height the size of the height of the hitbox */
    int height;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_HITBOX_HPP
