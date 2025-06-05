// In Brush.h

#ifndef BRUSH_H
#define BRUSH_H

// Keep existing includes
#include "EntityTypes.h" // Keep this if needed for other things
#include <SFML/Graphics.hpp>

// Add specific headers for the shape types we'll use with unique_ptr
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp> // <--- Add this for Triangle/Star

// Need cmath for trigonometric functions (sin, cos) and M_PI for point calculations
#include <cmath>
// Define M_PI if your compiler doesn't provide it in cmath by default (common on Windows/MSVC)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <memory> // For std::unique_ptr

class Brush
{   
public:
    enum ShapeType {
        Circle = 0,
        Rectangle = 1,
        Triangle = 2,
        Star = 3,
    };
    
    Brush(Brush::ShapeType shape_type, sf::Color col, float size);

    void setShapeType(Brush::ShapeType type);
    void setSize(float size);
    void setColor(const sf::Color& col);
    void setPosition(const sf::Vector2f vect);

    sf::Color getFillColor() const;
    const sf::Shape& getShape() const;
    ShapeType getShapeType() const; 

private:
    // Brush State
    ShapeType m_shape_type; 
    std::unique_ptr<sf::Shape> m_shape_ptr;
    sf::Color m_color;
    float m_size;

    void configureBrushShape();
    void centerBrushOrigin();
};  

#endif