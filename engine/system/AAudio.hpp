/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_AAUDIO_SYSTEM_HPP
#define OOP_ARCADE_2019_AAUDIO_SYSTEM_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {

/** \brief The Abstract Class used to manage all the Audio components */
class AAudio : public ecs::ASystem {
   public:
    /** \brief Constructor of the AAudio
    * \param world the world which the system belongs to
    **/
    explicit AAudio(ecs::World& world);

    /** \brief Destructor of the AAudio set as default*/
    ~AAudio() override = 0;

   public:
    /** \brief Initialize the system*/
    void init() override = 0;

    /** \brief Update the system and its Audio component*/
    void update() override = 0;

    /** \brief Render of the system, used to play the sound */
    void render() override = 0;
};

}  // namespace system

}  // namespace engine

#endif  // OOP_ARCADE_2019_AAUDIO_SYSTEM_HPP
