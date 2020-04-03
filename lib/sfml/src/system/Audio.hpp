/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Audio.hpp
*/

#ifndef SFML_AUDIO_SYS__HPP
#define SFML_AUDIO_SYS__HPP

#include "../../../engine/ecs/World.hpp"
#include "../../../engine/system/AAudio.hpp"

namespace sfml {

namespace system {

class Audio : public engine::system::AAudio {
   public:
    explicit Audio(engine::ecs::World& world);
    ~Audio() override;

   public:
    void init() override;
    void update() override;
    void render() override;
};

}  // namespace system

}  // namespace sfml
#endif  // SFML_AUDIO_SYS__HPP
