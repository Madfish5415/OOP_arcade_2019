/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AUser.hpp
*/

#ifndef OOP_ARCADE_2019_AUSER_HPP
#define OOP_ARCADE_2019_AUSER_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
    /** \brief The Abstract Class used to let the User play the games */
class AUser : public ecs::AComponent {
   public:
    /** \brief Constructor of the AUser
    * \param entity the Entity which the component belongs to
   **/
    explicit AUser(ecs::Entity& entity);

    /** \brief Destructor of the AUser set as default*/
    ~AUser() override = 0;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_AUSER_HPP
