/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Animations.cpp
*/

#include "../../../engine/component/Animations.hpp"

#include <component/Render.hpp>

#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/type/Animation.hpp"
#include "Animations.hpp"
#include <iostream>

using namespace sfml;
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
    static sf::Clock clock;
    auto entities = _world.getEntities<engine::component::ARender, engine::component::Animations>();

    for (auto& i : entities) {

        auto& anim = i.get().getComponent<engine::component::Animations>();
        auto& curr_anim = anim.list.at(anim.currentAnimation);
        auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());

        if (clock.getElapsedTime().asMilliseconds() > curr_anim.speed)
            clock.restart();
        else
            continue;

        render.srcRect.width = render.texture.getSize().x / curr_anim.frames;
        render.srcRect.height = render.texture.getSize().y / anim.list.size();

        render.srcRect.top = render.texture.getSize().y / anim.list.size() * curr_anim.row;

        anim.currentFrame++;
        render.srcRect.left += render.srcRect.width;

        if (anim.currentFrame == curr_anim.frames) {
            anim.currentFrame = 0;
            render.srcRect.left = 0;
        }

        render.sprite.setTextureRect(render.srcRect);
    }
}

void Animations::render()
{
}
