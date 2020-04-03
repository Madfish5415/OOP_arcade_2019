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

    engine::ecs::World& main_game = universe.createWorld("main_game");
    engine::ecs::Entity& my_pacman = main_game.createEntity();
    engine::ecs::Entity& red_ghost = main_game.createEntity();
    engine::ecs::Entity& blue_ghost = main_game.createEntity();
    engine::ecs::Entity& pink_ghost = main_game.createEntity();
    engine::ecs::Entity& orange_ghost = main_game.createEntity();

    main_game.addSystem<engine::system::AAnimations>();
    main_game.addSystem<engine::system::AAudio>();
    main_game.addSystem<engine::system::ARender>();
    main_game.addSystem<engine::system::Movement>();
    main_game.addSystem<engine::system::Physics>();

    const std::vector<std::string> pacmanTexture {"./assets/pacman.jpg", "./assets/pacman.jpg", "./assets/pacman.jpg"};
    my_pacman.addComponent<engine::component::ARender>(pacmanTexture);
    my_pacman.addComponent<engine::component::Hitbox>();
    my_pacman.addComponent<engine::component::Motion>();
    my_pacman.addComponent<engine::component::Size>();
    my_pacman.addComponent<engine::component::Transform>();
    //my_pacman.addComponent<engine::component::Animations>();

    //red_ghost.addComponent<engine::component::ARender>();
    red_ghost.addComponent<engine::component::Hitbox>();
    red_ghost.addComponent<engine::component::Motion>();
    red_ghost.addComponent<engine::component::Size>();
    red_ghost.addComponent<engine::component::Transform>();
    //red_ghost.addComponent<engine::component::Animations>();

    //blue_ghost.addComponent<engine::component::ARender>();
    blue_ghost.addComponent<engine::component::Hitbox>();
    blue_ghost.addComponent<engine::component::Motion>();
    blue_ghost.addComponent<engine::component::Size>();
    blue_ghost.addComponent<engine::component::Transform>();
    //blue_ghost.addComponent<engine::component::Animations>();

    //pink_ghost.addComponent<engine::component::ARender>();
    pink_ghost.addComponent<engine::component::Hitbox>();
    pink_ghost.addComponent<engine::component::Motion>();
    pink_ghost.addComponent<engine::component::Size>();
    pink_ghost.addComponent<engine::component::Transform>();
    //pink_ghost.addComponent<engine::component::Animations>();

    //orange_ghost.addComponent<engine::component::ARender>();
    orange_ghost.addComponent<engine::component::Hitbox>();
    orange_ghost.addComponent<engine::component::Motion>();
    orange_ghost.addComponent<engine::component::Size>();
    orange_ghost.addComponent<engine::component::Transform>();
    //orange_ghost.addComponent<engine::component::Animations>();

    main_game.addToGroup(my_pacman, "pacman");
    main_game.addToGroup(red_ghost, "ghost");
    main_game.addToGroup(blue_ghost, "ghost");
    main_game.addToGroup(pink_ghost, "ghost");
    main_game.addToGroup(orange_ghost, "ghost");

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

    universe.deleteWorld(name);

    return 0;
}