/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

class AI : public ecs::system::AAI {
    public:
        AI();
        ~AI();
        void init(event::EventBus& eventbus) override;
        void update(World &world) override;
        void render(World& world) override;
    protected:
    private:
};

#endif /* !AI_HPP_ */