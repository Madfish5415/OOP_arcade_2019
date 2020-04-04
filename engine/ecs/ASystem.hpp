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

class ASystem {
   protected:
    World& _world;

   public:
    explicit ASystem(World& world);
    virtual ~ASystem() = 0;

   public:
    World& getWorld() const;

   public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

}

}

#endif // OOP_ARCADE_2019_ASYSTEM_HPP
