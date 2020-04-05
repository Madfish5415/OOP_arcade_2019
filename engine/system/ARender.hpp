/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.hpp
*/

#ifndef OOP_ARCADE_2019_ARENDER_SYSTEM_HPP
#define OOP_ARCADE_2019_ARENDER_SYSTEM_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {

    /** \brief The Abstract Class used to manage all the Render components */
class ARender : public ecs::ASystem {
   public:
    /** \brief Constructor of the ARender
   * \param world the world which the system belongs to
   **/
    explicit ARender(ecs::World& world);

    /** \brief Destructor of the ARender set as default*/
    ~ARender() override = 0;

   public:
    /** \brief Initialize the system*/
    void init() override = 0;

    /** \brief Update the system and its Render component*/
    void update() override = 0;

    /** \brief Render of the system, used to draw the sprites */
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_ARENDER_SYSTEM_HPP
