/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AText.cpp
*/

#include "AText.hpp"

using namespace engine;
using namespace component;

AText::AText(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths) : AComponent(entity), text(text), paths(paths)
{
}

AText::~AText() = default;
