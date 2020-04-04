/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

using namespace sdl;
using namespace component;

Text::Text(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths)
    : AText(entity, text, paths)
{
}

Text::~Text() = default;