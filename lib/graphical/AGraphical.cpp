/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical
*/

#include "AGraphical.hpp"

graphical::AGraphical::AGraphical(const std::string &name, LIBTYPE type, engine::eventbus::EventBus &eventBus) : _type(type), _name(name) {

}

std::string graphical::AGraphical::getName() {
    return _name;
}

graphical::IGraphical::LIBTYPE graphical::AGraphical::getType() {
    return _type;
}

graphical::AGraphical::~AGraphical() = default;