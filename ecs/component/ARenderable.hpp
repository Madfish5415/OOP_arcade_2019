/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARenderable.hpp
*/

#ifndef OOP_ARCADE_2019_ARENDERABLE_HPP
#define OOP_ARCADE_2019_ARENDERABLE_HPP

#include "../AComponent.hpp"

#include <string>

namespace ecs {

namespace component {

class ARenderable : public AComponent {
   public:
    ARenderable(Entity& entity) : AComponent(entity){};
    ~ARenderable() = default;
    virtual void setTexture(std::string name) = 0;
    virtual void setAnimation(
        std::string animationName, IAnimation animation) = 0;
    virtual std::string getCurrentAnimation() = 0;
    virtual void useAnimation(std::string animationName) = 0;
};

}  // namespace component

}  // namespace ecs

#endif  // OOP_ARCADE_2019_ARENDERABLE_HPP
