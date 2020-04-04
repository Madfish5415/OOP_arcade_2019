/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>

namespace game {

class IGame {
   public:
    virtual ~IGame() = default;

    virtual std::string getName() = 0;

    virtual void init() = 0;
    virtual void destroy() = 0;
};

};  // namespace game

#endif /* !IGAME_HPP_ */