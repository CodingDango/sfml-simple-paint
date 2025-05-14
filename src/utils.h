#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <SFML/Graphics.hpp>

namespace utils 
{
    template <typename T>
    inline sf::Vector2f toVector2f(const T& vect)
    {
        return sf::Vector2f(
            static_cast<float>(vect.x), 
            static_cast<float>(vect.y)
        );
    }

    template <typename T>
    inline sf::Vector2f midpointOfSizeVector(const T& vect)
    {
        return sf::Vector2f(
            static_cast<float>(vect.x / 2.0f),
            static_cast<float>(vect.y / 2.0f) 
        ); 
    }
}

#endif
