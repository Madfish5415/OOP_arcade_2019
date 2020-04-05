/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Renderr.hpp
*/

#ifndef SFML_RENDERR_HPP
#define SFML_RENDERR_HPP

#include <SDL2/SDL.h>

#include <memory>

#include "../../../../engine/ecs/Entity.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/system/ARender.hpp"
#include "../../../graphical/AGraphical.hpp"

namespace sdl {

namespace system {

class Render : public engine::system::ARender {
   public:
    Render(engine::ecs::World& world, SDL_Renderer* win);
    ~Render() override;

   public:
    void init() override;
    void update() override;
    void render() override;

   private:
    SDL_Renderer& renderer;
};

}  // namespace system

}  // namespace sdl

#endif  // SFML_RENDERR_HPP
