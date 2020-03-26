/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame
*/

#ifndef AGAME_HPP_
#define AGAME_HPP_

#include <string>
#include "IGame.hpp"

class AGame : public IGame {
    public:
        AGame(Universe& universe, IGraphical& graph, std::string name): _universe(universe), _graph(graph), _name(name) {}
        virtual ~AGame() = 0;
        std::string getName() override {
            return _name;
        }
        void init() override = 0;
        void setGraphical(IGraphical& graph) override {
            _graph = graph;
        }
        ecs::system::AFollow createFollow() override = 0;
        ecs::system::AAI createAI() override = 0;
        ecs::system::AUser createUser() override = 0;
    protected:
        Universe& _universe;
        IGraphical& _graph;
    private:
        std::string _name;
};

#endif /* !AGAME_HPP_ */