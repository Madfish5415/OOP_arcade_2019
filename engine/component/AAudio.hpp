/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_AAUDIO_HPP
#define OOP_ARCADE_2019_AAUDIO_HPP

#include <utility>
#include <vector>
#include <string>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

class AAudio : public ecs::AComponent {
   public:
    AAudio(ecs::Entity& entity, const std::vector<std::string>& paths);
    ~AAudio() override = 0;

   public:
    const std::vector<std::string> paths;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_AAUDIO_HPP
