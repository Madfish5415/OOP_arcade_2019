/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../AGame.hpp"

class Game : public AGame {
    public:
        Game(Universe& universe, IGraphical& graph): AGame(universe, graph, "pacman") {}
        ~Game();
        void init() override;
        ecs::system::AFollow createFollow(): Follow() override {}
        ecs::system::AAI createAI(): AI() override {}
        ecs::system::AUser createUser(): User() override {}
    protected:
    private:
};

#endif /* !GAME_HPP_ */