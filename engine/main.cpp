/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main.cpp
*/


#include <exception>
#include <iostream>

#include "component/Hitbox.hpp"
#include "component/Motion.hpp"
#include "component/Size.hpp"
#include "component/Transform.hpp"
#include "ecs/Universe.hpp"

using namespace engine;

int main()
{
    std::string name = "menu";
    ecs::Universe universe = ecs::Universe();

    ecs::World& world = universe.createWorld(name);
    ecs::World& worldGet = universe.getWorld(name);
    universe.setCurrentWorld(name);
    ecs::World& worldCur = universe.getCurrentWorld();

    if (&world != &worldGet)
        throw std::exception();

    if (&world != &worldCur)
        throw std::exception();

    if (!universe.hasWorld(name))
        throw std::exception();

    ecs::Entity& pacman = world.createEntity();

    auto& pacmanMotion = pacman.addComponent<component::Motion>();
    auto& motionTest = pacman.getComponent<component::Motion>();

    if (&motionTest != &pacmanMotion)
        throw std::exception();

    world.addToGroup(pacman, "player");
    if (!world.hasGroup(pacman, "player"))
        throw std::exception();

    world.removeFromGroup(pacman, "player");
    if (world.hasGroup(pacman, "player"))
        throw std::exception();

    pacman.addComponent<component::Hitbox>();
    pacman.addComponent<component::Size>();
    pacman.addComponent<component::Transform>();

    universe.deleteWorld(name);

    return 0;
}