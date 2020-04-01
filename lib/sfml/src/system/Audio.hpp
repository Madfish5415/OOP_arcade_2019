/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Audio.hpp
*/

#ifndef SFML_AUDIO_HPP
#define SFML_AUDIO_HPP

#include "../../../engine/system/AAudio.hpp"
#include "../../../engine/ecs/World.hpp"

namespace sfml {
    namespace system {
        class Audio : public engine::system::AAudio {
            public:
                explicit Audio(engine::ecs::World &world);
                ~Audio() override;

                void init() override;
                void update() override;
                void render() override;
            };
    }
}
#endif // SFML_AUDIO_HPP
