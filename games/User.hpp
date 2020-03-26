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
        void init(event::EventBus& eventbus) override;
        void update(World& world) override;
        void update(World& world) override;
    protected:
    private:
};

#endif /* !USER_HPP_ */