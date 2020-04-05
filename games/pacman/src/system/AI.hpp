/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#ifndef AI_SYS_HPP_
#define AI_SYS_HPP_

#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/system/AAI.hpp"

namespace pacman {

namespace system {

class AI : public engine::system::AAI {
   public:
    AI(engine::ecs::World& world);
    ~AI();

   public:
    void init() override;
    void update() override;
    void render() override;
};

};  // namespace system

};  // namespace pacman

#endif /* !AI_HPP_ */