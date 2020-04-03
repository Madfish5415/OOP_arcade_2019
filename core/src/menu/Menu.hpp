/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Menu.hpp
*/

#ifndef OOP_ARCADE_2019_MENU_HPP
#define OOP_ARCADE_2019_MENU_HPP

#include "../../../games/game/AGame.hpp"

namespace menu {

class Menu : public game::AGame {
   public:
    Menu(engine::ecs::Universe& universe);
    virtual ~Menu();

   public:
    void init() override;
    void destroy() override;
};

}  // namespace menu

#endif  // OOP_ARCADE_2019_MENU_HPP
