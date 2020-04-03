/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.hpp
*/

#ifndef OOP_ARCADE_2019_SIZE_HPP
#define OOP_ARCADE_2019_SIZE_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

class Size : public ecs::AComponent {
   public:
    explicit Size(ecs::Entity& entity, int width = 0, int height = 0);
    ~Size() override;

   public:
    int width;
    int height;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_SIZE_HPP
