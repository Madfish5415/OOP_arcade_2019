/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI.hpp
*/

#ifndef OOP_ARCADE_2019_AI_HPP
#define OOP_ARCADE_2019_AI_HPP

#include "../AComponent.hpp"

namespace ecs {

namespace component {

class AI : public AComponent {
   public:
    AI(Entity& entity) : AComponent(entity){};
    ~AI() = default;
};

}  // namespace component

}  // namespace ecs

#endif  // OOP_ARCADE_2019_AI_HPP
