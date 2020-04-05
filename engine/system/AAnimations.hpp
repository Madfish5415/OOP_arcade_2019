/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAnimations.hpp
*/

#ifndef OOP_ARCADE_2019_AANIMATIONS_HPP
#define OOP_ARCADE_2019_AANIMATIONS_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
    /** \brief The Abstract Class used to manage all the Animations components */
class AAnimations : public ecs::ASystem {
   public:
    /** \brief Constructor of the AAnimations
    * \param world the world which the system belongs to
    **/
    explicit AAnimations(ecs::World& world);

    /** \brief Destructor of the AUser set as default*/
    ~AAnimations() override = 0;

   public:
    /** \brief Initialize the system*/
    void init() override = 0;

    /** \brief Update the system and its Animations component*/
    void update() override = 0;

    /** \brief Render of the system, used only if there is something to render */
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif // OOP_ARCADE_2019_AANIMATIONS_HPP
