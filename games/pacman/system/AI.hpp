/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

namespace system {
    class AI : public engine::system::AAI {
        public:
            AI();
            ~AI();

            void init() override;
            void update() override;
            void render() override;
        protected:
        private:
    };
};

#endif /* !AI_HPP_ */
