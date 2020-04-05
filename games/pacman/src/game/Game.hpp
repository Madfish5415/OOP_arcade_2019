/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../../../game/AGame.hpp"
#include "../../../../engine/event/Collision.hpp"

namespace pacman {

class Game : public game::AGame {
   public:
    Game(engine::ecs::Universe& universe);
    ~Game();

   public:
    void init() override;
    void destroy() override;

   public:
    void receiveCollision(engine::event::Collision& event);
};

};  // namespace pacman

#endif /* !GAME_HPP_ */