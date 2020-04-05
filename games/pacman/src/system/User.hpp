/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#ifndef USER_SYS_HPP_
#define USER_SYS_HPP_

#include "../../../engine/system/AUser.hpp"
#include "../../../engine/ecs/World.hpp"
#include "../../../engine/event/Input.hpp"

namespace pacman {
    namespace system {
        class User : public engine::system::AUser {
            public:
                User(engine::ecs::World& world);
                ~User();
    
                void init() override;
                void update() override;
                void render() override;
                void inputSubscriber(engine::event::Input& event);
                void collideSubscriber();
        };
    };
};

#endif /* !USER_HPP_ */