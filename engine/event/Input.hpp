/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Input.hpp
*/

#ifndef OOP_ARCADE_2019_INPUT_HPP
#define OOP_ARCADE_2019_INPUT_HPP

#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

    /** \brief The class used to signal that the user pressed on the  */
class Input : public eventbus::AEvent {
   public:
    /** \brief The enum representing all the keycode on the keyboard */
    enum KEYCODE {
        KEY_UNKNOWN = -1,
        KEY_A, KEY_B, KEY_C, KEY_D, KEY_E,
        KEY_F, KEY_G, KEY_H, KEY_I, KEY_J,
        KEY_K, KEY_L, KEY_M, KEY_N, KEY_O,
        KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T,
        KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y,
        KEY_Z,
        KEY_0, KEY_1, KEY_2, KEY_3, KEY_4,
        KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
        KEY_ESCAPE, KEY_LCONTROL, KEY_LSHIFT, KEY_LALT, KEY_LSYSTEM,
        KEY_RCONTROL, KEY_RSHIFT, KEY_RALT, KEY_RSYSTEM, KEY_MENU,
        KEY_LBRACKET, KEY_RBRACKET, KEY_SEMICOLON, KEY_COMMA, KEY_PERIOD,
        KEY_QUOTE, KEY_SLASH, KEY_BACKSLASH, KEY_TILDE, KEY_EQUAL,
        KEY_HYPHEN, KEY_SPACE, KEY_ENTER, KEY_BACKSPACE, KEY_TAB,
        KEY_PAGEUP, KEY_PAGEDOWN, KEY_END, KEY_HOME, KEY_INSERT,
        KEY_DELETE, KEY_ADD, KEY_SUBTRACT, KEY_MULTIPLY, KEY_DIVIDE,
        KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN,
        KEY_NUM0, KEY_NUM1, KEY_NUM2, KEY_NUM3, KEY_NUM4,
        KEY_NUM5, KEY_NUM6, KEY_NUM7, KEY_NUM8, KEY_NUM9,
        KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5,
        KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10,
        KEY_F11, KEY_F12, KEY_F13, KEY_F14, KEY_F15,
        KEY_PAUSE, KEY_KEYCOUNT
    };

   public:

    /** \brief Constructor of the Input class used to signal that the user pressed on a key
    * \param code A key code based on an enum representing the key pressed
    * */
    Input(KEYCODE code = KEY_UNKNOWN);

    /** \brief Destructor of Input set as default*/
    ~Input() override;

   public:
    /** \brief The key that was pressed by the user */
    KEYCODE code;
};

}  // namespace event

}  // namespace engine

#endif  // OOP_ARCADE_2019_INPUT_HPP
