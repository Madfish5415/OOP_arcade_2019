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

namespace sdl {
namespace component {

class Text : public engine::component::AText {
   public:
    Text(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths);
    ~Text() override;
};

}  // namespace component

}  // namespace sdl

#endif  // OOP_ARCADE_2019_TEXT_HPP
