/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Animations.hpp
*/

#ifndef SFML_ANIMATIONS_HPP
#define SFML_ANIMATIONS_HPP

#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/ecs/World.hpp"

namespace sfml {
    namespace system {
        class Animations : public engine::system::AAnimations {
        public:
            explicit Animations(engine::ecs::World& world);
            ~Animations() = default;
            void init() override;
            void update() override;
            void render() override;
        };
    }
}

#endif // SFML_ANIMATIONS_HPP
