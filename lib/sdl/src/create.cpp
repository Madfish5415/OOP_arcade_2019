/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** createSFML.cpp
*/

#include "../../../engine/eventbus/EventBus.hpp"
#include "../../graphical/IGraphical.hpp"
#include "graphical/Graphical.hpp"

extern "C" graphical::IGraphical* create(engine::eventbus::EventBus& eventbus)
{
    return new sdl::Graphical(eventbus);
}