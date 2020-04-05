/*
** EPITECH PROJECT, 2020
** engine
** File description:
** Physics.cpp
*/

#include "Physics.hpp"

#include <vector>

#include "../component/Hitbox.hpp"
#include "../component/Motion.hpp"
#include "../component/Transform.hpp"
#include "../ecs/Universe.hpp"
#include "../ecs/World.hpp"

using namespace engine;
using namespace system;

Physics::Physics(ecs::World& world) : ecs::ASystem(world)
{
}

Physics::~Physics() = default;

void Physics::init()
{
}

void Physics::update()
{
    std::vector<std::reference_wrapper<ecs::Entity>> entities = _world.getEntities<component::Hitbox, component::Transform>();

    for (std::reference_wrapper<ecs::Entity>& ent : entities) {
        auto& transform = (ent.get()).getComponent<component::Transform>();
        auto& hitbox = (ent.get()).getComponent<component::Hitbox>();

        for (std::reference_wrapper<ecs::Entity>& ent2 : entities) {
            if (&ent.get() == &ent2.get())
                continue;

            auto& transform2 = (ent2.get()).getComponent<component::Transform>();
            auto& hitbox2 = (ent2.get()).getComponent<component::Hitbox>();

            if (transform.position.x < transform2.position.x + hitbox2.width &&
                transform2.position.x < transform.position.x + hitbox.width &&
                transform.position.y < transform2.position.y + hitbox2.height &&
                transform2.position.y < transform.position.y + hitbox.height) {
                auto collision = new event::Collision(ent.get(), ent2.get());
                _world.getUniverse().getEventBus().publish<event::Collision>(*collision);
                delete collision;
            }
        }
    }
}

void Physics::render()
{
}
