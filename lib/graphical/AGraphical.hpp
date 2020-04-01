/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_AGRAPHICAL_HPP
#define OOP_ARCADE_2019_AGRAPHICAL_HPP

#include "IGraphical.hpp"

namespace graphical {
    class AGraphical : public IGraphical {
    public:
        AGraphical(const std::string &name, LIBTYPE type, engine::eventbus::EventBus &eventBus);
        virtual ~AGraphical() = 0;

        virtual void init() = 0;
        virtual void dispatchEvent() = 0;
        virtual void destroy() = 0;

        std::string getName() override {
            return _name;
        };

        LIBTYPE getType() override {
            return _type;
        };
        
        virtual engine::component::AAudio createAudio(const std::vector<std::string>& paths) override = 0 ;
        virtual engine::component::ARender createRender(const std::vector<std::string>& paths) override = 0;
        virtual engine::system::AAudio createAudioSystem(engine::ecs::World& world) = 0 override = 0;
        virtual engine::system::ARender createRenderSystem(engine::ecs::World& world) = 0 override = 0;
        virtual engine::system::AAnimations createAnimationsSystem(engine::ecs::World& world) = 0 override = 0;
    private:
        LIBTYPE _type;
        std::string _name;
    };
}

#endif // OOP_ARCADE_2019_AGRAPHICAL_HPP
