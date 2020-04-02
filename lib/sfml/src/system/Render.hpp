/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Renderr.hpp
*/

#ifndef SFML_RENDERR_HPP
#define SFML_RENDERR_HPP

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../graphical/AGraphical.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/ecs/Entity.hpp"
#include "../../../../engine/system/ARender.hpp"

namespace sfml {
    namespace system {
        class Render : public engine::system::ARender {
        public:
            Render(engine::ecs::World& world, sf::RenderWindow& win);
            ~Render() override;

            void init() override;
            void update() override;
            void render() override;
        private:
            sf::RenderWindow &window;
        };
    }
}

#endif // SFML_RENDERR_HPP