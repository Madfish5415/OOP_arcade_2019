/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.hpp
*/
#ifndef OOP_ARCADE_2019_UNIVERSE_HPP
#define OOP_ARCADE_2019_UNIVERSE_HPP

#include <functional>
#include <map>
#include <string>

namespace core {
class Core;
}

#include "../eventbus/EventBus.hpp"
#include "World.hpp"

namespace engine {

namespace ecs {

/** \brief The class that contains and manage all the worlds  */
class Universe {
   private:
    std::map<std::string, World*> _worlds {};
    std::string _currentWorld;
    eventbus::EventBus _eventbus;
    core::Core *_core;

   public:
    /** Default constructor initializing every field */
    Universe();

    /**
    * \param core A reference to the core that gets stocked in the _core attribute\n
    * \brief Constructor that just copy the core
    */
    Universe(core::Core& core);

    /** \brief Destructor that delete every world of the std::map _worlds*/
    ~Universe();

   public:
    /** \brief Call the init method of the current world, if there is no current world do nothing*/
    void init();

    /** \brief Call the update method of the current world, if there is no current world do nothing*/;
    void update();

    /** \brief Call the render method of the current world, if there is no current world do nothing*/;
    void render();

   public:
    /**
    * \return  The eventbus stocked in the attribute _eventBus
    */
    eventbus::EventBus& getEventBus();

    /** \return A reference to the core used by the universe\n
    * \brief If the core points to a nullptr throw an exception
    */
    core::Core& getCore();

   public:
    /** \param name Name of the world
    * \return  reference to the created world
    * \brief Create a new world named by the std::string passed as parameter*/
    World& createWorld(const std::string& name);

    /** \return true if the Universe contains a world named by the std::string passed as parameter, false otherwise*/
    bool hasWorld(const std::string& name) const;

    /**
     * \param name std::string representing the name of the wanted world
     * \return A reference to the world named by the std::string passed as parameter, throw an exception if the world does not exist*/
    World& getWorld(const std::string& name) const;

    /** \return An std::vector of std::string containing all the world's names*/
    std::vector<std::string> getWorldNames() const;

    /** \return A reference to the current world based on the attribute currentWorld, if there is no current world throw an exception */
    World& getCurrentWorld() const;

    /**
     * \param name std::string representing the name of the wanted current world
     * \brief Set the current world to the one named by the std::string passed as parameter if the name does not exist throw an exception */
    void setCurrentWorld(const std::string& name);

    /**
     * \param name std::string representing the name of world wanted to delete
     * \brief Delete the world named by the std::string passed as parameter if the name does not exist throw an exception */
    void deleteWorld(const std::string& name);

};

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_UNIVERSE_HPP
