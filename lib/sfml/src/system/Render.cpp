/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include <algorithm>

#include "../../../engine/component/Transform.hpp"
#include "../../../engine/component/Size.hpp"
#include "../component/Render.hpp"
#include "../component/Text.hpp"

using namespace sfml;
using namespace system;

Render::Render(engine::ecs::World& world, sf::RenderWindow& win) : ARender(world), window(win)
{
}

Render::~Render() = default;

void Render::init()
{
}

void Render::update()
{
    auto entities_transform = _world.getEntities<engine::component::Transform>();
    auto entities_size = _world.getEntities<engine::component::Size>();

    for (auto& i : entities_transform) {
        if (i.get().hasComponents<engine::component::ARender>()) {
            auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
            auto& pos = i.get().getComponent<engine::component::Transform>();

            render.sprite.setPosition(pos.position.x, pos.position.y);
        }
        if (i.get().hasComponents<engine::component::AText>()) {
            auto& text = dynamic_cast<component::Text&>(i.get().getComponent<engine::component::AText>());
            auto& pos = i.get().getComponent<engine::component::Transform>();

            text.sfText.setPosition((float)pos.position.x, (float)pos.position.y);
        }
    }
    for (auto& i : entities_size) {
        if (i.get().hasComponents<engine::component::ARender>()) {
            auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
            auto& size = i.get().getComponent<engine::component::Size>();

            render.destRect.width = size.width;
            render.destRect.height = size.height;
            render.sprite.setScale(float(render.destRect.width) / float(render.srcRect.width),
                                   float(render.destRect.height) / float(render.srcRect.height));
        }
        if (i.get().hasComponents<engine::component::AText>()) {
            auto &text = dynamic_cast<component::Text &>(i.get().getComponent<engine::component::AText>());
            auto &size = i.get().getComponent<engine::component::Size>();
            sf::FloatRect bounds = text.sfText.getLocalBounds();

            text.sfText.setScale((float) size.width / bounds.width,
                                 (float) size.height / bounds.height);
        }
    }
}

void Render::render()
{
    auto entities = _world.getEntities<engine::component::Transform>();

    if (!window.isOpen())
        return;
    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });

    window.clear();
    for (auto& i : entities) {
        if (i.get().hasComponents<engine::component::ARender>()) {
            auto& render = dynamic_cast<component::Render&>(i.get().getComponent<engine::component::ARender>());
            window.draw(render.sprite);
        }
        if (i.get().hasComponents<engine::component::AText>()) {
            auto& text = dynamic_cast<component::Text&>(i.get().getComponent<engine::component::AText>());
            window.draw(text.sfText);
        }
    }
    window.display();
}
