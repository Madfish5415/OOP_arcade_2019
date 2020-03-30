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
        void init(event::EventBus& eventbus) override {
            // il faut init et que je demande aux pd
        }
        void update(World& world) override {
            // faire un bail avec chopé la pos du pacman et faire en sorte que calculé un vector pour que le fantôme le suive.
        }
        void render(World& world) override {
            // aucune idée
        }
    protected:
    private:
};

#endif /* !FOLLOW_HPP_ */