/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "../../../../engine/component/AAI.hpp"
#include "../../../../engine/ecs/Entity.hpp"
#include "../../../../engine/type/Vector2D.hpp"

namespace pacman {

namespace component {

class AI : public engine::component::AAI {
   public:
    explicit AI(engine::ecs::Entity& entity);
    ~AI() override;

   public:
    engine::type::Vector2D oldVelocity;
};

};  // namespace component

};  // namespace pacman

#endif /* !AI_HPP_ */
