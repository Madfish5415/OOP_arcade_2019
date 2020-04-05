/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_USER_HPP
#define OOP_ARCADE_2019_USER_HPP


#include <vector>
#include <string>
#include "../../../../engine/component/AUser.hpp"

namespace menu {

namespace component {

class User : public engine::component::AUser {
   public:
    User(engine::ecs::Entity& entity);
    ~User() override;

   public:
    std::vector<std::string> observedGroups;
    std::pair<std::string, int> currentObserved;
};

}

}

#endif  // OOP_ARCADE_2019_USER_HPP
