/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>

class IGame {
    public:
        virtual ~IGame() = 0;
        virtual std::string getName() = 0;
        virtual void init() = 0;
        virtual void setGraphical(IGraphical& graph) = 0;
        virtual ecs::system::AFollow createFollow() = 0;
        virtual ecs::system::AAI createAI() = 0;
        virtual ecs::system::AUser createUser() = 0;
    protected:
    private:
};

#endif /* !IGAME_HPP_ */