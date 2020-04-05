/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_AAUDIO_HPP
#define OOP_ARCADE_2019_AAUDIO_HPP

#include <utility>
#include <vector>
#include <string>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

    /** \brief The Abstract Class used to create the Audio component */
class AAudio : public ecs::AComponent {
   public:
    /** \brief Constructor of the AAudio
     * \param entity the Entity which the component belongs to
     * \param paths A Vector of std::string representing the paths to the audio:
     * paths[0] is the path for the text libraries (Ncurses)
     * paths[1] is the path for the graphic libraries (SFML / SDL)
     * paths[2] is the path for the debug library
     **/
    AAudio(ecs::Entity& entity, const std::vector<std::string>& paths);

    /** \brief Destructor of the AAudio set as default*/
    ~AAudio() override = 0;

   public:
    /** \brief A vector of std::string representing the paths to the audio as explained above*/
    const std::vector<std::string> paths;
};

}  // namespace component

}  // namespace engine

#endif // OOP_ARCADE_2019_AAUDIO_HPP
