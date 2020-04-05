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
            auto& transform2 = (ent.get()).getComponent<component::Transform>();
            auto& hitbox2 = (ent.get()).getComponent<component::Hitbox>();

            if (transform.position.x < transform2.position.x + hitbox2.width &&
                transform2.position.x < transform.position.x + hitbox.width &&
                transform.position.y < transform2.position.y + hitbox2.height &&
                transform2.position.y < transform.position.y + hitbox.height) {
                auto collision = new event::Collision(ent.get(), ent2.get());
                _world.getUniverse().getEventBus().publish<event::Collision>(*collision);
                delete collision;

                if (ent.get().hasComponents<component::Motion>()) {
                    auto& motion = ent.get().getComponent<component::Motion>();

                    motion.velocity.x -= motion.acceleration.x;
                    motion.velocity.y -= motion.acceleration.y;

                    transform.position.x -= motion.velocity.x;
                    transform.position.y -= motion.velocity.y;

                    motion.velocity.x = 0;
                    motion.acceleration.x = 0;
                    motion.velocity.y = 0;
                    motion.acceleration.y = 0;
                }

                if (ent2.get().hasComponents<component::Motion>()) {
                    auto& motion2 = ent.get().getComponent<component::Motion>();

                    motion2.velocity.x -= motion2.acceleration.x;
                    motion2.velocity.y -= motion2.acceleration.y;

                    transform2.position.x -= motion2.velocity.x;
                    transform2.position.y -= motion2.velocity.y;

                    motion2.velocity.x = 0;
                    motion2.acceleration.x = 0;
                    motion2.velocity.y = 0;
                    motion2.acceleration.y = 0;
                }
            }
        }
    }
}

void Physics::render()
{
}
