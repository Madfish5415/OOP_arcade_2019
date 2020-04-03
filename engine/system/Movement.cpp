/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Movement.cpp
*/

#include "Movement.hpp"

#include <vector>

#include "../component/Motion.hpp"
#include "../component/Transform.hpp"
#include "../ecs/World.hpp"

using namespace engine;
using namespace system;

Movement::Movement(ecs::World& world) : ecs::ASystem(world)
{
}

Movement::~Movement() = default;

void Movement::init()
{
}

void Movement::update()
{
    std::vector<std::reference_wrapper<ecs::Entity>> entities = _world.getEntities<component::Motion, component::Transform>();

    for (std::reference_wrapper<ecs::Entity>& ent : entities) {
        auto& transform = (ent.get()).getComponent<component::Transform>();
        auto& motion = (ent.get()).getComponent<component::Motion>();

        transform.position.x += motion.velocity.x;
        transform.position.y += motion.velocity.y;

        motion.velocity.x += motion.acceleration.x;
        motion.velocity.y += motion.acceleration.y;
    }
}

void Movement::render()
{
}
