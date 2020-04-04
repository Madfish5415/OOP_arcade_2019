/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

#include <exception>

#include "../../../graphical/AGraphical.hpp"

using namespace sfml;
using namespace component;

Text::Text(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths)
    : AText(entity, text, paths)
{
    if (!font.loadFromFile(paths[graphical::GRAPHIC]))
        throw std::exception();
    sfText.setFont(font);
    sfText.setString(text);
}

Text::~Text() = default;
