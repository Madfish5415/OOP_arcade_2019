/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Movement.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/system/Movement.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/component/Motion.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;

Test(Movement, TestCtorMovement)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);

    auto& movementSystem = world.addSystem<system::Movement>();
    cr_assert_eq(&movementSystem, &movementSystem);
}

Test(Movement, TestInitMovement)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);

    auto& movementSystem = world.addSystem<system::Movement>();
    movementSystem.init();
    cr_assert_eq(&movementSystem, &movementSystem);
}

Test(Movement, TestUpdateMovementAcceleration)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();
    auto& movementSystem = world.addSystem<system::Movement>();
    type::Vector2D vec(5, 8);

    auto& pacmanMotion = pacman.addComponent<component::Motion>(type::Vector2D(3, 3));
    auto& pacmanTransform = pacman.addComponent<component::Transform>(vec, 12);
    movementSystem.init();
    movementSystem.update();
    cr_assert_eq(pacmanTransform.position.x, 8);
    cr_assert_eq(pacmanTransform.position.y, 11);
}

Test(Movement, TestRenderMovement)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);

    auto& movementSystem = world.addSystem<system::Movement>();
    movementSystem.render();
    cr_assert_eq(&movementSystem, &movementSystem);
}