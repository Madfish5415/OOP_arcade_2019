/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Physics.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/system/Physics.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;

Test(Physics, TestCtorPhysics)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);

    auto& physicsSystem = world.addSystem<system::Physics>();
    cr_assert_eq(&physicsSystem, &physicsSystem);
}

Test(Physics, TestPhysicsSystem)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);

    auto& physicsSystem = world.addSystem<system::Physics>();
    physicsSystem.init();
    cr_assert_eq(&physicsSystem, &physicsSystem);
}

Test(Physics, TestUpdatePhysics)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();
    ecs::Entity& ghost = world.createEntity();
    auto& physicsSystem = world.addSystem<system::Physics>();
    type::Vector2D vec(5, 8);

    auto& ghostHitbox = ghost.addComponent<component::Hitbox>(40, 40);
    auto& pacmanHitbox = pacman.addComponent<component::Hitbox>(40, 40);
    auto& ghostTransform = ghost.addComponent<component::Transform>(vec, 12);
    auto& pacmanTransform = pacman.addComponent<component::Transform>(vec, 12);
    physicsSystem.init();
    physicsSystem.update();
    cr_assert_eq(pacmanTransform.position.x, ghostTransform.position.x);
    cr_assert_eq(pacmanTransform.position.y, ghostTransform.position.y);
}