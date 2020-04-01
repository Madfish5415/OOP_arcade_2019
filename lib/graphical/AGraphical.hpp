/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_AGRAPHICAL_HPP
#define OOP_ARCADE_2019_AGRAPHICAL_HPP

#include "IGraphical.hpp"
#include "../../engine/eventbus/EventBus.hpp"

namespace graphical {
    class AGraphical : public IGraphical {
    public:
        AGraphical(const std::string &name, LIBTYPE type, engine::eventbus::EventBus &eventBus);
        virtual ~AGraphical() override = 0;

        virtual void init() = 0;
        virtual void dispatchEvent() = 0;
        virtual void destroy() = 0;
        std::string getName() override;
        LIBTYPE getType() override;
        
        virtual engine::component::AAudio& createAudio(engine::ecs::Entity &entity, const std::vector<std::string>& paths) override = 0;
        virtual engine::component::ARender& createRender(engine::ecs::Entity &entity, const std::vector<std::string>& paths) override = 0;
        virtual engine::system::AAudio& createAudioSystem(engine::ecs::World& world) override = 0;
        virtual engine::system::ARender& createRenderSystem(engine::ecs::World& world) override = 0;
        virtual engine::system::AAnimations& createAnimationsSystem(engine::ecs::World& world) override = 0;
    protected:
        engine::eventbus::EventBus& eventBus;
    private:
        LIBTYPE _type;
        std::string _name;
    };
}

#endif // OOP_ARCADE_2019_AGRAPHICAL_HPP
