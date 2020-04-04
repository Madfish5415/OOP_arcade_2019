/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_ARCADE_2019_ACOMPONENT_HPP
#define OOP_ARCADE_2019_ACOMPONENT_HPP

namespace engine {
namespace ecs {
class Entity;
}
}

namespace engine {

namespace ecs {

class AComponent {
   protected:
    Entity& _entity;

   public:
    explicit AComponent(Entity& entity);
    virtual ~AComponent() = 0;

   public:
    Entity& getEntity() const;
};

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_ACOMPONENT_HPP
