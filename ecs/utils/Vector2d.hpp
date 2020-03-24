/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Vector2d.hpp
*/

#ifndef OOP_ARCADE_2019_VECTOR2D_HPP
#define OOP_ARCADE_2019_VECTOR2D_HPP

namespace utils {

class Vector2d {
   public:
    int x;
    int y;

   public:
    Vector2d(xParam = 0, yParam = 0) : x(xParam), y(yParam) {};
};

}

#endif // OOP_ARCADE_2019_VECTOR2D_HPP
