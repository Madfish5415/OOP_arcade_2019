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

using namespace pacman;
using namespace system;

User::User(engine::ecs::World& world) : AUser(world)
{
}

User::~User()
{
}

void User::init()
{
    this->_world.getUniverse().getEventBus().subscribe(*this, &User::inputSubscriber);
    // faire subscribe à la collide
}

void User::update()
{
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
        }
    }
}

void User::collideSubscriber()
{
    // je catch la collision avec un mur
    // je check dans quelle direction j'allais au moment de collide
    // je fais reculer mon pacman dans la position opposée
    // je mets le vecteur position à 0
    
    // je check la collision avec un ghost
    // je mets le isAlive du pacman à false

    // je check la collision avec un pacGum
    // je mets le isAlive du pacGum à false
}