/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Follow
*/

#ifndef FOLLOW_HPP_
#define FOLLOW_HPP_

class Follow : public ecs::system::AFollow {
    public:
        Follow();
        ~Follow();
        void init(event::EventBus& eventbus) override;
        void update(World& world) override;
        void render(World& world) override;
    protected:
    private:
};

#endif /* !FOLLOW_HPP_ */