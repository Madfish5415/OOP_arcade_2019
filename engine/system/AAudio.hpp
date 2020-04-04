/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_AAUDIO_SYSTEM_HPP
#define OOP_ARCADE_2019_AAUDIO_SYSTEM_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {

class AAudio : public ecs::ASystem {
   public:
    explicit AAudio(ecs::World& world);
    ~AAudio() override = 0;

   public:
    void init() override = 0;
    void update() override = 0;
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_AAUDIO_SYSTEM_HPP
