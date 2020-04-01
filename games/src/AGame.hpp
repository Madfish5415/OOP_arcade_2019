/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame
*/

#ifndef AGAME_HPP_
#define AGAME_HPP_

#include <string>
#include "IGame.hpp"

namespace game {
    class AGame : public IGame {
        public:
            AGame(engine::ecs::Universe& universe, const std::string name);
            virtual ~AGame() = 0;
    
            std::string getName() override;
    
            void init() override = 0;
            void destroy() override = 0;
        protected:
            engine::ecs::Universe& _universe;
        private:
            std::string _name;
    };
};

#endif /* !AGAME_HPP_ */