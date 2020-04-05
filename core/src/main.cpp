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
    core::Core* core = new core::Core();

    core->loadGames();
    core->loadGraphics();

    engine::ecs::Universe& universe = core->getUniverse();

    core->getCurrentGraphical().init();
    core->getCurrentGame().init();

    universe.init();

    while (core->_run) {
        core->getCurrentGraphical().dispatchEvent();
        universe.update();
        universe.render();
        core->switchChecker();
    }

    //core.getCurrentGame().destroy();
    //core.getCurrentGraphical().destroy();

    delete core;

    return 0;
}