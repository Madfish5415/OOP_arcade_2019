/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Switch.hpp
*/

#ifndef OOP_ARCADE_2019_SWITCH_HPP
#define OOP_ARCADE_2019_SWITCH_HPP

#include <string>

#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

class Switch : public eventbus::AEvent {
   public:
    explicit Switch(std::string type = "", std::string name = "");
    ~Switch() override;

   public:
    std::string type;
    std::string name;
};

}  // namespace event

}  // namespace engine

#endif  // OOP_ARCADE_2019_SWITCH_HPP
