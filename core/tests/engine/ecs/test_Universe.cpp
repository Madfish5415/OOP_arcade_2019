/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Universe.cpp
*/

#include <criterion/criterion.h>
#include <iostream>

#include "../../../src/core/Core.hpp"

Test(Universe, constructor1)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    cr_assert_eq(true, true);
}

Test(Universe, constructor2)
{
    core::Core* testCore = new core::Core();
    engine::ecs::Universe universe = engine::ecs::Universe(*testCore);

    cr_assert_eq(true, true);
}

Test(Universe, getEventBus)
{
    core::Core* testCore = new core::Core();
    engine::ecs::Universe universe = engine::ecs::Universe(*testCore);

    universe.getEventBus().unsubscribe();

    cr_assert_eq(true, true);
}

Test(Universe, getCore)
{
    core::Core* testCore = new core::Core();
    engine::ecs::Universe universe = engine::ecs::Universe(*testCore);

    if (testCore == &universe.getCore())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Universe, createWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    universe.createWorld("test");

    cr_assert_eq(true, true);
}

Test(Universe, createWorldError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    universe.createWorld("test");

    try {
        universe.createWorld("test");
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(Universe, hasWorldTrue)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    universe.createWorld("test");

    if (universe.hasWorld("test"))
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Universe, hasWorldFalse)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    universe.createWorld("test");

    if (universe.hasWorld("test2"))
        cr_assert_eq(true, false);
    else
        cr_assert_eq(true, true);
}

Test(Universe, getWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& test = universe.createWorld("test");

    if (&test == &universe.getWorld("test"))
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Universe, getWorldError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    universe.createWorld("test");

    try {
        universe.getWorld("test2");
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(Universe, getWorldNames)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& test = universe.createWorld("test");
    engine::ecs::World& test2 = universe.createWorld("test2");

    std::vector<std::string> worldName {"none", "test", "test2"};

    if (worldName == universe.getWorldNames())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}

Test(Universe, deleteWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& test = universe.createWorld("test");

    universe.deleteWorld("test");

    cr_assert_eq(true, true);
}

Test(Universe, deleteWorldError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    universe.createWorld("test");

    try {
        universe.deleteWorld("test2");
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(Universe, setCurrentWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& test = universe.createWorld("test");

    universe.setCurrentWorld("test");

    cr_assert_eq(true, true);
}

Test(Universe, setCurrentWorldError)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    universe.createWorld("test");

    try {
        universe.setCurrentWorld("test2");
        cr_assert_eq(true, false);
    } catch (std::exception& e) {
        cr_assert_eq(true, true);
    }
}

Test(Universe, getCurrentWorld)
{
    engine::ecs::Universe universe = engine::ecs::Universe();

    engine::ecs::World& test = universe.createWorld("test");

    universe.setCurrentWorld("test");

    if (&test == &universe.getCurrentWorld())
        cr_assert_eq(true, true);
    else
        cr_assert_eq(true, false);
}