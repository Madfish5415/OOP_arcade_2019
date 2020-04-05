/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AUser.hpp
*/

#ifndef OOP_ARCADE_2019_AUSER_SYSTEM_HPP
#define OOP_ARCADE_2019_AUSER_SYSTEM_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {

    /** \brief The Abstract Class used to manage all the User components */
class AUser : public ecs::ASystem {
   public:
    /** \brief Constructor of the AUser
  * \param world the world which the system belongs to
  **/
    explicit AUser(ecs::World& world);

    /** \brief Destructor of the Physics set as default*/
    ~AUser() override = 0;

   public:
    /** \brief Initialize the system*/
    void init() override = 0;

    /** \brief Update the system and its Render component*/
    void update() override = 0;

    /** \brief Render of the system, not used here */
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_AUSER_SYSTEM_HPP
