/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.hpp
*/

#ifndef OOP_ARCADE_2019_ARENDER_HPP
#define OOP_ARCADE_2019_ARENDER_HPP

#include <vector>
#include <string>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

class ARender : public ecs::AComponent {
   public:
    ARender(ecs::Entity& entity, const std::vector<std::string>& paths);
    ~ARender() override = 0;

   public:
    const std::vector<std::string> paths;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_ARENDER_HPP
