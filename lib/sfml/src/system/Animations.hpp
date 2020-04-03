/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Animations.hpp
*/

#ifndef SFML_ANIMATIONS_HPP
#define SFML_ANIMATIONS_HPP

#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/system/AAnimations.hpp"

namespace sfml {
namespace system {

class Animations : public engine::system::AAnimations {
   public:
    explicit Animations(engine::ecs::World& world);
    ~Animations() override;

   public:
    void init() override;
    void update() override;
    void render() override;
};
}  // namespace system
}  // namespace sfml

#endif  // SFML_ANIMATIONS_HPP
