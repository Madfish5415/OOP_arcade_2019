/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "../../../engine/system/AAI.hpp"
#include "../../../engine/ecs/World.hpp"

namespace pacman {
    namespace system {
        class AI : public engine::system::AAI {
            public:
                AI(engine::ecs::World& world);
                ~AI();
    
                void init() override;
                void update() override;
                void render() override;
            protected:
            private:
        };
    };
};

#endif /* !AI_HPP_ */
