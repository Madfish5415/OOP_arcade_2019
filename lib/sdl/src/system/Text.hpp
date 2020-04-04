/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.hpp
*/

#ifndef OOP_ARCADE_2019_TEXT_SYSTEM_HPP
#define OOP_ARCADE_2019_TEXT_SYSTEM_HPP

#include <SDL2/SDL.h>
#include <memory>

#include "../../../../engine/ecs/Entity.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/system/AText.hpp"
#include "../../../graphical/AGraphical.hpp"

namespace sdl {

namespace system {

class Text : public engine::system::AText {
   public:
    Text(engine::ecs::World& world, SDL_Renderer *win);
    ~Text() override;

   public:
    void init() override;
    void update() override;
    void render() override;

   private:
    SDL_Renderer& renderer;
};

}  // namespace system

}  // namespace sfml

#endif  // OOP_ARCADE_2019_TEXT_SYSTEM_HPP
