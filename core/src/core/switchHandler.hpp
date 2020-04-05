/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** switchHandler.hpp
*/

#ifndef OOP_ARCADE_2019_SWITCHHANDLER_HPP
#define OOP_ARCADE_2019_SWITCHHANDLER_HPP

#include <string>

namespace core {

class switchHandler {
   public:
    switchHandler();
    ~switchHandler();

   public:
    bool state;
    std::string type;
    std::string name;
};

}

#endif  // OOP_ARCADE_2019_SWITCHHANDLER_HPP
