/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.hpp
*/

#ifndef OOP_ARCADE_2019_SIZE_HPP
#define OOP_ARCADE_2019_SIZE_HPP

namespace ecs {

class Size : public AComponent {
   public:
    int w;
    int h;

   public:
    Size(Entity& entity, int wParam = 0, int hParam = 0) : AComponent(entity), w(wParam), h(hParam) {};
    ~Size() = default;
};

}

#endif // OOP_ARCADE_2019_SIZE_HPP
