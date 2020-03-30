/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Audio.cpp
*/

#include "../../../engine/ecs/Entity.hpp"
#include "Audio.hpp"

sfml::component::Audio::Audio(engine::ecs::Entity &entity, const std::vector<std::string> &paths) : engine::component::AAudio(entity, paths) {

}
