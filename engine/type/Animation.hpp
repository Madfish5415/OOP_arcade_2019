/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animation.hpp
*/

#ifndef OOP_ARCADE_2019_ANIMATION_HPP
#define OOP_ARCADE_2019_ANIMATION_HPP

namespace engine {

namespace type {

class Animation {
   public:
    explicit Animation(int row = 0, int frames = 0, int speed = 0);
    ~Animation();

   public:
    int row;
    int frames;
    int speed;
};

}

}

#endif // OOP_ARCADE_2019_ANIMATION_HPP
