/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.hpp
*/

#ifndef SFML_RENDER_HPP
#define SFML_RENDER_HPP

#include <map>

#include "../../../graphical/IGraphical.hpp"
#include "SFML/Graphics.hpp"

namespace sfml {
namespace component {

enum FLIPTYPE { NONE = 1, VERTICAL = 2, HORIZONTAL = 4 };

using sfmlAngle = float;

class Render : public engine::component::ARender {
   public:
    Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
    ~Render() override;

   public:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect srcRect, destRect;
    FLIPTYPE spriteFlip;
    sfmlAngle angle;
};

}  // namespace component
}  // namespace sfml

#endif  // SFML_RENDER_HPP
