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

class World {
   private:
    Universe& _universe;
    std::vector<std::reference_wrapper<Entity>> _entities;
    std::map<std::string, std::vector<std::reference_wrapper<Entity>>> _groups;
    std::map<std::type_index, std::reference_wrapper<ASystem>> _systems;

   public:
    World(Universe& universe);
    ~World();

   public:
    void init();
    void update();
    void render();

   public:
    Universe& getUniverse() const;

   public:
    Entity& createEntity();
    template <typename... TArgs>
    std::vector<std::reference_wrapper<Entity>> getEntities() const {
        std::vector<std::reference_wrapper<Entity>> list {};

        for (auto& entity : _entities) {
            if (entity.get().hasComponents<TArgs...>())
                list.emplace_back(entity.get());
        }

        return list;
    };
    void deleteEntity(Entity& entity);

   public:
    void addToGroup(Entity& entity, const std::string& group);
    bool hasGroup(Entity& entity, const std::string& group) const;
    std::vector<std::reference_wrapper<Entity>>& getGroup(const std::string& group) const;
    void removeFromGroup(Entity& entity, const std::string& group);

   public:
    template <typename T, typename... TArgs>
    T& addSystem(TArgs&&... mArgs) {
        std::type_index id = typeid(T);

        for (auto &s : _systems) {
            if (s.first == id)
                throw std::exception();
        }

        T* system = new T(*this, mArgs...);

        std::reference_wrapper<AComponent> ref_wrap = std::ref(*system);

        _systems.emplace(id, ref_wrap);

        return *system;
    };
    template <typename T = void, typename... TArgs>
    bool hasSystems() const {
        std::type_index id = typeid(T);
        bool has = this->_systems.count(id);

        if (sizeof...(TArgs))
            has &= this->hasSystems<TArgs...>();

        return has;
    };
    template <typename T>
    T& getSystem() const {
        std::type_index id = typeid(T);

        for (auto &s : _systems) {
            if (s.first == id)
                return static_cast<T>(s.second.get());
        }

        throw std::exception();
    };
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

}  // namespace ecs

}  // namespace engine

#endif  // OOP_ARCADE_2019_WORLD_HPP
