/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations.hpp
*/

#ifndef OOP_ARCADE_2019_ANIMATIONS_HPP
#define OOP_ARCADE_2019_ANIMATIONS_HPP

#include <map>

#include "../ecs/AComponent.hpp"
#include "../type/Animation.hpp"

namespace engine {

namespace component {

class Animations : public ecs::AComponent {
   public:
    Animations(ecs::Entity& entity, const std::map<std::string, type::Animation>& list);
    ~Animations() override;

   public:
    const std::map<std::string, type::Animation> list;
    std::string currentAnimation;
    int currentFrame;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_ANIMATIONS_HPP
