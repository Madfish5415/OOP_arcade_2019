/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#include "AI.hpp"

#include <cstdlib>

#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Transform.hpp"
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
}

void AI::update()
{
    auto aiList = _world.getEntities<component::AI>();

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