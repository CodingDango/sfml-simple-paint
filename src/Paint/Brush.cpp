#include "Brush.h"

Brush::Brush(Brush::ShapeType shape_type, sf::Color& col)
:   m_shape_type { shape_type }
{
    setShape(shape_type);
}

void Brush::setShape(Brush::ShapeType shape_type)
{   
    switch (shape_type)
    {
    case Brush::Circle:
        m_shape = std::make_unique<sf::CircleShape>();
        break;
    case Brush::Rectangle:
        m_shape = std::make_unique<sf::RectangleShape>();
        break;
    default:
        std::cerr << "Shape type not identified\n";
        break;
    }
}

sf::Shape* Brush::getShape() const
{
    return m_shape.get();
}