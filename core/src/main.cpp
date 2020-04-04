/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main.cpp
*/

#include <filesystem>
#include <iostream>
#include <regex>
#include <string>

#include "../../engine/component/Animations.hpp"
#include "../../engine/component/Hitbox.hpp"
#include "../../engine/component/Motion.hpp"
#include "../../engine/component/Size.hpp"
#include "../../engine/component/Transform.hpp"
#include "../../engine/system/Movement.hpp"
#include "../../engine/system/Physics.hpp"
#include "core/Core.hpp"

int main()
{
    core::Core core = core::Core();

    core.loadGames();
    core.loadGraphics();

    engine::ecs::Universe& universe = core.getUniverse();

    core.getCurrentGraphical().init();

    std::string name = "menu";

    engine::ecs::World& world = universe.createWorld(name);
    engine::ecs::World& worldGet = universe.getWorld(name);
    universe.setCurrentWorld(name);
    engine::ecs::World& worldCur = universe.getCurrentWorld();

    if (&world != &worldGet)
        throw std::exception();

    if (&world != &worldCur)
        throw std::exception();

    if (!universe.hasWorld(name))
        throw std::exception();

    engine::ecs::Entity& pacman = world.createEntity();

    auto& pacmanMotion = pacman.addComponent<engine::component::Motion>();
    auto& motionTest = pacman.getComponent<engine::component::Motion>();

    if (&motionTest != &pacmanMotion)
        throw std::exception();

    world.addToGroup(pacman, "player");
    if (!world.hasGroup(pacman, "player"))
        throw std::exception();

    world.removeFromGroup(pacman, "player");
    if (world.hasGroup(pacman, "player"))
        throw std::exception();

    pacman.addComponent<engine::component::Hitbox>();
    pacman.addComponent<engine::component::Size>();
    pacman.addComponent<engine::component::Transform>();

    const std::vector<std::string> paths {"./assets/pacman.jpg", "./assets/pacman.jpg", "./assets/pacman.jpg"};
    auto &renderPacman = pacman.addComponent<engine::component::ARender>(paths);

    if (&renderPacman != &pacman.getComponent<engine::component::ARender>())
        throw std::exception();

    core.setCurrentGraphical("sdl2");

    universe.deleteWorld(name);

    return 0;
}