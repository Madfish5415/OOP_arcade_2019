/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Close.hpp
*/

#ifndef OOP_ARCADE_2019_CLOSE_HPP
#define OOP_ARCADE_2019_CLOSE_HPP

#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

class Close : public eventbus::AEvent {
   public:
    Close();
    ~Close() override;
};

}  // namespace event

}  // namespace engine

#endif  // OOP_ARCADE_2019_CLOSE_HPP
