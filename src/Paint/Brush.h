#ifndef BRUSH_H
#define BRUSH_H

#include "EntityTypes.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

class Brush
{   
public:
    enum ShapeType {
        Circle = 0,
        Rectangle = 1
    };
    
    Brush(Brush::ShapeType shape_type, sf::Color col, float size);

    void setShapeType(Brush::ShapeType type);
    void setSize(float size);
    void setColor(const sf::Color& col);
    void setPosition(const sf::Vector2f vect);

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
    void applySizeToShape();
};  


#endif
