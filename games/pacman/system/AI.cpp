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
    auto& pacmans = _world.getGroup("pacman");
    auto ia_list = _world.getEntities<component::AI>();

    for (auto& my_pacman : pacmans) {
        auto &the_pacman = my_pacman.get(); 
        auto& pacman_position = the_pacman.getComponent<engine::component::Transform>();

        for (auto& ia_ref_wrap : ia_list) {
            auto& ia_entity = ia_ref_wrap.get();
            auto& ia_entity_position = ia_entity.getComponent<engine::component::Transform>();
            auto& ia_entity_motion = ia_entity.getComponent<engine::component::Motion>();

            int diff_x = pacman_position.position.x - ia_entity_position.position.x;
            int diff_y = pacman_position.position.y - ia_entity_position.position.y;

            int abs_diff_x = diff_x;
            int abs_diff_y = diff_y;

            if (diff_x < 0)
                abs_diff_x = diff_x - (2 * diff_x);

            if (diff_y < 0)
                abs_diff_y = diff_y - (2 * diff_y);

            if (abs_diff_x > abs_diff_y) {
                if (diff_x > 0) {
                    ia_entity_motion.velocity.x = 1;
                    ia_entity_motion.velocity.y = 0;
                }
                else {
                    ia_entity_motion.velocity.x = -1;
                    ia_entity_motion.velocity.y = 0;
                }
            }
            else {
                if (diff_y > 0) {
                    ia_entity_motion.velocity.x = 0;
                    ia_entity_motion.velocity.y = 1;
                }
                else {
                    ia_entity_motion.velocity.x = 0;
                    ia_entity_motion.velocity.y = -1;
                }
            }
        }
    }
}

void AI::render()
{
}