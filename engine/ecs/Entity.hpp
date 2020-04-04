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

class Entity {
   private:
    World& _world;
    std::map<std::type_index, std::reference_wrapper<AComponent>> _components;

   public:
    Entity(World& world);
    ~Entity();

   public:
    World& getWorld() const;

   public:
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs) {
        std::type_index id = typeid(T);

        for (auto &c : _components) {
            if (c.first == id)
                throw std::exception();
        }

        T* component = new T(*this, mArgs...);

        std::reference_wrapper<AComponent> ref_wrap = std::ref(*component);

        _components.emplace(id, ref_wrap);

        return *component;
    };
    template <typename T = void, typename... TArgs>
    bool hasComponents() const {
        std::type_index id = typeid(T);
        bool has = this->_components.count(id);

        if (sizeof...(TArgs))
            has &= this->hasComponents<TArgs...>();

        return has;
    };
    template <typename T>
    T& getComponent() const {
        std::type_index id = typeid(T);

        for (auto &c : _components) {
            if (c.first == id)
                return static_cast<T&>(const_cast<AComponent&>(c.second.get()));
        }

        throw std::exception();
    };
    template <typename T>
    void removeComponent() {
        std::type_index id = typeid(T);

        auto itr = std::find_if(_components.begin(), _components.end(), [&id](auto &c){
          return c.first == id;
        });

        if (itr == _components.end())
            throw std::exception();

        delete &itr->second.get();

        _components.erase(itr);
    };
};

template <>
engine::component::ARender& Entity::addComponent<engine::component::ARender>(const std::vector<std::string>& paths);
template <>
engine::component::AAudio& Entity::addComponent<engine::component::AAudio>(const std::vector<std::string>& paths);
template <>
engine::component::AText& Entity::addComponent<engine::component::AText>(const std::string& text, const std::vector<std::string>& paths);

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_ENTITY_HPP
