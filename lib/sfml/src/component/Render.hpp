/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.hpp
*/

#ifndef SFML_RENDER_HPP
#define SFML_RENDER_HPP

#include <map>
#include "SFML/Graphics.hpp"
#include "Rect.hpp"
#include "../../../graphical/IGraphical.hpp"

namespace sfml {
    namespace component {
        enum FLIPTYPE {
            NONE = 1,
            VERTICAL = 2,
            HORIZONTAL = 4
        };

        using sfmlAngle = float;
        class Render : public engine::component::ARender {
        public:
            Render(engine::ecs::Entity& entity, std::vector<std::string>& paths);
            ~Render() = default;;
            sf::Sprite sprite;
            sf::Texture texture;
            sf::IntRect srcRect, destRect;
            FLIPTYPE spriteFlip;
            sfmlAngle angle;
        };
    }
}

#endif // SFML_RENDER_HPP
