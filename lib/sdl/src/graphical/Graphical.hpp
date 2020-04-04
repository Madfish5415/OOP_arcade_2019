/*
** EPITECH PROJECT, 2020
** sfml
** File description:
** Graphical.hpp
*/

#ifndef SFML_GRAPHICAL_HPP
#define SFML_GRAPHICAL_HPP

#include <SDL2/SDL.h>
#include <map>

#include "../../../engine/component/AAudio.hpp"
#include "../../../engine/ecs/Universe.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/event/Input.hpp"
#include "../../../engine/eventbus/EventBus.hpp"
#include "../../graphical/AGraphical.hpp"

namespace sdl {

    static const std::map<SDL_Keycode, engine::event::Input::KEYCODE> KEYSCORR = {
    {SDLK_UNKNOWN, engine::event::Input::KEY_UNKNOWN},
    {SDLK_a, engine::event::Input::KEY_A},
    {SDLK_b, engine::event::Input::KEY_B},
    {SDLK_c, engine::event::Input::KEY_C},
    {SDLK_d, engine::event::Input::KEY_D},
    {SDLK_e, engine::event::Input::KEY_E},
    {SDLK_f, engine::event::Input::KEY_F},
    {SDLK_g, engine::event::Input::KEY_G},
    {SDLK_h, engine::event::Input::KEY_H},
    {SDLK_i, engine::event::Input::KEY_I},
    {SDLK_j, engine::event::Input::KEY_J},
    {SDLK_k, engine::event::Input::KEY_K},
    {SDLK_l, engine::event::Input::KEY_L},
    {SDLK_m, engine::event::Input::KEY_M},
    {SDLK_n, engine::event::Input::KEY_N},
    {SDLK_o, engine::event::Input::KEY_O},
    {SDLK_p, engine::event::Input::KEY_P},
    {SDLK_q, engine::event::Input::KEY_Q},
    {SDLK_r, engine::event::Input::KEY_R},
    {SDLK_s, engine::event::Input::KEY_S},
    {SDLK_t, engine::event::Input::KEY_T},
    {SDLK_u, engine::event::Input::KEY_U},
    {SDLK_v, engine::event::Input::KEY_V},
    {SDLK_w, engine::event::Input::KEY_W},
    {SDLK_x, engine::event::Input::KEY_X},
    {SDLK_y, engine::event::Input::KEY_Y},
    {SDLK_z, engine::event::Input::KEY_Z},
    {SDLK_0, engine::event::Input::KEY_NUM0},
    {SDLK_1, engine::event::Input::KEY_NUM1},
    {SDLK_2, engine::event::Input::KEY_NUM2},
    {SDLK_3, engine::event::Input::KEY_NUM3},
    {SDLK_4, engine::event::Input::KEY_NUM4},
    {SDLK_5, engine::event::Input::KEY_NUM5},
    {SDLK_6, engine::event::Input::KEY_NUM6},
    {SDLK_7, engine::event::Input::KEY_NUM7},
    {SDLK_8, engine::event::Input::KEY_NUM8},
    {SDLK_9, engine::event::Input::KEY_NUM9},
    {SDLK_ESCAPE, engine::event::Input::KEY_ESCAPE},
    {SDLK_LCTRL, engine::event::Input::KEY_LCONTROL},
    {SDLK_LSHIFT, engine::event::Input::KEY_LSHIFT},
    {SDLK_LALT, engine::event::Input::KEY_LALT},
    {SDLK_LGUI, engine::event::Input::KEY_LSYSTEM},
    {SDLK_RCTRL, engine::event::Input::KEY_RCONTROL},
    {SDLK_RSHIFT, engine::event::Input::KEY_RSHIFT},
    {SDLK_RALT, engine::event::Input::KEY_RALT},
    {SDLK_RGUI, engine::event::Input::KEY_RSYSTEM},
    {SDLK_MENU, engine::event::Input::KEY_MENU},
    {SDLK_LEFTBRACKET, engine::event::Input::KEY_LBRACKET},
    {SDLK_RIGHTBRACKET, engine::event::Input::KEY_RBRACKET},
    {SDLK_SEMICOLON, engine::event::Input::KEY_SEMICOLON},
    {SDLK_COMMA, engine::event::Input::KEY_COMMA},
    {SDLK_PERIOD, engine::event::Input::KEY_PERIOD},
    {SDLK_QUOTE, engine::event::Input::KEY_QUOTE},
    {SDLK_SLASH, engine::event::Input::KEY_SLASH},
    {SDLK_BACKSLASH, engine::event::Input::KEY_BACKSLASH},
    //{sf::Keyboard::Tilde, engine::event::Input::KEY_TILDE},
    {SDLK_EQUALS, engine::event::Input::KEY_EQUAL},
    {SDLK_BACKSLASH, engine::event::Input::KEY_HYPHEN},
    {SDLK_SPACE, engine::event::Input::KEY_SPACE},
    {SDLK_RETURN, engine::event::Input::KEY_ENTER},
    {SDLK_BACKSPACE, engine::event::Input::KEY_BACKSPACE},
    {SDLK_TAB, engine::event::Input::KEY_TAB},
    {SDLK_PAGEUP, engine::event::Input::KEY_PAGEUP},
    {SDLK_PAGEDOWN, engine::event::Input::KEY_PAGEDOWN},
    {SDLK_END, engine::event::Input::KEY_END},
    {SDLK_HOME, engine::event::Input::KEY_HOME},
    {SDLK_INSERT, engine::event::Input::KEY_INSERT},
    {SDLK_DELETE, engine::event::Input::KEY_DELETE},
    {SDLK_KP_MEMADD, engine::event::Input::KEY_ADD},
    {SDLK_KP_MEMSUBTRACT, engine::event::Input::KEY_SUBTRACT},
    {SDLK_KP_MEMMULTIPLY, engine::event::Input::KEY_MULTIPLY},
    {SDLK_KP_MEMDIVIDE, engine::event::Input::KEY_DIVIDE},
    {SDLK_LEFT, engine::event::Input::KEY_LEFT},
    {SDLK_RIGHT, engine::event::Input::KEY_RIGHT},
    {SDLK_UP, engine::event::Input::KEY_UP},
    {SDLK_DOWN, engine::event::Input::KEY_DOWN},
    {SDLK_KP_0, engine::event::Input::KEY_0},
    {SDLK_KP_1, engine::event::Input::KEY_1},
    {SDLK_KP_2, engine::event::Input::KEY_2},
    {SDLK_KP_3, engine::event::Input::KEY_3},
    {SDLK_KP_4, engine::event::Input::KEY_4},
    {SDLK_KP_5, engine::event::Input::KEY_5},
    {SDLK_KP_6, engine::event::Input::KEY_6},
    {SDLK_KP_7, engine::event::Input::KEY_7},
    {SDLK_KP_8, engine::event::Input::KEY_8},
    {SDLK_KP_9, engine::event::Input::KEY_9},
    {SDLK_F1, engine::event::Input::KEY_F1},
    {SDLK_F2, engine::event::Input::KEY_F2},
    {SDLK_F3, engine::event::Input::KEY_F3},
    {SDLK_F4, engine::event::Input::KEY_F4},
    {SDLK_F5, engine::event::Input::KEY_F5},
    {SDLK_F6, engine::event::Input::KEY_F6},
    {SDLK_F7, engine::event::Input::KEY_F7},
    {SDLK_F8, engine::event::Input::KEY_F8},
    {SDLK_F9, engine::event::Input::KEY_F9},
    {SDLK_F10, engine::event::Input::KEY_F10},
    {SDLK_F11, engine::event::Input::KEY_F11},
    {SDLK_F12, engine::event::Input::KEY_F12},
    {SDLK_F13, engine::event::Input::KEY_F13},
    {SDLK_F14, engine::event::Input::KEY_F14},
    {SDLK_F15, engine::event::Input::KEY_F15},
    {SDLK_PAUSE, engine::event::Input::KEY_PAUSE}
};

class Graphical : public graphical::AGraphical {
   public:
    explicit Graphical(engine::eventbus::EventBus& eventBus);
    ~Graphical() override;

   public:
    void init() override;
    void dispatchEvent() override;
    void destroy() override;

   public:
    engine::component::AAudio& createAudio(engine::ecs::Entity& entity, const std::vector<std::string>& paths) override;
    engine::component::ARender& createRender(engine::ecs::Entity& entity, const std::vector<std::string>& paths) override;
    engine::component::AText& createText(engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths) override;

   public:
    engine::system::AAudio& createAudioSystem(engine::ecs::World& world) override;
    engine::system::ARender& createRenderSystem(engine::ecs::World& world) override;
    engine::system::AAnimations& createAnimationsSystem(engine::ecs::World& world) override;

   private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};
}  // namespace sdl

#endif  // SFML_GRAPHICAL_HPP
