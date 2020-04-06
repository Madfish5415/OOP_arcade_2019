/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Transform.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/component/Transform.hpp"
#include "../../../src/core/Core.hpp"
#include "../../../../engine/type/Vector2D.hpp"

using namespace engine;
Test(Transform, TestCtorTransformOneParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();

    auto& pacmanSize = pacman.addComponent<engine::component::Transform>();
    cr_assert_eq(pacmanSize.position.x, 0);
    cr_assert_eq(pacmanSize.position.y, 0);
    cr_assert_eq(pacmanSize.layer, 0);
}

Test(Transform, TestCtorTransformTwoParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();
    type::Vector2D vec(5, 8);

    auto& pacmanSize = pacman.addComponent<engine::component::Transform>(vec);
    cr_assert_eq(pacmanSize.position.x, 5);
    cr_assert_eq(pacmanSize.position.y, 8);
    cr_assert_eq(pacmanSize.layer, 0);
}

Test(Transform, TestCtorTransformThreeParam)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();
    type::Vector2D vec(5, 8);

    auto& pacmanSize = pacman.addComponent<engine::component::Transform>(vec, 12);
    cr_assert_eq(pacmanSize.position.x, 5);
    cr_assert_eq(pacmanSize.position.y, 8);
    cr_assert_eq(pacmanSize.layer, 12);
}