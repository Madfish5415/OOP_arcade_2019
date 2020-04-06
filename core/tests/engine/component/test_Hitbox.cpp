/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Hitbox.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/component/Hitbox.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;
Test(Hitbox, TestCtorHitboxOneParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanHitbox = pacman.addComponent<engine::component::Hitbox>();
    cr_assert_eq(pacmanHitbox.width, 0);
    cr_assert_eq(pacmanHitbox.height, 0);
}

Test(Hitbox, TestCtorHitboxTwoParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanHitbox = pacman.addComponent<engine::component::Hitbox>(5);
    cr_assert_eq(pacmanHitbox.width, 5);
    cr_assert_eq(pacmanHitbox.height, 0);
}

Test(Hitbox, TestCtorHitboxThreeParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanHitbox = pacman.addComponent<engine::component::Hitbox>(3, 22);
    cr_assert_eq(pacmanHitbox.width, 3);
    cr_assert_eq(pacmanHitbox.height, 22);
}