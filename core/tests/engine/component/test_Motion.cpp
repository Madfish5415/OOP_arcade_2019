/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_AAI.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/component/Motion.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;
Test(Motion, TestCtorMotion)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanMotion = pacman.addComponent<engine::component::Motion>();
    auto& motionTest = pacman.getComponent<engine::component::Motion>();
    cr_assert_eq(&pacmanMotion, &motionTest);
}