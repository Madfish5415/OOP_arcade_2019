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

class AUser : public ecs::ASystem {
   public:
    explicit AUser(ecs::World& world);
    ~AUser() override = 0;

   public:
    void init() override = 0;
    void update() override = 0;
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_AUSER_SYSTEM_HPP
