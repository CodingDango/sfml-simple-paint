#ifndef BRUSH_H
#define BRUSH_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

class Brush : public sf::Drawable
{   
public:
    enum ShapeType {
        Circle = 0,
        Rectangle = 1
    };

    void update(const sf::Vector2f& mouse_pos)
    {

    }
    
    Brush(ShapeType shape, sf::Color& col);
    void setShape(ShapeType shape);
    sf::Shape* getShape() const;
    
private:
    static const 

    ShapeType m_shape_type; 
    std::unique_ptr<sf::Shape> m_shape;
};  


#endif
