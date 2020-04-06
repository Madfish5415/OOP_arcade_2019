/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Animations.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/type/Animation.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;

Test(Physics, TestCtorAnimationsNoparam)
{
    type::Animation anim = type::Animation();
    cr_assert_eq(anim.row, 0);
    cr_assert_eq(anim.frames, 0);
    cr_assert_eq(anim.speed, 0);
}

Test(Physics, TestCtorAnimationsOneparam)
{
    type::Animation anim = type::Animation(2);
    cr_assert_eq(anim.row, 2);
    cr_assert_eq(anim.frames, 0);
    cr_assert_eq(anim.speed, 0);
}

Test(Physics, TestCtorAnimationsTwoparam)
{
    type::Animation anim = type::Animation(2, 4);
    cr_assert_eq(anim.row, 2);
    cr_assert_eq(anim.frames, 4);
    cr_assert_eq(anim.speed, 0);
}

Test(Physics, TestCtorAnimationsThreeparam)
{
    type::Animation anim = type::Animation(2, 4, 6);
    cr_assert_eq(anim.row, 2);
    cr_assert_eq(anim.frames, 4);
    cr_assert_eq(anim.speed, 6);
}
