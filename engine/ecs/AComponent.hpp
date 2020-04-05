/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_ARCADE_2019_ACOMPONENT_HPP
#define OOP_ARCADE_2019_ACOMPONENT_HPP

namespace engine {
namespace ecs {
class Entity;
}
}

namespace engine {

namespace ecs {

    /** \brief The Abstract Class used to represent all components */
class AComponent {
   protected:
    /** \brief The entity that the components belongs to */
    Entity& _entity;

   public:
    /** \brief Constructor of the AComponent abstract class
     * \param entity A reference the entity which it belongs to
     */
    explicit AComponent(Entity& entity);

    /** \brief Destructor of the abstract component
     * Set as default
     **/
    virtual ~AComponent() = 0;

   public:
    /** \brief Return the entity which the component belongs to
    * \return A Reference to the entity
    * */
    Entity& getEntity() const;
};

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_ACOMPONENT_HPP
