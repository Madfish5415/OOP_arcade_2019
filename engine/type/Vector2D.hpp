/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Vector2D.hpp
*/

#ifndef OOP_ARCADE_2019_VECTOR2D_HPP
#define OOP_ARCADE_2019_VECTOR2D_HPP

namespace engine {

namespace type {

class Vector2D {
   public:
    explicit Vector2D(int x = 0, int y = 0);
    ~Vector2D();

   public:
    int x;
    int y;
};

}

}


#endif // OOP_ARCADE_2019_VECTOR2D_HPP
