/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Graphical.hpp
*/

#ifndef SFML_GRAPHICAL_HPP
#define SFML_GRAPHICAL_HPP

#include "SFML/Graphics.hpp"
#include "../../../engine/ecs/Universe.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/eventbus/EventBus.hpp"
#include "../../../engine/component/AAudio.hpp"
#include "../../graphical/AGraphical.hpp"

namespace sfml {
class Graphical : public graphical::AGraphical {
    public:
        explicit Graphical(engine::eventbus::EventBus &eventBus);
        ~Graphical() override;
        void init() override;
        void dispatchEvent() override;
        void destroy() override;

        engine::component::AAudio createAudio(engine::ecs::Entity &entity, const std::vector<std::string>& paths) override;
        engine::component::ARender createRender(engine::ecs::Entity &entity, const std::vector<std::string>& paths) override;

        engine::system::AAudio createAudioSystem(engine::ecs::World& world) override;
        engine::system::ARender createRenderSystem(engine::ecs::World& world) override;
        engine::system::AAnimations createAnimationsSystem(engine::ecs::World& world) override;
    private:
        sf::RenderWindow* _window;
    };
}


#endif // SFML_GRAPHICAL_HPP
