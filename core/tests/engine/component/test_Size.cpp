/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Size.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/component/Size.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;
Test(Hitbox, TestCtorSizeOneParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanSize = pacman.addComponent<engine::component::Size>();
    cr_assert_eq(pacmanSize.width, 0);
    cr_assert_eq(pacmanSize.height, 0);
}

Test(Hitbox, TestCtorSizeTwoParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanSize = pacman.addComponent<engine::component::Size>(5);
    cr_assert_eq(pacmanSize.width, 5);
    cr_assert_eq(pacmanSize.height, 0);
}

Test(Hitbox, TestCtorSizeThreeParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanSize = pacman.addComponent<engine::component::Size>(3, 22);
    cr_assert_eq(pacmanSize.width, 3);
    cr_assert_eq(pacmanSize.height, 22);
}