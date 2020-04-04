/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AText.hpp
*/

#ifndef OOP_ARCADE_2019_ATEXT_HPP
#define OOP_ARCADE_2019_ATEXT_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

class AText : public ecs::AComponent {
   public:
    explicit AText(ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths);
    ~AText() override = 0;

   public:
    std::string text;
    const std::vector<std::string> paths;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_ATEXT_HPP
