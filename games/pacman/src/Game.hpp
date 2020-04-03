/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../../src/AGame.hpp"

namespace pacman {
    class Game : public AGame {
        public:
            Game(Universe& universe);
            ~Game();
    
            void init() override;
            void destroy() override;
        protected:
        private:
    };
};

#endif /* !GAME_HPP_ */