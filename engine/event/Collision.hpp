/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision.hpp
*/

#ifndef OOP_ARCADE_2019_COLLISION_HPP
#define OOP_ARCADE_2019_COLLISION_HPP

#include "../ecs/Entity.hpp"
#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

    /** \brief The class used to signal that two entites entered in collision */
class Collision : public eventbus::AEvent {
   public:
    /** \brief Constructor of the Collision class used to signal that two entites collided
     * \param ent1 The first entity that was in collision
     * \param ent2 The second entity that was in collision
     * */
    Collision(ecs::Entity& ent1, ecs::Entity& ent2);

    /** \brief Destructor of Collision set as default*/
    ~Collision() override;

   public:
    /** \brief The first entity of the collision */
    ecs::Entity& entity1;

    /** \brief The second entity of the collision */
    ecs::Entity& entity2;
};

}  // namespace event

}  // namespace engine

#endif  // OOP_ARCADE_2019_COLLISION_HPP
