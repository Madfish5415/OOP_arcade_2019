/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Audio.hpp
*/

#ifndef SFML_AUDIO_HPP
#define SFML_AUDIO_HPP

#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"
#include "../../../engine/component/AAudio.hpp"

namespace sfml {
    namespace component {
        class Audio : public engine::component::AAudio {
        public:
            ~Audio() = default;
            Audio(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
            sf::SoundBuffer soundbuffer;
            sf::Sound sound;
            sf::Music music;
        };
    }
}

#endif // SFML_AUDIO_HPP
