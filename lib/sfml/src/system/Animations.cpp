/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Animations.cpp
*/

#include <component/Render.hpp>
#include "../../../engine/type/Animation.hpp"
#include "../../../engine/ecs/Entity.hpp"
#include "../../../engine/component/Animations.hpp"
#include "../../../engine/ecs/World.hpp"
#include "Animations.hpp"

sfml::system::Animations::Animations(engine::ecs::World &world) : engine::system::AAnimations(world) {

}

sfml::system::Animations::~Animations() = default;

void sfml::system::Animations::init() {

}

void sfml::system::Animations::update() {
    auto entities = _world.getEntities<sfml::component::Render, engine::type::Animation>();

    for (auto& i : entities) {
        auto& anim = i.get().getComponent<engine::component::Animations>();
        auto& render = i.get().getComponent<sfml::component::Render>();
        auto& curr_anim = anim.list.at(anim.currentAnimation);
        render.srcRect.top = render.texture.getSize().y / anim.list.size() * curr_anim.row;
        if (anim.currentFrame == curr_anim.frames) {
            anim.currentFrame = 0;
            render.srcRect.left = 0;
        }
        else {
            anim.currentFrame++;
            render.srcRect.left += render.srcRect.width;
        }
        render.sprite.setTextureRect(render.srcRect);
    }
}

void sfml::system::Animations::render() {

}
