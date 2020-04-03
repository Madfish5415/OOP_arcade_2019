/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Audio.cpp
*/

#include "Audio.hpp"

#include "../../../engine/ecs/Entity.hpp"

using namespace sfml;
using namespace component;

Audio::Audio(engine::ecs::Entity& entity, const std::vector<std::string>& paths) : engine::component::AAudio(entity, paths)
{
}

Audio::~Audio() = default;