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
    inline sf::Vector2f midOfVect(const T& vect)
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
    inline T multVectByVect(const T& vect1, const T& vect2)
    {
        return {vect1.x * vect2.x, vect1.y * vect2.y};
    }

    template <typename T>
    inline T multVectByFactor(const T& vect, float factor)
    {
        return {vect.x * factor, vect.y * factor};
    }

    template <typename T>
    inline T divVectByVect(const T& vect1, const T& vect2)
    {
        return {vect1.x / vect2.x, vect1.y / vect2.y};
    }

    template <typename T>
    inline T divVectByFactor(const T& vect, float factor)
    {
        return {vect.x / factor, vect.y / factor};
    }

    template <typename T>
    inline float vectLength(const T& vect)
    {
        return sqrt((vect.x * vect.x) + (vect.y * vect.y));
    }

    inline sf::Font loadFontFromFile(const std::string& path)
    {
        sf::Font font;
        font.loadFromFile(path);
        
        return font;
    }

    template <typename T>
    inline bool isVectNotZero(const T& vect)
    {
        return (vect.x != 0 && vect.y != 0);
    }

    inline sf::Color scaleColor(sf::Color col, float factor)
    {
        col.r = clamp<int>(255, 0, col.r * factor); 
        col.g = clamp<int>(255, 0, col.g * factor); 
        col.b = clamp<int>(255, 0, col.b * factor);
        
        return col;
    }
}


#endif