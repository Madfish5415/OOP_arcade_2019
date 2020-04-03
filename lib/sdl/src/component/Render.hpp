/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.hpp
*/

#ifndef SDL_RENDER_HPP
#define SDL_RENDER_HPP

#include <map>


#include "../../../graphical/IGraphical.hpp"
#include "SDL2/SDL.h"

namespace sdl {
namespace component {

using sdlAngle = double;

class Render : public engine::component::ARender {
   public:
    Render(engine::ecs::Entity& entity, const std::vector<std::string>& paths, SDL_Renderer* renderer);
    ~Render() override;

   public:
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Rect srcRect, destRect;
    SDL_RendererFlip spriteFlip;
    sdlAngle angle;
};

}  // namespace component
}  // namespace sdl

#endif  // SDL_RENDER_HPP
