/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Audio.hpp
*/

#ifndef SFML_AUDIO_HPP
#define SFML_AUDIO_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../../../engine/component/AAudio.hpp"

namespace sfml {

namespace component {

class Audio : public engine::component::AAudio {
   public:
    Audio(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
    ~Audio() override;
    //            sf::SoundBuffer soundbuffer;
    //            sf::Sound sound;
    //            sf::Music music;
};

}  // namespace component

}  // namespace sfml

#endif  // SFML_AUDIO_HPP
