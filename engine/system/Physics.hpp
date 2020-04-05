/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Physics.hpp
*/

#ifndef OOP_ARCADE_2019_PHYSICS_HPP
#define OOP_ARCADE_2019_PHYSICS_HPP

#include "../component/Hitbox.hpp"
#include "../component/Transform.hpp"
#include "../ecs/ASystem.hpp"
#include "../event/Collision.hpp"

namespace engine {

namespace system {

    /** \brief The Abstract Class used to manage all the Physics components */
class Physics : public ecs::ASystem {
   public:
    /** \brief Constructor of the Physics
    * \param world the world which the system belongs to
    **/
    explicit Physics(ecs::World& world);

    /** \brief Destructor of the Movement set as default*/
    ~Physics() override;

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

#endif  // OOP_ARCADE_2019_PHYSICS_HPP
