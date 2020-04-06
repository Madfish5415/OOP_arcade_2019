/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Vector2d.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/type/Vector2D.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;

Test(Physics, TestCtorVector2dNoparam)
{
    type::Vector2D vctr = type::Vector2D();
    cr_assert_eq(vctr.x, 0);
    cr_assert_eq(vctr.y, 0);
}

Test(Physics, TestCtorVector2dOneparam)
{
    type::Vector2D vctr = type::Vector2D(2);
    cr_assert_eq(vctr.x, 2);
    cr_assert_eq(vctr.y, 0);
}

Test(Physics, TestCtorVector2dTwoparam)
{
    type::Vector2D vctr = type::Vector2D(2, 4);
    cr_assert_eq(vctr.x, 2);
    cr_assert_eq(vctr.y, 4);
}