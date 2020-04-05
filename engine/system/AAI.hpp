/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAI.hpp
*/

#ifndef OOP_ARCADE_2019_AAI_SYSTEM_HPP
#define OOP_ARCADE_2019_AAI_SYSTEM_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
    /** \brief The Abstract Class used to manage all the AI components */
class AAI : public ecs::ASystem {
   public:
    /** \brief Constructor of the AAI
    * \param world the world which the system belongs to
    **/
    explicit AAI(ecs::World& world);

    /** \brief Destructor of the AUser set as default*/
    ~AAI() override = 0;

   public:
    /** \brief Initialize the system*/
    void init() override = 0;

    /** \brief Update the system and its AI component*/
    void update() override = 0;

    /** \brief Render of the system, used only if there is something to render */
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_AAI_SYSTEM_HPP
