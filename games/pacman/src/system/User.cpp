/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#include "User.hpp"

#include <iostream>

#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/ecs/Universe.hpp"
#include "../../../../engine/event/Close.hpp"
#include "../../../../engine/event/Switch.hpp"

using namespace pacman;
using namespace system;

User::User(engine::ecs::World& world) : AUser(world)
{
}

User::~User() = default;

void User::init()
{
    this->_world.getUniverse().getEventBus().subscribe(*this, &User::inputSubscriber);
    this->_world.getUniverse().getEventBus().subscribe(*this, &User::receivePacGumCollision);
    this->_world.getUniverse().getEventBus().subscribe(*this, &User::receiveGhostCollision);
}

void User::update()
{
    auto& pacgums = _world.getGroup("pacgum");
    auto& pacgumsSpecial = _world.getGroup("pacgumSpecial");
    int remaining = 0;

    for (auto& pacgum : pacgums) {
        if (pacgum.get().hasComponents<engine::component::ARender>())
            remaining++;
    }

    for (auto& pacgumSpecial : pacgumsSpecial) {
        if (pacgumSpecial.get().hasComponents<engine::component::ARender>())
            remaining++;
    }

    if (!remaining) {
        auto eventSwitch = new engine::event::Switch("game", "Menu");
        _world.getUniverse().getEventBus().publish(*eventSwitch);
        delete eventSwitch;
    }
}

void User::render()
{
}

void User::inputSubscriber(engine::event::Input& event)
{
    auto& playerList = _world.getGroup("pacman");

    for (auto& player : playerList) {
        auto& pacmanMotion = player.get().getComponent<engine::component::Motion>();

        if (event.code == event.KEY_LEFT) {
            pacmanMotion.velocity.x = -1;
            pacmanMotion.velocity.y = 0;
        } else if (event.code == event.KEY_UP) {
            pacmanMotion.velocity.x = 0;
            pacmanMotion.velocity.y = -1;
        } else if (event.code == event.KEY_RIGHT) {
            pacmanMotion.velocity.x = 1;
            pacmanMotion.velocity.y = 0;
        } else if (event.code == event.KEY_DOWN) {
            pacmanMotion.velocity.x = 0;
            pacmanMotion.velocity.y = 1;
        } else if (event.code == event.KEY_ESCAPE) {
            auto eventClose = new engine::event::Close();
            _world.getUniverse().getEventBus().publish(*eventClose);
            delete eventClose;
        } else if (event.code == event.KEY_BACKSPACE) {
            auto eventSwitch = new engine::event::Switch("game", "Menu");
            _world.getUniverse().getEventBus().publish(*eventSwitch);
            delete eventSwitch;
        } else if (event.code == event.KEY_P) {
            auto eventSwitch = new engine::event::Switch("game", "previous");
            _world.getUniverse().getEventBus().publish(*eventSwitch);
            delete eventSwitch;
        } else if (event.code == event.KEY_M) {
            auto eventSwitch = new engine::event::Switch("game", "next");
            _world.getUniverse().getEventBus().publish(*eventSwitch);
            delete eventSwitch;
        } else if (event.code == event.KEY_O) {
            auto eventSwitch = new engine::event::Switch("graph", "previous");
            _world.getUniverse().getEventBus().publish(*eventSwitch);
            delete eventSwitch;
        } else if (event.code == event.KEY_L) {
            auto eventSwitch = new engine::event::Switch("graph", "next");
            _world.getUniverse().getEventBus().publish(*eventSwitch);
            delete eventSwitch;
        } else if (event.code == event.KEY_R) {
            auto eventSwitch = new engine::event::Switch("game", "restart");
            _world.getUniverse().getEventBus().publish(*eventSwitch);
            delete eventSwitch;
        }
    }
}

void User::receivePacGumCollision(engine::event::Collision& event)
{
    if (!event.entity1.getWorld().hasGroup(event.entity1, "pacman") ||
        (!event.entity2.getWorld().hasGroup(event.entity2, "pacgum") &&
         !event.entity2.getWorld().hasGroup(event.entity2, "pacgumSpecial")))
        return;

    if (event.entity2.hasComponents<engine::component::ARender>())
        event.entity2.removeComponent<engine::component::ARender>();
}

void User::receiveGhostCollision(engine::event::Collision& event)
{
    if (!event.entity1.getWorld().hasGroup(event.entity1, "pacman") ||
        !event.entity2.getWorld().hasGroup(event.entity2, "ghost"))
        return;

    auto eventSwitch = new engine::event::Switch("game", "Menu");
    _world.getUniverse().getEventBus().publish(*eventSwitch);
    delete eventSwitch;
}