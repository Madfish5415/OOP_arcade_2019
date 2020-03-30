/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Graphical.cpp
*/

#include "../../graphical/AGraphical.hpp"
#include "../component/Audio.hpp"
#include "../component/Render.hpp"
#include "../system/Animations.hpp"
#include "../system/Audio.hpp"
#include "../system/Render.hpp"
#include "Graphical.hpp"

sfml::Graphical::Graphical(engine::eventbus::EventBus &eventBus) : AGraphical("SFML", GRAPHIC, eventBus)
{
}

sfml::Graphical::~Graphical() {
    delete _window;
}

void sfml::Graphical::init() {
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
}

void sfml::Graphical::dispatchEvent() {

}

void sfml::Graphical::destroy() {
    delete _window;
}

engine::component::ARender sfml::Graphical::createRender(engine::ecs::Entity &entity, const std::vector<std::string> &paths) {
    auto rdr = new component::Render(entity, paths);
    return rdr;
}

engine::component::AAudio sfml::Graphical::createAudio(engine::ecs::Entity &entity, const std::vector<std::string> &paths) {
    auto audio = new component::Audio(entity, paths);
    return audio;
}

engine::system::ARender sfml::Graphical::createRenderSystem(engine::ecs::World &world) {
    auto render = new system::Render(world);
    return render;
}

engine::system::AAudio sfml::Graphical::createAudioSystem(engine::ecs::World &world) {
    auto audio = new system::Audio(world);
    return audio;
}

engine::system::AAnimations sfml::Graphical::createAnimationsSystem(engine::ecs::World &world) {
    auto anim = new system::Animations(world);
    return anim;
}
