/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include <component/Audio.hpp>
#include <vector>
#include <iostream>

#include "../../graphical/AGraphical.hpp"
#include "../component/Audio.hpp"
#include "../component/Render.hpp"
#include "../component/Text.hpp"
#include "../system/Animations.hpp"
#include "../system/Audio.hpp"
#include "../system/Render.hpp"
#include "../system/Text.hpp"

using namespace sfml;

Graphical::Graphical(engine::eventbus::EventBus& eventBus) : AGraphical("SFML", graphical::GRAPHIC, eventBus)
{
    _window = nullptr;
}

Graphical::~Graphical() = default;

void Graphical::init()
{
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
    _window->setVerticalSyncEnabled(true);
    _window->setFramerateLimit(60);
}

void Graphical::dispatchEvent()
{
    sf::Event event;

    while (_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            _window->close();
            auto evt = new engine::event::Close();
            _eventBus.publish(*evt);
            delete evt;
        }

        if (event.type == sf::Event::KeyPressed) {
            for (auto& i : KEYSCORR) {
                if (event.key.code == i.first) {
                    auto evt = new engine::event::Input();
                    evt->code = i.second;
                    _eventBus.publish(*evt);
                    delete evt;
                }
            }
        }


    }
}

void Graphical::destroy()
{
    if (_window->isOpen())
        _window->close();
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

engine::component::AText& Graphical::createText(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths)
{
    auto cmptext = new component::Text(entity, text, paths);
    return *cmptext;
}

engine::system::ARender& Graphical::createRenderSystem(engine::ecs::World& world)
{
    auto render = new system::Render(world, *_window);
    return *render;
}

engine::system::AText& Graphical::createTextSystem(engine::ecs::World& world)
{
    auto text = new system::Text(world, *_window);
    return *text;
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

