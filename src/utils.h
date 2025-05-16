#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <SFML/Graphics.hpp>

namespace utils 
{
    template <typename T>
    T clamp(const T& max, const T& min, const T& val)
    {   
        if (val < min)
            return min;
        else if (val > max)
            return max;
        return val;
    }

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

    inline sf::Color modifyOpacity(sf::Color col, sf::Uint8 val)
    {
        col.a = clamp<sf::Uint8>(255, 0, val); 
        return col;
    }

    template <typename T>
    inline T multiplyVectByVect(const T& vect1, const T& vect2)
    {
        return {vect1.x * vect2.x, vect1.y * vect2.y};
    }

    template <typename T>
    inline T multiplyVectByFactor(const T& vect, float factor)
    {
        return {vect.x * factor, vect.y * factor};
    }
}

#endif
