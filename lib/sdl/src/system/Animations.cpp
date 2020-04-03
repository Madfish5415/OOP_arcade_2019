/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Animations.cpp
*/

#include "../../../engine/component/Animations.hpp"

#include <SDL2/SDL.h>

#include <component/Render.hpp>

#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/type/Animation.hpp"
#include "Animations.hpp"

using namespace sdl;
using namespace system;

Animations::Animations(engine::ecs::World& world) : engine::system::AAnimations(world)
{
}

Animations::~Animations() = default;

void Animations::init()
{
}

void Animations::update()
{
    auto entities = _world.getEntities<component::Render, engine::type::Animation>();

    for (auto& i : entities) {
        auto& anim = i.get().getComponent<engine::component::Animations>();
        auto& render = i.get().getComponent<component::Render>();
        auto& curr_anim = anim.list.at(anim.currentAnimation);
        int x = 0;
        int y = 0;

        SDL_QueryTexture(render.texture, nullptr, nullptr, &x, &y);
        render.srcRect.y = y / (int)anim.list.size() * curr_anim.row;

        if (anim.currentFrame == curr_anim.frames) {
            anim.currentFrame = 0;
            render.srcRect.x = 0;
        } else {
            anim.currentFrame++;
            render.srcRect.x += render.srcRect.w;
        }
    }
}

void Animations::render()
{
}
