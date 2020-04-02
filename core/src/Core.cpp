/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include "Core.hpp"

using namespace core;

Core::Core()
{
}

Core::~Core()
{
}

void Core::loadGames()
{
}

void Core::loadGraphics()
{
}

engine::ecs::Universe& Core::getUniverse() const
{
    return <#initializer #>;
}

bool Core::hasGame(const std::string& name) const
{
    return false;
}

game::IGame& Core::getGame(const std::string& name) const
{
    return <#initializer #>;
}

game::IGame& Core::getCurrentGame() const
{
    return <#initializer #>;
}

void Core::setCurrentGame(const std::string& name)
{
}

bool Core::hasGraphical(const std::string& name) const
{
    return false;
}

graphical::IGraphical& Core::getGraphical(const std::string& name) const
{
    return <#initializer #>;
}

graphical::IGraphical& Core::getCurrentGraphical() const
{
    return <#initializer #>;
}

void Core::setCurrentGraphical(const std::string& name)
{
}
