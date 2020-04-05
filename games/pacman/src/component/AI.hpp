/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "../../../engine/component/AAI.hpp"
#include "../../../engine/ecs/Entity.hpp"

namespace pacman {
    namespace component {
        class AI : public engine::component::AAI {
            public:
                AI(engine::ecs::Entity& entity);
                ~AI();
        };
    };
};

#endif /* !AI_HPP_ */
