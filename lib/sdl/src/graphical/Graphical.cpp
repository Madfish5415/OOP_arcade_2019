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
#include "../../../../engine/event/Close.hpp"

using namespace sdl;

Graphical::Graphical(engine::eventbus::EventBus& eventBus) : AGraphical("SDL", graphical::GRAPHIC, eventBus)
{
    _window = nullptr;
    _renderer = nullptr;
}
Graphical::~Graphical() = default;

void Graphical::init()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", 0, 0, 1920, 1080, 0);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
}

void Graphical::dispatchEvent()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            auto evt = new engine::event::Close();
            _eventBus.publish(*evt);
            delete evt;
        }
        if (event.type == SDL_KEYDOWN) {
            auto evt = new engine::event::Input();
            evt->code = KEYSCORR.at(event.key.keysym.sym);
            _eventBus.publish(*evt);
            delete evt;
        }
    }
}


void Graphical::destroy()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    IMG_Quit();
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
