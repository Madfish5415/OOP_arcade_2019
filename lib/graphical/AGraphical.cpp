/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical
*/

#include "AGraphical.hpp"

using namespace graphical;

AGraphical::AGraphical(const std::string& name, LIBTYPE type, engine::eventbus::EventBus& eventBus)
    : _eventBus(eventBus), _type(type), _name(name)
{
}

AGraphical::~AGraphical() = default;

std::string AGraphical::getName()
{
    return _name;
}

LIBTYPE AGraphical::getType()
{
    return _type;
}