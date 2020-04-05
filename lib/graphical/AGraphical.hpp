/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_AGRAPHICAL_HPP
#define OOP_ARCADE_2019_AGRAPHICAL_HPP

#include "../../engine/eventbus/EventBus.hpp"
#include "IGraphical.hpp"

namespace graphical {
class AGraphical : public IGraphical {
   public:
    AGraphical(const std::string& name, LIBTYPE type, engine::eventbus::EventBus& eventBus);
    ~AGraphical() override = 0;

   public:
    void init() override = 0;
    void dispatchEvent() override = 0;
    void destroy() override = 0;

   public:
    std::string getName() override;
    LIBTYPE getType() override;

   public:
    engine::component::AAudio& createAudio(engine::ecs::Entity& entity, const std::vector<std::string>& paths) override = 0;
    engine::component::ARender& createRender(engine::ecs::Entity& entity, const std::vector<std::string>& paths) override = 0;
    engine::component::AText& createText(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths) override = 0;

   public:
    engine::system::AAudio& createAudioSystem(engine::ecs::World& world) override = 0;
    engine::system::ARender& createRenderSystem(engine::ecs::World& world) override = 0;
    engine::system::AAnimations& createAnimationsSystem(engine::ecs::World& world) override = 0;

   protected:
    engine::eventbus::EventBus& _eventBus;

   private:
    LIBTYPE _type;
    std::string _name;
};
}  // namespace graphical

#endif  // OOP_ARCADE_2019_AGRAPHICAL_HPP
