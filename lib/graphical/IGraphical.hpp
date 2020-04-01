/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_IGRAPHICAL_HPP
#define OOP_ARCADE_2019_IGRAPHICAL_HPP

#include <string>
#include <vector>

namespace graphical {
    class IGraphical {
    public:
        enum LIBTYPE {
            TEXT = 0,
            GRAPHIC,
            DEBUG
        };
        virtual ~IGraphical() = 0;
        virtual void init() = 0;
        virtual void dispatchEvent() = 0;
        virtual void destroy() = 0;
        virtual std::string getName() = 0;
        virtual LIBTYPE getType() = 0;
        virtual engine::component::AAudio createAudio(const std::vector<std::string>& paths) = 0;
        virtual engine::component::ARender createRender(const std::vector<std::string>& paths) = 0;
        virtual engine::system::AAudio createAudioSystem(engine::ecs::World& world) = 0;
        virtual engine::system::ARender createRenderSystem(engine::ecs::World& world) = 0;
        virtual engine::system::AAnimations createAnimationsSystem(engine::ecs::World& world) = 0;
    };
}
#endif // OOP_ARCADE_2019_IGRAPHICAL_HPP
