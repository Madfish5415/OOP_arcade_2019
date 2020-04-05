/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** World.hpp
*/
#ifndef OOP_ARCADE_2019_WORLD_HPP
#define OOP_ARCADE_2019_WORLD_HPP

namespace engine {
namespace ecs {
class Universe;
}  // namespace ecs
}  // namespace engine

#include <functional>
#include <map>
#include <typeindex>
#include <vector>
#include <exception>
#include <algorithm>

#include "ASystem.hpp"
#include "Entity.hpp"

namespace engine {

namespace ecs {

    /** \brief The Class used represent everything appearing on screen like a Menu or Pacman */
class World {
   private:
    Universe& _universe;
    std::vector<std::reference_wrapper<Entity>> _entities;
    std::map<std::string, std::vector<std::reference_wrapper<Entity>>> _groups;
    std::map<std::type_index, std::reference_wrapper<ASystem>> _systems;

   public:
    /** \brief Constructor of the world
     * \param universe The universe which the worlds belongs to
     **/
    World(Universe& universe);
    /** \brief Destructor of the world
     * Delete the entites, the groups and the systems that the world contains
     **/
    ~World();

   public:
    /** \brief Call the init method of every system the world contains */
    void init();

    /** \brief Call the update method of every system the world contains */
    void update();

    /** \brief Call the render method of every system the world contains */
    void render();

   public:
    /** \brief Return the universe which the world belongs to
     * \return A Reference to the universe
     * */
    Universe& getUniverse() const;

   public:
    /** \brief Create an entity and add it to the entity vector
     * \return A reference to the newly created Entity
     * */
    Entity& createEntity();

    /** \brief Return all the entites having the components asked by the typename
     * \return An std::vector of std::reference_wrapper to the asked entites
     * */
    template <typename... TArgs>
    std::vector<std::reference_wrapper<Entity>> getEntities() const {
        std::vector<std::reference_wrapper<Entity>> list {};

        for (auto& entity : _entities) {
            if (entity.get().hasComponents<TArgs...>())
                list.emplace_back(entity.get());
        }

        return list;
    };

    /** \brief Delete the entity entered as parameter
     * \param entity A reference to the entity that must be deleted
     * */

    void deleteEntity(Entity& entity);

   public:
    /** \brief Add the entity to a group
     * \param entity A reference to the  Entity
     * \param group A reference to a const std::string that contain the name of the group that entity must be added to
     * */
    void addToGroup(Entity& entity, const std::string& group);

    /** \brief Verify if the entity is a member of a certain group
     * \param entity A reference to the  Entity
     * \param group A reference to a const std::string that represents the name of the group
     * \return true if the entity is a member of the groupe, false otherwise
     * */
    bool hasGroup(Entity& entity, const std::string& group) const;

    /** \brief Return a boolean defining if  the entity is a member of a group
    * \param group A reference to a const std::string that represents the name of the group
    * \return An std::vector of std::reference_wrapper to the entites
    * */
    std::vector<std::reference_wrapper<Entity>>& getGroup(const std::string& group) const;

    /** \brief Remove the entity from a group
    * \param entity A reference to the  Entity
    * \param group A reference to a const std::string that represents the name of the group
    * */
    void removeFromGroup(Entity& entity, const std::string& group);

   public:
    /** \brief Add the system based on the typename to the world
    *  \return A reference to the system
    * */
    template <typename T, typename... TArgs>
    T& addSystem(TArgs&&... mArgs) {
        std::type_index id = typeid(T);

        for (auto& s : _systems) {
            if (s.first == id)
                throw std::exception();
        }

        T* system = new T(*this, mArgs...);

        std::reference_wrapper<ASystem> ref_wrap = std::ref(*system);

        _systems.emplace(id, ref_wrap);

        return *system;
    };

    /** \brief Return a boolean defining if the world has a system specified by the typename
    * \return true if the world got the system, false otherwise
    * */
    template <typename T = void, typename... TArgs>
    bool hasSystems() const {
        std::type_index id = typeid(T);
        bool has = this->_systems.count(id);

        if (sizeof...(TArgs))
            has &= this->hasSystems<TArgs...>();

        return has;
    };

    /** \brief Return the system specified by the typename
    * \return A reference to the system asked
    * */
    template <typename T>
    T& getSystem() const {
        std::type_index id = typeid(T);

        for (auto& s : _systems) {
            if (s.first == id)
                return static_cast<T>(s.second.get());
        }

        throw std::exception();
    };

    /** \brief Delete the system specified by the typename
    * */
    template <typename T>
    void removeSystem() {
        std::type_index id = typeid(T);

        auto itr = std::find_if(_systems.begin(), _systems.end(), [&id](auto &s){
            return s.first == id;
        });

        if (itr == _systems.end())
            throw std::exception();

        delete &itr->second.get();

        _systems.erase(itr);
    };
};

/** \brief Add the system Audio to the world
\return A reference to the system
* */
template <>
engine::system::AAudio& World::addSystem<engine::system::AAudio>();

/** \brief Add the system Animation to the world
\return A reference to the system
* */
template <>
engine::system::AAnimations& World::addSystem<engine::system::AAnimations>();


/** \brief Add the system World to the world
\return A reference to the system
* */
template <>
engine::system::ARender& World::addSystem<engine::system::ARender>();

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_WORLD_HPP
