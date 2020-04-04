/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#include "AI.hpp"
#include "../component/AI.hpp"
#include "../component/User.hpp"
#include "../../../engine/component/Transform.hpp"
#include "../../../engine/component/Motion.hpp"

using namespace pacman;
using namespace system;

AI::AI(engine::ecs::World& world): AAI(world) {}

AI::~AI()
{
}

void AI::init()
{
}

void AI::update()
{
    auto& playerList = _world.getGroup("pacman");
    auto iaList = _world.getEntities<component::AI>();

    for (auto& player : playerList) {
        auto& pacmanEntity = player.get(); 
        auto& pacmanPosition = pacmanEntity.getComponent<engine::component::Transform>();

        for (auto& iaRefWrap : iaList) {
            auto& iaEntity = iaRefWrap.get();
            auto& iaEntityPosition = iaEntity.getComponent<engine::component::Transform>();
            auto& iaEntityMotion = iaEntity.getComponent<engine::component::Motion>();

            int diffX = pacmanPosition.position.x - iaEntityPosition.position.x;
            int diffY = pacmanPosition.position.y - iaEntityPosition.position.y;

            int absDiffX = (diffX < 0) ? diffX - ( 2 * diffX) : diffX;
            int absDiffY = (diffY < 0) ? diffY - ( 2 * diffY) : diffY;

            if (absDiffX > absDiffY) {
                if (diffX > 0) {
                    iaEntityMotion.velocity.x = 1;
                    iaEntityMotion.velocity.y = 0;
                }
                else {
                    iaEntityMotion.velocity.x = -1;
                    iaEntityMotion.velocity.y = 0;
                }
            }
            else {
                if (diffY > 0) {
                    iaEntityMotion.velocity.x = 0;
                    iaEntityMotion.velocity.y = 1;
                }
                else {
                    iaEntityMotion.velocity.x = 0;
                    iaEntityMotion.velocity.y = -1;
                }
            }
        }
    }
}

void AI::render()
{
}