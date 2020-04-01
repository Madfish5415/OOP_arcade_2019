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

class AUser : public ecs::AComponent {
   public:
    explicit AUser(ecs::Entity& entity);
    ~AUser() override = 0;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_AUSER_HPP
