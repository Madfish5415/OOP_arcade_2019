/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Switch.hpp
*/

#ifndef OOP_ARCADE_2019_SWITCH_HPP
#define OOP_ARCADE_2019_SWITCH_HPP

#include <string>

#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

    /** \brief The class used to signal that the user wants to change the game / graphical libraries */
class Switch : public eventbus::AEvent {
   public:

    /** \brief Constructor of the Switch class used to signal that the user wanted to change the game / graphical libraries
    * \param type the type of library expected to change, possibilites are game or graphical
    * \param name the name of library that the user wants to change to
    * */
    explicit Switch(std::string type = "", std::string name = "");

    /** \brief Destructor of Input set as default*/
    ~Switch() override;

   public:
    /** \brief The type of the change asked by the user (graphical or game) */
    std::string type;

    /** \brief The name of the library that the user want to change to */
    std::string name;
};

}  // namespace event

}  // namespace engine

#endif  // OOP_ARCADE_2019_SWITCH_HPP
