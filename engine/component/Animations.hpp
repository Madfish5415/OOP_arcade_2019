/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations.hpp
*/

#ifndef OOP_ARCADE_2019_ANIMATIONS_HPP
#define OOP_ARCADE_2019_ANIMATIONS_HPP

#include <map>

#include "../ecs/AComponent.hpp"
#include "../type/Animation.hpp"

namespace engine {

namespace component {

    /** \brief The Class used to animate entites */
class Animations : public ecs::AComponent {
   public:
    /** \brief Constructor of the Animations component
     * \param entity the Entity which the component belongs to
     * \param list A map of std::string and type::Animation that represent all the animations avaiable for
     * this entity and the name of the animation
     **/
    Animations(ecs::Entity& entity, const std::map<std::string, type::Animation>& list);

    /** \brief Destructor of the Animations set as default*/
    ~Animations() override;

   public:
    /** \brief A map of std::string and type::Animation that represent all the animations avaiable for
     * this entity and the name of the animation */
    const std::map<std::string, type::Animation> list;

    /** \brief An std::string used to explain the current animation used */
    std::string currentAnimation;

    /** \brief An int used to represent the current frame used on the texture */
    int currentFrame;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_ANIMATIONS_HPP
