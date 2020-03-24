/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_ARCADE_2019_ACOMPONENT_HPP
#define OOP_ARCADE_2019_ACOMPONENT_HPP

namespace ecs {
    class Entity {};
}

#include "Entity.hpp"

namespace ecs {

class AComponent {
   protected:
    Entity& _entity;

   public:
    explicit AComponent(Entity& entity) : _entity(entity) {};
    virtual ~AComponent() = 0;
};

}

#endif // OOP_ARCADE_2019_ACOMPONENT_HPP
