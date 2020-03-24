/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Input.hpp
*/

#ifndef OOP_ARCADE_2019_INPUT_HPP
#define OOP_ARCADE_2019_INPUT_HPP

#include "../AComponent.hpp"

namespace ecs {

class Input : public AComponent {
   public:
    Input(Entity& entity) : AComponent(entity) {};
    ~Input() = default;
};

}

#endif // OOP_ARCADE_2019_INPUT_HPP
