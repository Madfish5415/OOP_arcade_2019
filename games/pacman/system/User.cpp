/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#include "User.hpp"
#include "../../../engine/ecs/Universe.hpp"
#include "../../../engine/component/Motion.hpp"

using namespace pacman;
using namespace system;

User::User(engine::ecs::World& world): AUser(world) {}

User::~User()
{
}

void User::init()
{
    this->_world.getUniverse().getEventBus().subscribe(*this, &User::inputSubscriber);
}

void User::update()
{
}

void User::render()
{
}

void User::inputSubscriber(engine::event::Input& event)
{
    auto& pacmans = _world.getGroup("pacman");

    for (auto& my_pacman : pacmans) {
        auto &the_pacman = my_pacman.get();
        auto& pacman_motion = the_pacman.getComponent<engine::component::Motion>();
        if (event.code == event.KEY_LEFT) {
            pacman_motion.velocity.x = -1;
            pacman_motion.velocity.y = 0;
        }
        else if (event.code == event.KEY_UP) {
            pacman_motion.velocity.x = 0;
            pacman_motion.velocity.y = -1;
        }
        else if (event.code == event.KEY_RIGHT) {
            pacman_motion.velocity.x = 1;
            pacman_motion.velocity.y = 0;
        }
        else if (event.code == event.KEY_DOWN) {
            pacman_motion.velocity.x = 0;
            pacman_motion.velocity.y = 1;
        }
    }
}