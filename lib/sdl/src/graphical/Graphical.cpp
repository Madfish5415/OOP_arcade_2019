/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "../../graphical/AGraphical.hpp"
#include "../component/Audio.hpp"
#include "../component/Render.hpp"
#include "../component/Text.hpp"
#include "../system/Animations.hpp"
#include "../system/Audio.hpp"
#include "../system/Render.hpp"

using namespace sdl;

Graphical::Graphical(engine::eventbus::EventBus& eventBus) : AGraphical("SDL", graphical::GRAPHIC, eventBus)
{
    _window = nullptr;
    _renderer = nullptr;
}
Graphical::~Graphical() = default;

void Graphical::init()
{
    IMG_Init(IMG_INIT_PNG);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", 0, 0, 1920, 1080, 0);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
}

void Graphical::dispatchEvent()
{
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        for (auto &i : KEYSCORR) {
            if (e.key.keysym.sym == i.first) {
                auto evt = new engine::event::Input();
                evt->code = i.second;
                _eventBus.publish(*evt);
                delete evt;
            }
        }
    }
}

void Graphical::destroy()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

engine::component::ARender& Graphical::createRender(engine::ecs::Entity& entity, const std::vector<std::string>& paths)
{
    auto render = new component::Render(entity, paths, _renderer);
    return *render;
}

engine::component::AAudio& Graphical::createAudio(engine::ecs::Entity& entity, const std::vector<std::string>& paths)
{
    auto audio = new component::Audio(entity, paths);
    return *audio;
}

engine::component::AText& Graphical::createText(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths)
{
    auto cmptext = new component::Text(entity, text, paths, _renderer);
    return *cmptext;
}

engine::system::ARender& Graphical::createRenderSystem(engine::ecs::World& world)
{
    auto render = new system::Render(world, _renderer);
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
