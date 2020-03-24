/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.hpp
*/

#ifndef OOP_ARCADE_2019_UNIVERSE_HPP
#define OOP_ARCADE_2019_UNIVERSE_HPP

#include "WorldManager.hpp"

namespace ecs {

class Universe {
   private:
    std::vector<std::reference_wrapper<WorldManager>> _managers{};

   public:
    Universe() = default;
    ~Universe();

    void addWorldManager(WorldManager& world)
    {
        _managers.push_back(world);
    }

    void delWorldManager()
    {
        _managers.pop_back();
    }
};

}  // namespace ecs

#endif  // OOP_ARCADE_2019_UNIVERSE_HPP
