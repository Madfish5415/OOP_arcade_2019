/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ASystem.hpp
*/

#ifndef OOP_ARCADE_2019_ASYSTEM_HPP
#define OOP_ARCADE_2019_ASYSTEM_HPP

namespace engine {
namespace ecs {
class World;
}
}

namespace engine {

namespace ecs {
/** \brief The Abstract Class used to represent all the systems that must manage entities having special components */
class ASystem {
   protected:
    /** \brief The world that the system belongs to */
    World& _world;

   public:
    /** \brief Constructor of the ASystem abstract class
     * \param world A reference to the world which it belongs to
     */
    explicit ASystem(World& world);

    /** \brief Destructor of the abstract component
     * Set as default
     **/
    virtual ~ASystem() = 0;

   public:
    /** \brief Return the entity which the component belongs to
    * \return A Reference to the entity
    * */
    World& getWorld() const;

   public:
    /** \brief Init the entites that belongs to the System
    * */
    virtual void init() = 0;

    /** \brief Update the entites that belongs to the System
   * */
    virtual void update() = 0;

    /** \brief Render the entites that belongs to the System
   * */
    virtual void render() = 0;
};

}

}

#endif // OOP_ARCADE_2019_ASYSTEM_HPP
