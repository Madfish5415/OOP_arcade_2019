/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include <component/Audio.hpp>
#include <vector>

#include "../../graphical/AGraphical.hpp"
#include "../component/Audio.hpp"
#include "../component/Render.hpp"
#include "../system/Animations.hpp"
#include "../system/Audio.hpp"
#include "../system/Render.hpp"

using namespace sfml;

Graphical::Graphical(engine::eventbus::EventBus& eventBus) : AGraphical("SFML", graphical::GRAPHIC, eventBus)
{
    _window = nullptr;
}

Graphical::~Graphical() = default;

void Graphical::init()
{
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
}

void Graphical::dispatchEvent()
{
    for (auto& i : KEYSCORR) {
        if (sf::Keyboard::isKeyPressed(i.first)) {
            auto evt = new engine::event::Input();
            evt->code = i.second;
            _eventBus.publish(*evt);
            delete evt;
        }
    }
}

void Graphical::destroy()
{
    delete _window;
}

engine::component::ARender& Graphical::createRender(engine::ecs::Entity& entity, const std::vector<std::string>& paths)
{
    auto rdr = new component::Render(entity, paths);
    return *rdr;
}

engine::component::AAudio& Graphical::createAudio(engine::ecs::Entity& entity, const std::vector<std::string>& paths)
{
    auto audio = new component::Audio(entity, paths);
    return *audio;
}

engine::system::ARender& Graphical::createRenderSystem(engine::ecs::World& world)
{
    auto render = new system::Render(world, *_window);
    return *render;
}

engine::system::AAudio& Graphical::createAudioSystem(engine::ecs::World& world)
{
    auto audio = new system::Audio(world);
    return *audio;
}

engine::system::AAnimations& Graphical::createAnimationsSystem(engine::ecs::World& world)
{
    auto anim = new system::Animations(world);
    return *anim;
}