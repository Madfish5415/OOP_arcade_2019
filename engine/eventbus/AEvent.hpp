/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AEvent.hpp
*/

#ifndef OOP_ARCADE_2019_AEVENT_HPP
#define OOP_ARCADE_2019_AEVENT_HPP

namespace engine {

namespace eventbus {

    /** \brief The Abstract Class used to represent all the events that may happens during the execution */
class AEvent {
   public:
    /** \brief Constructor of the AEvent abstract class */
    AEvent();

    /** \brief Destructor of the abstract component
     * Set as default
     **/
    virtual ~AEvent() = 0;
};

}  // namespace eventbus

}  // namespace engine

#endif  // OOP_ARCADE_2019_AEVENT_HPP
