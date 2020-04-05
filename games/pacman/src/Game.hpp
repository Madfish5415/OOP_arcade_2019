/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../../game/AGame.hpp"
#include "../../../engine/ecs/Universe.hpp"

namespace pacman {
    class Game : public game::AGame {
        public:
            Game(engine::ecs::Universe& universe);
            ~Game();
    
            void init() override;
            void destroy() override;
        protected:
        private:
    };
};

#endif /* !GAME_HPP_ */