/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include "../../../../engine/component/AUser.hpp"
#include "../../../../engine/ecs/Entity.hpp"

namespace pacman {
    namespace component {
        class User : public engine::component::AUser {
            public:
                User(engine::ecs::Entity& entity);
                ~User();
    
            protected:
            private:
        };
    };
};

#endif /* !USER_HPP_ */
