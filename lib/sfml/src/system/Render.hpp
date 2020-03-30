/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Renderr.hpp
*/

#ifndef SFML_RENDERR_HPP
#define SFML_RENDERR_HPP

#include <memory>
#include "../../../graphical/AGraphical.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/ecs/Entity.hpp"
#include "../../../../engine/system/ARender.hpp"

namespace sfml {
    namespace system {
        class Render : public engine::system::ARender {
        public:
            explicit Render(engine::ecs::World& world);
            ~Render() = default;

            void init() override;
            void update() override;
            void render() override;
        };
    }
}

#endif // SFML_RENDERR_HPP
