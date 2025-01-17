/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#ifndef USER_SYS_HPP_
#define USER_SYS_HPP_

#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../../../../engine/event/Input.hpp"
#include "../../../../engine/system/AUser.hpp"

namespace pacman {
namespace system {
class User : public engine::system::AUser {
   public:
    User(engine::ecs::World& world);
    ~User();

   public:
    void init() override;
    void update() override;
    void render() override;

   public:
    void inputSubscriber(engine::event::Input& event);
    void receivePacGumCollision(engine::event::Collision& event);
    void receiveGhostCollision(engine::event::Collision& event);
};
};  // namespace system
};  // namespace pacman

#endif /* !USER_HPP_ */