/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Follow.hpp
*/

#ifndef OOP_ARCADE_2019_FOLLOW_HPP
#define OOP_ARCADE_2019_FOLLOW_HPP

namespace ecs {

namespace component {

class Follow : public AComponent {
   public:
    Entity& followed;

   public:
    Follow(Entity& entity, Entity& followedP)
        : AComponent(entity), followed(followedP){};
    ~Follow() = default;
};

}  // namespace component

}  // namespace ecs

#endif  // OOP_ARCADE_2019_FOLLOW_HPP
