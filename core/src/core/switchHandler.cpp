/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** switchHandler.cpp
*/

#include "switchHandler.hpp"

using namespace core;

switchHandler::switchHandler()
{
    state = false;
    type = "";
    name = "";
}

switchHandler::~switchHandler() = default;