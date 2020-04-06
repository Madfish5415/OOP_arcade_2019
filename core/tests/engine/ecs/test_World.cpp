/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_World.cpp
*/

#include <criterion/criterion.h>

#include "../../../src/core/Core.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/system/Movement.hpp"
#include "../../../../engine/system/Physics.hpp"
#include "../../../src/menu/system/User.hpp"

Test(World, constructor)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    cr_assert_eq(true, true);
}

Test(World, getUniverse)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    if (&world.getUniverse() == &universe)
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, createWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    cr_assert_eq(true, true);
}

Test(World, getEntities1)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    entity1.addComponent<engine::component::Transform>();
    auto& entity2 = world.createEntity();
    entity2.addComponent<engine::component::Transform>();
    auto& entity3 = world.createEntity();
    entity3.addComponent<engine::component::Transform>();
    auto& entity4 = world.createEntity();
    entity4.addComponent<engine::component::Motion>();
    auto& entity5 = world.createEntity();
    entity5.addComponent<engine::component::Motion>();

    if (world.getEntities<engine::component::Transform>().size() == 3 && world.getEntities<engine::component::Motion>().size() == 2)
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, getEntities2)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    if (world.getEntities<engine::component::Transform>().empty())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, deleteWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    world.deleteEntity(entity1);
    world.deleteEntity(entity2);
    world.deleteEntity(entity3);
    world.deleteEntity(entity4);
    world.deleteEntity(entity5);

    cr_assert_eq(true, true);
}

Test(World, addToGroup)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    world.addToGroup(entity1, "group1");
    world.addToGroup(entity2, "group1");
    world.addToGroup(entity3, "group1");
    world.addToGroup(entity4, "group2");
    world.addToGroup(entity5, "group2");

    cr_assert_eq(true, true);
}

Test(World, addToGroup2)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    world.addToGroup(entity1, "group1");
    world.addToGroup(entity2, "group1");
    world.addToGroup(entity3, "group1");
    world.addToGroup(entity4, "group2");
    world.addToGroup(entity5, "group2");

    world.addToGroup(entity1, "group2");
    world.addToGroup(entity2, "group2");
    world.addToGroup(entity3, "group2");
    world.addToGroup(entity4, "group2");
    world.addToGroup(entity5, "group2");

    cr_assert_eq(true, true);
}

Test(World, hasGroup)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    world.addToGroup(entity1, "group1");
    world.addToGroup(entity2, "group1");
    world.addToGroup(entity3, "group1");
    world.addToGroup(entity4, "group2");
    world.addToGroup(entity5, "group2");

    world.addToGroup(entity1, "group2");
    world.addToGroup(entity2, "group2");
    world.addToGroup(entity3, "group2");

    if (world.hasGroup(entity1, "group1") && world.hasGroup(entity1, "group2") && world.hasGroup(entity2, "group1") &&
            world.hasGroup(entity2, "group2") && world.hasGroup(entity3, "group1") && world.hasGroup(entity3, "group2") &&
            world.hasGroup(entity4, "group2"),
        world.hasGroup(entity5, "group2"))
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, hasNotGroup)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    if (!world.hasGroup(entity1, "tests1"))
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, getGroup)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    world.addToGroup(entity1, "group1");
    world.addToGroup(entity2, "group1");
    world.addToGroup(entity3, "group1");
    world.addToGroup(entity4, "group2");
    world.addToGroup(entity5, "group2");

    world.addToGroup(entity1, "group2");
    world.addToGroup(entity2, "group2");
    world.addToGroup(entity3, "group2");

    if (world.getGroup("group2").size() == 5 && world.getGroup("group1").size() == 3)
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, removeFromGroup)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    auto& entity1 = world.createEntity();
    auto& entity2 = world.createEntity();
    auto& entity3 = world.createEntity();
    auto& entity4 = world.createEntity();
    auto& entity5 = world.createEntity();

    world.addToGroup(entity1, "group1");
    world.addToGroup(entity2, "group1");
    world.addToGroup(entity3, "group1");
    world.addToGroup(entity4, "group2");
    world.addToGroup(entity5, "group2");

    world.addToGroup(entity1, "group2");
    world.addToGroup(entity2, "group2");
    world.addToGroup(entity3, "group2");

    world.removeFromGroup(entity1, "group1");
    world.removeFromGroup(entity2, "group1");
    world.removeFromGroup(entity3, "group1");
    world.removeFromGroup(entity4, "group2");
    world.removeFromGroup(entity5, "group2");

    world.removeFromGroup(entity1, "group2");
    world.removeFromGroup(entity2, "group2");
    world.removeFromGroup(entity3, "group2");

    if (world.getGroup("group2").size() == 0 && world.getGroup("group1").size() == 0)
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, addSystem)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();

    cr_assert_eq(true, true);
}

Test(World, alreadyHasSystem)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();

    try {
        world.addSystem<engine::system::Physics>();
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, hasSystem)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();

    if (world.hasSystems<engine::system::Physics>())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, hasNotSystem)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();

    if (world.hasSystems<engine::system::Movement>())
        cr_assert_eq(true, false);
    else
        cr_assert_eq(true, true);
}

Test(World, hasSystemMultiple)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();
    world.addSystem<engine::system::Movement>();

    if (world.hasSystems<engine::system::Physics, engine::system::Movement>())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, hasNotSystemMultiple)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();
    world.addSystem<engine::system::Movement>();

    if (world.hasSystems<engine::system::Physics, menu::system::User>())
        cr_assert_eq(true, false);
    else
        cr_assert_eq(true, true);
}

Test(World, getSystem)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    engine::system::Physics& cmp = world.addSystem<engine::system::Physics>();

    if (&cmp == &world.getSystem<engine::system::Physics>())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(World, getSystemError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();

    try {
        world.getSystem<engine::system::Movement>();
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, removeSystem)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();
    world.removeSystem<engine::system::Physics>();

    try {
        world.getSystem<engine::system::Physics>();
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, removeSystemError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& world = universe.createWorld("test_world");

    world.addSystem<engine::system::Physics>();

    try {
        world.removeSystem<engine::system::Movement>();
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}