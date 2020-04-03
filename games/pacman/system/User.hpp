/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

namespace pacman {
    namespace system {
        class User : public engine::system::AUser {
            public:
                User();
                ~User();
    
                void init() override;
                void update() override;
                void render() override;
            protected:
            private:
        };
    };
};

#endif /* !USER_HPP_ */