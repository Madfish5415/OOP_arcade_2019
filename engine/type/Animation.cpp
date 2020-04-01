/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Animation.cpp
*/

#include "Animation.hpp"

using namespace engine;
using namespace type;

Animation::Animation(int row, int frames, int speed) : row(row), frames(frames), speed(speed)
{
}

Animation::~Animation() = default;
