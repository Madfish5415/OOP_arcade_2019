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

class AAI : public ecs::ASystem {
   public:
    explicit AAI(ecs::World& world);
    ~AAI() override = 0;

   public:
    void init() override = 0;
    void update() override = 0;
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_AAI_SYSTEM_HPP
