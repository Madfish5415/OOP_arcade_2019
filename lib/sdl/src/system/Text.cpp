/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

using namespace sdl;
using namespace system;

Render::Render(engine::ecs::World& world, SDL_Renderer* rdr) : ARender(world), renderer(*rdr)
{
}

Render::~Render() = default;

void Render::init()
{
}

void Render::update()
{
}

void Render::render()
{
}