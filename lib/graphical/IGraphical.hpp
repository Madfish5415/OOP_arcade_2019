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

#include "../../engine/component/AAudio.hpp"
#include "../../engine/component/ARender.hpp"
#include "../../engine/component/AText.hpp"
#include "../../engine/system/AAnimations.hpp"
#include "../../engine/system/AAudio.hpp"
#include "../../engine/system/ARender.hpp"
#include "../../engine/system/AText.hpp"

namespace graphical {

enum LIBTYPE { TEXT = 0, GRAPHIC, DEBUG };

class IGraphical {
   public:
    virtual ~IGraphical() = default;

   public:
    virtual void init() = 0;
    virtual void dispatchEvent() = 0;
    virtual void destroy() = 0;

   public:
    virtual std::string getName() = 0;
    virtual LIBTYPE getType() = 0;

   public:
    virtual engine::component::AAudio& createAudio(engine::ecs::Entity& entity, const std::vector<std::string>& paths) = 0;
    virtual engine::component::ARender& createRender(engine::ecs::Entity& entity, const std::vector<std::string>& paths) = 0;
    virtual engine::component::AText& createText(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths) = 0;

   public:
    virtual engine::system::AAudio& createAudioSystem(engine::ecs::World& world) = 0;
    virtual engine::system::ARender& createRenderSystem(engine::ecs::World& world) = 0;
    virtual engine::system::AText& createTextSystem(engine::ecs::World& world) = 0;
    virtual engine::system::AAnimations& createAnimationsSystem(engine::ecs::World& world) = 0;
};

}  // namespace graphical
#endif  // OOP_ARCADE_2019_IGRAPHICAL_HPP
