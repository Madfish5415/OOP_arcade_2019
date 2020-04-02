/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.hpp
*/

#ifndef OOP_ARCADE_2019_CORE_HPP
#define OOP_ARCADE_2019_CORE_HPP

#include <map>
#include <string>

#include "../../engine/ecs/Universe.hpp"
#include "../../games/game/IGame.hpp"
#include "../../lib/graphical/IGraphical.hpp"
#include "DynamicLib.hpp"

namespace core {

class Core {
   private:
    std::map<std::string, DynamicLib<graphical::IGraphical>*> _graphicals;
    std::map<std::string, DynamicLib<game::IGame>*> _games;
    std::string _currentGraphical;
    std::string _currentGame;
    engine::ecs::Universe _universe;

    Core();
    ~Core();

    void loadGames();
    void loadGraphics();

    engine::ecs::Universe& getUniverse() const;

    bool hasGame(const std::string& name) const;
    game::IGame& getGame(const std::string& name) const;
    game::IGame& getCurrentGame() const;
    void setCurrentGame(const std::string& name);

    bool hasGraphical(const std::string& name) const;
    graphical::IGraphical& getGraphical(const std::string& name) const;
    graphical::IGraphical& getCurrentGraphical() const;
    void setCurrentGraphical(const std::string& name);
};

}  // namespace core

#endif  // OOP_ARCADE_2019_CORE_HPP
