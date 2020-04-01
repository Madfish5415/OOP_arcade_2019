/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Graphical.hpp
*/

#ifndef SFML_GRAPHICAL_HPP
#define SFML_GRAPHICAL_HPP

#include <Keyboard.hpp>
#include <map>
#include "SFML/Graphics.hpp"
#include "../../../engine/ecs/Universe.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/eventbus/EventBus.hpp"
#include "../../../engine/component/AAudio.hpp"
#include "../../graphical/AGraphical.hpp"

static const std::map<sf::Keyboard::Key, engine::event::Input::KEYCODE> KEYSCORR = {
        {sf::Keyboard::Unknown, engine::event::Input::KEY_UNKNOWN},
        {sf::Keyboard::A, engine::event::Input::KEY_A},
        {sf::Keyboard::B, engine::event::Input::KEY_B},
        {sf::Keyboard::C, engine::event::Input::KEY_C},
        {sf::Keyboard::D, engine::event::Input::KEY_D},
        {sf::Keyboard::E, engine::event::Input::KEY_E},
        {sf::Keyboard::F, engine::event::Input::KEY_F},
        {sf::Keyboard::G, engine::event::Input::KEY_G},
        {sf::Keyboard::H, engine::event::Input::KEY_H},
        {sf::Keyboard::I, engine::event::Input::KEY_I},
        {sf::Keyboard::J, engine::event::Input::KEY_J},
        {sf::Keyboard::K, engine::event::Input::KEY_K},
        {sf::Keyboard::L, engine::event::Input::KEY_L},
        {sf::Keyboard::M, engine::event::Input::KEY_M},
        {sf::Keyboard::N, engine::event::Input::KEY_N},
        {sf::Keyboard::O, engine::event::Input::KEY_O},
        {sf::Keyboard::P, engine::event::Input::KEY_P},
        {sf::Keyboard::Q, engine::event::Input::KEY_Q},
        {sf::Keyboard::R, engine::event::Input::KEY_R},
        {sf::Keyboard::S, engine::event::Input::KEY_S},
        {sf::Keyboard::T, engine::event::Input::KEY_T},
        {sf::Keyboard::U, engine::event::Input::KEY_U},
        {sf::Keyboard::V, engine::event::Input::KEY_V},
        {sf::Keyboard::W, engine::event::Input::KEY_W},
        {sf::Keyboard::X, engine::event::Input::KEY_X},
        {sf::Keyboard::Y, engine::event::Input::KEY_Y},
        {sf::Keyboard::Z, engine::event::Input::KEY_Z},
        {sf::Keyboard::Num0, engine::event::Input::KEY_NUM0},
        {sf::Keyboard::Num1, engine::event::Input::KEY_NUM1},
        {sf::Keyboard::Num2, engine::event::Input::KEY_NUM2},
        {sf::Keyboard::Num3, engine::event::Input::KEY_NUM3},
        {sf::Keyboard::Num4, engine::event::Input::KEY_NUM4},
        {sf::Keyboard::Num5, engine::event::Input::KEY_NUM5},
        {sf::Keyboard::Num6, engine::event::Input::KEY_NUM6},
        {sf::Keyboard::Num7, engine::event::Input::KEY_NUM7},
        {sf::Keyboard::Num8, engine::event::Input::KEY_NUM8},
        {sf::Keyboard::Num9, engine::event::Input::KEY_NUM9},
        {sf::Keyboard::Escape, engine::event::Input::KEY_ESCAPE},
        {sf::Keyboard::LControl, engine::event::Input::KEY_LCONTROL},
        {sf::Keyboard::LShift, engine::event::Input::KEY_LSHIFT},
        {sf::Keyboard::LAlt, engine::event::Input::KEY_LALT},
        {sf::Keyboard::LSystem, engine::event::Input::KEY_LSYSTEM},
        {sf::Keyboard::RControl, engine::event::Input::KEY_RCONTROL},
        {sf::Keyboard::RShift, engine::event::Input::KEY_RSHIFT},
        {sf::Keyboard::RAlt, engine::event::Input::KEY_RALT},
        {sf::Keyboard::RSystem, engine::event::Input::KEY_RSYSTEM},
        {sf::Keyboard::Menu, engine::event::Input::KEY_MENU},
        {sf::Keyboard::LBracket, engine::event::Input::KEY_LBRACKET},
        {sf::Keyboard::RBracket, engine::event::Input::KEY_RBRACKET},
        {sf::Keyboard::SemiColon, engine::event::Input::KEY_SEMICOLON},
        {sf::Keyboard::Comma, engine::event::Input::KEY_COMMA},
        {sf::Keyboard::Period, engine::event::Input::KEY_PERIOD},
        {sf::Keyboard::Quote, engine::event::Input::KEY_QUOTE},
        {sf::Keyboard::Slash, engine::event::Input::KEY_SLASH},
        {sf::Keyboard::BackSlash, engine::event::Input::KEY_BACKSLASH},
        {sf::Keyboard::Tilde, engine::event::Input::KEY_TILDE},
        {sf::Keyboard::Equal, engine::event::Input::KEY_EQUAL},
        {sf::Keyboard::BackSlash, engine::event::Input::KEY_HYPHEN},
        {sf::Keyboard::Space, engine::event::Input::KEY_SPACE},
        {sf::Keyboard::Return, engine::event::Input::KEY_ENTER},
        {sf::Keyboard::BackSpace, engine::event::Input::KEY_BACKSPACE},
        {sf::Keyboard::Tab, engine::event::Input::KEY_TAB},
        {sf::Keyboard::PageUp, engine::event::Input::KEY_PAGEUP},
        {sf::Keyboard::PageDown, engine::event::Input::KEY_PAGEDOWN},
        {sf::Keyboard::End, engine::event::Input::KEY_END},
        {sf::Keyboard::Home, engine::event::Input::KEY_HOME},
        {sf::Keyboard::Insert, engine::event::Input::KEY_INSERT},
        {sf::Keyboard::Delete, engine::event::Input::KEY_DELETE},
        {sf::Keyboard::Add, engine::event::Input::KEY_ADD},
        {sf::Keyboard::Subtract, engine::event::Input::KEY_SUBTRACT},
        {sf::Keyboard::Multiply, engine::event::Input::KEY_MULTIPLY},
        {sf::Keyboard::Divide, engine::event::Input::KEY_DIVIDE},
        {sf::Keyboard::Left, engine::event::Input::KEY_LEFT},
        {sf::Keyboard::Right, engine::event::Input::KEY_RIGHT},
        {sf::Keyboard::Up, engine::event::Input::KEY_UP},
        {sf::Keyboard::Down, engine::event::Input::KEY_DOWN},
        {sf::Keyboard::Numpad0, engine::event::Input::KEY_NUM0},
        {sf::Keyboard::Numpad1, engine::event::Input::KEY_NUM1},
        {sf::Keyboard::Numpad2, engine::event::Input::KEY_NUM2},
        {sf::Keyboard::Numpad3, engine::event::Input::KEY_NUM3},
        {sf::Keyboard::Numpad4, engine::event::Input::KEY_NUM4},
        {sf::Keyboard::Numpad5, engine::event::Input::KEY_NUM5},
        {sf::Keyboard::Numpad6, engine::event::Input::KEY_NUM6},
        {sf::Keyboard::Numpad7, engine::event::Input::KEY_NUM7},
        {sf::Keyboard::Numpad8, engine::event::Input::KEY_NUM8},
        {sf::Keyboard::Numpad9, engine::event::Input::KEY_NUM9},
        {sf::Keyboard::F1, engine::event::Input::KEY_F1},
        {sf::Keyboard::F2, engine::event::Input::KEY_F2},
        {sf::Keyboard::F3, engine::event::Input::KEY_F3},
        {sf::Keyboard::F4, engine::event::Input::KEY_F4},
        {sf::Keyboard::F5, engine::event::Input::KEY_F5},
        {sf::Keyboard::F6, engine::event::Input::KEY_F6},
        {sf::Keyboard::F7, engine::event::Input::KEY_F7},
        {sf::Keyboard::F8, engine::event::Input::KEY_F8},
        {sf::Keyboard::F9, engine::event::Input::KEY_F9},
        {sf::Keyboard::F10, engine::event::Input::KEY_F10},
        {sf::Keyboard::F11, engine::event::Input::KEY_F11},
        {sf::Keyboard::F12, engine::event::Input::KEY_F12},
        {sf::Keyboard::F13, engine::event::Input::KEY_F13},
        {sf::Keyboard::F14, engine::event::Input::KEY_F14},
        {sf::Keyboard::F15, engine::event::Input::KEY_F15},
        {sf::Keyboard::Pause, engine::event::Input::KEY_PAUSE},
        {sf::Keyboard::KeyCount, engine::event::Input::KEY_KEYCOUNT}
};

namespace sfml {
class Graphical : public graphical::AGraphical {
    public:
        explicit Graphical(engine::eventbus::EventBus &eventBus);
        ~Graphical() override;
        void init() override;
        void dispatchEvent() override;
        void destroy() override;

        engine::component::AAudio createAudio(engine::ecs::Entity &entity, const std::vector<std::string>& paths) override;
        engine::component::ARender createRender(engine::ecs::Entity &entity, const std::vector<std::string>& paths) override;

        engine::system::AAudio createAudioSystem(engine::ecs::World& world) override;
        engine::system::ARender createRenderSystem(engine::ecs::World& world) override;
        engine::system::AAnimations createAnimationsSystem(engine::ecs::World& world) override;
    private:
        sf::RenderWindow* _window;
    };
}


#endif // SFML_GRAPHICAL_HPP
