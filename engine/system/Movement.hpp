/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Movement.hpp
*/

#ifndef OOP_ARCADE_2019_MOVEMENT_HPP
#define OOP_ARCADE_2019_MOVEMENT_HPP

#include "../component/Motion.hpp"
#include "../component/Transform.hpp"
#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {

    /** \brief The Abstract Class used to manage all the Movement components */
class Movement : public ecs::ASystem {
   public:
    /** \brief Constructor of the Movement
    * \param world the world which the system belongs to
    **/
    explicit Movement(ecs::World& world);

    /** \brief Destructor of the Movement set as default*/
    ~Movement() override;

   public:
    /** \brief Initialize the system*/
    void init() override;

    /** \brief Update the system and its User component*/
    void update() override;

    /** \brief Render of the system, not used here */
    void render() override;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_MOVEMENT_HPP
