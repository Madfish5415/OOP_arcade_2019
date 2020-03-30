/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

class User : public ecs::system::AUser {
    public:
        User();
        ~User();
        void init(event::EventBus& eventbus) override {
            // il faut init mais je dois demander aux pd
        }
        void update(World& world) override {
            // IDK
        }
        void render(World& world) override {
            // IDK
        }
    protected:
    private:
};

#endif /* !USER_HPP_ */