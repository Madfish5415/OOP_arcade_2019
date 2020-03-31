/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Animations.cpp
*/

#include <component/Render.hpp>
#include "../../../engine/ecs/World.hpp"
#include "Animations.hpp"

sfml::system::Animations::Animations(engine::ecs::World &world) : engine::system::AAnimations(world) {

}

void sfml::system::Animations::init() {

}

void sfml::system::Animations::update() {
    auto& entities = _world.getEntities<sfml::component::Render, engine::type::Animation>();

    for (auto& i : entities) {
        auto& anim = i.getComponent<engine::component::Animation>();
        auto& render = i.getComponent<sfml::component::Render>();
        auto& curr_anim = anim.list[anim.currentAnimation];
        render.srcRect.top = render.texture.getSize().y / anim.list.size() * curr_anim.row;
        if (curr_anim.currentFrame == curr_anim.frames) {
            curr_anim.currentFrame = 0;
            render.srcRect.left = 0;
        }
        else {
            curr_anim.frames++;
            render.srcRect.left += render.srcRect.width;
        }
    }
    //TODO IMPLEMENT SPEED
}

void sfml::system::Animations::render() {

}
