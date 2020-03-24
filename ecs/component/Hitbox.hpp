/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Hitbox.hpp
*/

#ifndef OOP_ARCADE_2019_HITBOX_HPP
#define OOP_ARCADE_2019_HITBOX_HPP

#include "../AComponent.hpp"

namespace ecs {

class Hitbox : public AComponent {
   public:
    int w;
    int h;

   public:
    Hitbox(Entity& entity, int wParam = 0, int hParam = 0) : AComponent(entity), w(wParam), h(hParam) {};
    ~Hitbox() = default;
};

}

#endif // OOP_ARCADE_2019_HITBOX_HPP
