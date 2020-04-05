/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAI.hpp
*/

#ifndef OOP_ARCADE_2019_AAI_HPP
#define OOP_ARCADE_2019_AAI_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

    /** \brief The Abstract Class used to create the AI component */
class AAI : public ecs::AComponent {
   public:
    /** \brief Constructor of the AAI
     * \param entity the Entity which the component belongs to
    **/
    explicit AAI(ecs::Entity& entity);

    /** \brief Destructor of the AAI set as default*/
    ~AAI() override = 0;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_AAI_HPP
