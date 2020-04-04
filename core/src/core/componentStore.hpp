/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** componentStore.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENTSTORE_HPP
#define OOP_ARCADE_2019_COMPONENTSTORE_HPP

#include <tuple>

#include "../../../engine/ecs/Entity.hpp"

namespace core {

template <typename T, typename... TArgs>
class componentStore {
   public:
    componentStore(engine::ecs::Entity& entity, TArgs... args) : _entity(entity), _args(args...)
    {
    }

    ~componentStore() = default;

   public:
    void addToEntity()
    {
        std::apply([this](auto... args) { this->_entity.template addComponent<T>(args...); }, _args);
    }

    void removeFromEntity()
    {
        _entity.removeComponent<T>();
    }

   private:
    engine::ecs::Entity& _entity;
    std::tuple<TArgs...> _args;
};

template <>
void componentStore<engine::component::AAudio, std::vector<std::string>>::addToEntity()
{
    std::apply([this](const std::vector<std::string>& paths) { this->_entity.template addComponent<engine::component::AAudio>(paths); }, _args);
}

template <>
void componentStore<engine::component::ARender, std::vector<std::string>>::addToEntity()
{
    std::apply([this](const std::vector<std::string>& paths) { this->_entity.template addComponent<engine::component::ARender>(paths); }, _args);
}

template <>
void componentStore<engine::component::AText, std::string, std::vector<std::string>>::addToEntity()
{
    std::apply([this](const std::string& text,
                   const std::vector<std::string>& paths) { this->_entity.template addComponent<engine::component::AText>(text, paths); },
        _args);
}

}  // namespace core

#endif  // OOP_ARCADE_2019_COMPONENTSTORE_HPP
