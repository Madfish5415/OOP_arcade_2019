/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Entity.cpp
*/

#include <criterion/criterion.h>

#include "../../../../engine/component/Hitbox.hpp"
#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../src/core/Core.hpp"

Test(Entity, constructor)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    cr_assert_eq(true, true);
}

Test(Entity, getWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    if (&test_entity.getWorld() == &world)
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Entity, addComponent)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();

    cr_assert_eq(true, true);
}

Test(Entity, alreadyHasComponent)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();

    try {
        test_entity.addComponent<engine::component::Motion>();
        cr_assert_eq(true, false);
    } catch(std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(Entity, hasComponent)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();

    if (test_entity.hasComponents<engine::component::Motion>())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Entity, hasNotComponent)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();

    if (test_entity.hasComponents<engine::component::Transform>())
        cr_assert_eq(true, false);
    else
        cr_assert_eq(true, true);
}

Test(Entity, hasComponentMultiple)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();
    test_entity.addComponent<engine::component::Hitbox>();

    if (test_entity.hasComponents<engine::component::Motion, engine::component::Hitbox>())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Entity, hasNotComponentMultiple)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();
    test_entity.addComponent<engine::component::Hitbox>();

    if (test_entity.hasComponents<engine::component::Motion, engine::component::Transform>())
        cr_assert_eq(true, false);
    else
        cr_assert_eq(true, true);
}

Test(Entity, getComponent)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    engine::component::Motion& cmp = test_entity.addComponent<engine::component::Motion>();

    if (&cmp == &test_entity.getComponent<engine::component::Motion>())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Entity, getComponentError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();

    try {
        test_entity.getComponent<engine::component::Transform>();
        cr_assert_eq(true, false);
    } catch(std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(Entity, removeComponent)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();
    test_entity.removeComponent<engine::component::Motion>();

    try {
        test_entity.getComponent<engine::component::Motion>();
        cr_assert_eq(true, false);
    } catch(std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(Entity, removeComponentError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::ecs::Entity& test_entity = world.createEntity();

    test_entity.addComponent<engine::component::Motion>();

    try {
        test_entity.removeComponent<engine::component::Transform>();
        cr_assert_eq(true, false);
    } catch(std::exception& e) {
        cr_assert_eq(true, true);
    }
}