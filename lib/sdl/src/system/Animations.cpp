/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Animations.cpp
*/

#include "../../../engine/component/Animations.hpp"

#include <SDL2/SDL.h>
#include <iostream>

#include <component/Render.hpp>

#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/type/Animation.hpp"
#include "Animations.hpp"

using namespace sdl;
using namespace system;

Animations::Animations(engine::ecs::World& world) : engine::system::AAnimations(world)
{
    lastTime = 0;
}

Animations::~Animations() = default;

void Animations::init()
{
}

void Animations::update()
{
    auto entities = _world.getEntities<engine::component::ARender, engine::component::Animations>();

    unsigned int currentTime = SDL_GetTicks();

    for (auto& i : entities) {
        auto& anim = i.get().getComponent<engine::component::Animations>();
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
        auto& curr_anim = anim.list.at(anim.currentAnimation);
        int x = 0;
        int y = 0;

        if (currentTime > lastTime + curr_anim.speed) {
            lastTime = currentTime;
        } else {
            continue;
        }

        SDL_QueryTexture(render.texture, nullptr, nullptr, &x, &y);

        render.srcRect.w = x / curr_anim.frames;
        render.srcRect.h = y / anim.list.size();

        render.srcRect.y = y / (int)anim.list.size() * curr_anim.row;

        anim.currentFrame++;
        render.srcRect.x += render.srcRect.w;

        if (anim.currentFrame == curr_anim.frames) {
            anim.currentFrame = 0;
            render.srcRect.x = 0;
        }
    }
}

void Animations::render()
{
}
