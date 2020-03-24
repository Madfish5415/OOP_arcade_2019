/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** World.hpp
*/

#ifndef OOP_ARCADE_2019_WORLD_HPP
#define OOP_ARCADE_2019_WORLD_HPP

using GroupID = std::string;

namespace ecs {

class World {
   private:
    std::vector<std::shared_ptr<Entity>> _entities {};
    std::map<GroupID, std::vector<std::shared_ptr<Entity>>> _groups {};

   public:
    World() = default;
    ~World() = default;

    void refresh() {
        for (auto& i : _groups) {
            i.second.erase(std::remove_if(std::begin(i.second), std::end(v), [i.first](Entity* entity){return !entity->isActive();}), std::end(i.second));
        }

        _entities.erase(std::remove_if(std::begin(_entities), std::end(_entities), [](const std::unique_ptr<Entity>& entity) { return !entity->isActive();}), std::end(entities));
    }

    void addToGroup(Entity* entity, GroupID group) {
        _groups[group].push_back(entity);
    }

    void delFromGroup(Entity* entity, GroupID group) {
        _groups[group].erase(entity);
    }

    void hasGroup(Entity* entity, GroupID group);

    std::vector<std::shared_ptr<Entity>>& getGroup(GroupID group) {
        return _groups[group];
    }

    template <typename... TArgs>
    std::vector<std::shared_ptr<Entity>>& getEntities();

    Entity& addEntity() {
        Entity* entity = new Entity(*this);

        std::shared_ptr<Entity> sPtr{entity};
        entities.emplace_back(std::move(sPtr));
        return *e;
    }
}

}  // namespace ecs

#endif  // OOP_ARCADE_2019_WORLD_HPP
