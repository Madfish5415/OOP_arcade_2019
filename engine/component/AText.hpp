/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AText.hpp
*/

#ifndef OOP_ARCADE_2019_ATEXT_HPP
#define OOP_ARCADE_2019_ATEXT_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

    /** \brief The Abstract Class used to display entites using text */
class AText : public ecs::AComponent {
   public:
    /** \brief Constructor of the AText
    * \param entity the Entity which the component belongs to
    * \param text an std::string that represents the text to display
    * \param paths A Vector of std::string representing the paths to the font:
    * paths[0] is the path for the text libraries (Ncurses)
    * paths[1] is the path for the graphic libraries (SFML / SDL)
    * paths[2] is the path for the debug library
    **/
    explicit AText(ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths);

    /** \brief Destructor of the AAudio set as default*/
    ~AText() override = 0;

   public:
    /** \brief an std::string representing the text to display */
    std::string text;

    /** \brief A vector of std::string representing the paths to the audio as explained above*/
    const std::vector<std::string> paths;
};

}  // namespace component

}  // namespace engine

#endif  // OOP_ARCADE_2019_ATEXT_HPP
