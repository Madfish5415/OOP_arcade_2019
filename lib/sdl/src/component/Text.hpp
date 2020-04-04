/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.hpp
*/

#ifndef OOP_ARCADE_2019_TEXT_HPP
#define OOP_ARCADE_2019_TEXT_HPP

#include "../../../../engine/component/AText.hpp"
#include "../../../graphical/IGraphical.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

namespace sdl {
namespace component {

using sdlAngle = double;

class Text : public engine::component::AText {
   public:
    Text(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths, SDL_Renderer *renderer);
    ~Text() override;

public:
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Surface *surface;
    SDL_Rect srcRect, destRect;
    SDL_RendererFlip spriteFlip;
    sdlAngle angle;
    SDL_Color color;
};

}  // namespace component

}  // namespace sdl

#endif  // OOP_ARCADE_2019_TEXT_HPP
