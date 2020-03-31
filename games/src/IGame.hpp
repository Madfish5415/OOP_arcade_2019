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

        virtual const std::string getName() const = 0;

        virtual void init() = 0;
        virtual void destroy() = 0;
    protected:
    private:
};

#endif /* !IGAME_HPP_ */