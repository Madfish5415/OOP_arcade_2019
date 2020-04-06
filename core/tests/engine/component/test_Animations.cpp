/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Animations.cpp
*/

#include <criterion/criterion.h>
#include "../../../../engine/component/Animations.hpp"
#include "../../../src/core/Core.hpp"

using namespace engine;
Test(Animations, TestCtorAnimations)
{
    ecs::Universe universe = ecs::Universe();
    std::string name = "test";
    ecs::World& world = universe.createWorld(name);
    ecs::Entity& pacman = world.createEntity();
auto list =
        new const std::map<std::string, engine::type::Animation> {std::make_pair("OnSelect", engine::type::Animation(0, 14, 100))};
    auto& pacmanAnimations = pacman.addComponent<engine::component::Animations>(*list);
    auto& animationTest = pacman.getComponent<engine::component::Animations>();
    cr_assert_eq(&(pacmanAnimations.list), &(animationTest.list));
}