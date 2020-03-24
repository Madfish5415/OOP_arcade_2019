/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Follow.hpp
*/

#ifndef OOP_ARCADE_2019_FOLLOW_HPP
#define OOP_ARCADE_2019_FOLLOW_HPP

namespace ecs {

class Input : public AComponent {
   public:
    Entity& followed

   public:
    Input(Entity& entity, Entity& followedP) : AComponent(entity), followed(followedP) {};
    ~Input() = default;
};

}

#endif // OOP_ARCADE_2019_FOLLOW_HPP
