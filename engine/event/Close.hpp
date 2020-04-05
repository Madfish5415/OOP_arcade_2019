/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Close.hpp
*/

#ifndef OOP_ARCADE_2019_CLOSE_HPP
#define OOP_ARCADE_2019_CLOSE_HPP

#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

    /** \brief The class used to signal that the user closed the window */
class Close : public eventbus::AEvent {
   public:
    /** \brief Constructor of the Close class used to signal that the user closed the window */
    Close();

    /** \brief Destructor of Close set as default*/
    ~Close() override;
};

}  // namespace event

}  // namespace engine

#endif  // OOP_ARCADE_2019_CLOSE_HPP
