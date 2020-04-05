/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity.hpp
*/

#ifndef OOP_ARCADE_2019_ENTITY_HPP
#define OOP_ARCADE_2019_ENTITY_HPP

namespace engine {
namespace ecs {
class World;
}  // namespace ecs
}  // namespace engine

#include <functional>
#include <map>
#include <typeindex>
#include <algorithm>

#include "AComponent.hpp"
#include "../../lib/graphical/IGraphical.hpp"

namespace engine {

namespace ecs {

    /** \brief The class used to represent every Entity (everything used on the game) that can have different components */
class Entity {
   private:
    World& _world;
    std::map<std::type_index, std::reference_wrapper<AComponent>> _components;

   public:
    /** \brief Constructor of the entity
    * \param world The world which the entity belongs to
    **/
    Entity(World& world);

    /** \brief Destructor of the entity
     * Delete the components that the entity contains
     **/
    ~Entity();

   public:
    /** \brief Return the world which the entity belongs to
    * \return A Reference to the world
    * */
    World& getWorld() const;

   public:
    /** \brief Add the component based on the typename to the entity
    *  \return A reference to the component
    * */
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs) {
        std::type_index id = typeid(T);

        for (auto& c : _components) {
            if (c.first == id)
                throw std::exception();
        }

        T* component = new T(*this, mArgs...);

        std::reference_wrapper<AComponent> ref_wrap = std::ref(*component);

        _components.emplace(id, ref_wrap);

        return *component;
    };

    /** \brief Return a boolean defining if the entity has a component specified by the typename
    * \return true if the entity got the component, false otherwise
    * */
    template <typename T = void, typename... TArgs>
    bool hasComponents() const {
        std::type_index id = typeid(T);
        bool has = this->_components.count(id);

        if (sizeof...(TArgs))
            has &= this->hasComponents<TArgs...>();

        return has;
    };

    /** \brief Return the component specified by the typename
    * \return A reference to the component asked
    * */
    template <typename T>
    T& getComponent() const {
        std::type_index id = typeid(T);

        for (auto& c : _components) {
            if (c.first == id)
                return static_cast<T&>(const_cast<AComponent&>(c.second.get()));
        }

        throw std::exception();
    };

    /** \brief Delete the component specified by the typename
    * */
    template <typename T>
    void removeComponent() {
        std::type_index id = typeid(T);

        auto itr = std::find_if(_components.begin(), _components.end(), [&id](auto& c){
          return c.first == id;
        });

        if (itr == _components.end())
            throw std::exception();

        delete &itr->second.get();

        _components.erase(itr);
    };
};

/** \brief Add the component Render to the entity
* \param paths a vector of std::string that represent all the paths to the texture where:
* paths[0] is the path for the text libraries (Ncurses)
* paths[1] is the path for the graphic libraries (SFML / SDL)
* paths[2] is the path for the debug librarie
\return A reference to the component
* */
template <>
engine::component::ARender& Entity::addComponent<engine::component::ARender>(const std::vector<std::string>& paths);

/** \brief Add the component Audio to the entity
* \param paths a vector of std::string that represent all the paths to the music where:
* paths[0] is the path for the text libraries (Ncurses)
* paths[1] is the path for the graphic libraries (SFML / SDL)
* paths[2] is the path for the debug librarie
\return A reference to the component
* */

template <>
engine::component::AAudio& Entity::addComponent<engine::component::AAudio>(const std::vector<std::string>& paths);

/** \brief Add the component Text to the entity
* \param text an std::string representing the text to display
* \param paths a vector of std::string that represent all the paths to the text where:
* paths[0] is the path for the text libraries (Ncurses)
* paths[1] is the path for the graphic libraries (SFML / SDL)
* paths[2] is the path for the debug librarie
\return A reference to the component
* */
template <>
engine::component::AText& Entity::addComponent<engine::component::AText>(const std::string& text, const std::vector<std::string>& paths);

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_ENTITY_HPP
