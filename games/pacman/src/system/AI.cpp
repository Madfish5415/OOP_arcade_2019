/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#include "AI.hpp"

#include <cstdlib>
#include <iostream>

#include "../../../../engine/component/Hitbox.hpp"
#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Size.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/ecs/Universe.hpp"
#include "../component/AI.hpp"
#include "../component/User.hpp"

using namespace pacman;
using namespace system;

AI::AI(engine::ecs::World& world) : AAI(world)
{
}

AI::~AI()
{
}

void AI::init()
{
    _world.getUniverse().getEventBus().subscribe(*this, &AI::receiveIntersectCollision);
    initialized = 0;
    clk = clock();
}

void AI::update()
{
    auto aiList = _world.getEntities<component::AI>();

    if ((float(clock() - clk) / CLOCKS_PER_SEC >= 10) && !initialized) {
        initialized = 1;
        engine::ecs::Entity& upcase = _world.createEntity();
        upcase.addComponent<engine::component::Hitbox>(40, 40);
        upcase.addComponent<engine::component::Size>(40, 40);
        upcase.addComponent<engine::component::Transform>(engine::type::Vector2D(960, 470));
        _world.addToGroup(upcase, "upcase");
    }

    for (auto& aiRefWrap : aiList) {
        auto& aiEntityMotion = aiRefWrap.get().getComponent<engine::component::Motion>();
        auto& aiEntityAi = aiRefWrap.get().getComponent<component::AI>();

        if (aiEntityMotion.velocity.x == 0 && aiEntityMotion.velocity.y == 0) {
            int random_variable = std::rand();

            if (aiEntityAi.oldVelocity.x != 0) {
                switch (random_variable % 2) {
                    case 0:
                        aiEntityMotion.velocity.y = 1;
                        break;
                    case 1:
                        aiEntityMotion.velocity.y = -1;
                        break;
                    default:
                        throw std::exception();
                }
            } else if (aiEntityAi.oldVelocity.y != 0) {
                switch (random_variable % 2) {
                    case 0:
                        aiEntityMotion.velocity.x = 1;
                        break;
                    case 1:
                        aiEntityMotion.velocity.x = -1;
                        break;
                    default:
                        throw std::exception();
                }
            }
        } else {
            aiEntityAi.oldVelocity = aiEntityMotion.velocity;
        }
    }
}

void AI::render()
{
}

void AI::receiveIntersectCollision(engine::event::Collision& event)
{
    if (!event.entity1.getWorld().hasGroup(event.entity1, "ghost") ||
    (!event.entity2.getWorld().hasGroup(event.entity2, "intersect") &&
    !event.entity2.getWorld().hasGroup(event.entity2, "upcase")))
        return;

    auto& motion = event.entity1.getComponent<engine::component::Motion>();
    auto& transform = event.entity1.getComponent<engine::component::Transform>();
    auto& hitbox = event.entity1.getComponent<engine::component::Hitbox>();
    auto& transform2 = event.entity2.getComponent<engine::component::Transform>();
    auto& hitbox2 = event.entity2.getComponent<engine::component::Hitbox>();

    if (transform2.position.x - 2 <= transform.position.x && transform.position.x + hitbox.width <= transform2.position.x + hitbox2.width + 2 &&
        transform2.position.y - 2 <= transform.position.y && transform.position.y + hitbox.height <= transform2.position.y + hitbox2.height + 2) {

        if (event.entity2.getWorld().hasGroup(event.entity2, "upcase")) {
            motion.velocity.x = 0;
            motion.velocity.y = -1;
            return;
        }

        if (std::rand() % 20 != 0)
            return;

        int random_variable = std::rand();

        switch (random_variable % 4) {
            case 0:
                motion.velocity.x = 0;
                motion.velocity.y = 1;
                break;
            case 1:
                motion.velocity.x = 0;
                motion.velocity.y = -1;
                break;
            case 2:
                motion.velocity.x = 1;
                motion.velocity.y = 0;
                break;
            case 3:
                motion.velocity.x = -1;
                motion.velocity.y = 0;
                break;
            default:
                throw std::exception();
        }
    }
}
