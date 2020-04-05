/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_USER_SYSTEM_HPP
#define OOP_ARCADE_2019_USER_SYSTEM_HPP

#include "../../../../engine/system/AUser.hpp"
#include "../../../../engine/event/Input.hpp"

namespace menu {

namespace system {

class User : public engine::system::AUser {
   public:
    explicit User(engine::ecs::World& world);
    ~User() override;

   public:
    void init() override;
    void update() override;
    void render() override;

   public:
    void inputSubscriber(engine::event::Input& event);
};

}  // namespace system

}  // namespace menu

#endif  // OOP_ARCADE_2019_USER_SYSTEM_HPP
