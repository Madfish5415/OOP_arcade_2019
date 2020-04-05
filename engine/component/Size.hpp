/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.hpp
*/

#ifndef OOP_ARCADE_2019_SIZE_HPP
#define OOP_ARCADE_2019_SIZE_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

    /** \brief The Class used to manage the size of entities */
class Size : public ecs::AComponent {
   public:
    /** \brief Constructor of the Size
    * \param entity the Entity which the component belongs to
    * \param width an int representing the width to be displayed on screen
    * \param height an int representing the width to be displayed on screen
    **/
    explicit Size(ecs::Entity& entity, int width = 0, int height = 0);

    /** \brief Destructor of the Motion set as default*/
    ~Size() override;

   public:
    /** \brief width an int representing the width to be displayed on screen*/
    int width;

    /** \brief height an int representing the width to be displayed on screen*/
    int height;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_SIZE_HPP
