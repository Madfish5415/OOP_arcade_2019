/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#include "AI.hpp"

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
    auto& playerList = _world.getGroup("pacman");
    auto aiList = _world.getEntities<component::AI>();

    for (auto& player : playerList) {
        auto& pacmanEntity = player.get();
        auto& pacmanPosition = pacmanEntity.getComponent<engine::component::Transform>();

        for (auto& aiRefWrap : aiList) {
            auto& aiEntity = aiRefWrap.get();
            auto& aiEntityPosition = aiEntity.getComponent<engine::component::Transform>();
            auto& aiEntityMotion = aiEntity.getComponent<engine::component::Motion>();

            int diffX = pacmanPosition.position.x - aiEntityPosition.position.x;
            int diffY = pacmanPosition.position.y - aiEntityPosition.position.y;

            if (std::abs(diffX) > std::abs(diffY)) {
                if (diffX > 0) {
                    aiEntityMotion.velocity.x = 1;
                    aiEntityMotion.velocity.y = 0;
                } else {
                    aiEntityMotion.velocity.x = -1;
                    aiEntityMotion.velocity.y = 0;
                }
            } else {
                if (diffY > 0) {
                    aiEntityMotion.velocity.x = 0;
                    aiEntityMotion.velocity.y = 1;
                } else {
                    aiEntityMotion.velocity.x = 0;
                    aiEntityMotion.velocity.y = -1;
                }
            }
        }
    }
}

void AI::render()
{
}