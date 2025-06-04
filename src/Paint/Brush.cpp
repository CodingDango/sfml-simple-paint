#include "Brush.h"

Brush::Brush(Brush::ShapeType shape_type, sf::Color col, float size)
:   m_shape_type  { shape_type },
    m_color { col },
    m_size  { size }
{
    configureBrushShape();
}

void Brush::configureBrushShape()
{   
    switch (m_shape_type)
    {
    case Brush::Circle:
        m_shape_ptr = std::make_unique<sf::CircleShape>();
        break;
    case Brush::Rectangle:
        m_shape_ptr = std::make_unique<sf::RectangleShape>();
        break;
    default:
        break;
    }

    m_shape_ptr->setFillColor(m_color);
    applySizeToShape();
    centerBrushOrigin();
}

void Brush::setShapeType(Brush::ShapeType type)
{
    m_shape_type = type;
    configureBrushShape();
}

void Brush::setSize(float size) 
{
    if (size <= 0)
    {
        std::cerr << "[Brush] Size cannot be negative!\n";
        return;
    }
    
    m_size = size;
    applySizeToShape();
    centerBrushOrigin();
}

void Brush::setColor(const sf::Color& col)
{
    m_color = col;

    if (!m_shape_ptr)
    {
        std::cerr << "[Brush] Attempted to setColor on null\n";
        return;
    }

    m_shape_ptr->setFillColor(m_color);
}

void Brush::setPosition(const sf::Vector2f vect)
{
    m_shape_ptr->setPosition(vect);
}

const sf::Shape& Brush::getShape() const
{
    return *m_shape_ptr.get();
}

Brush::ShapeType Brush::getShapeType() const
{
    return m_shape_type;
}

sf::Color Brush::getFillColor() const
{
    return m_color;
}

void Brush::centerBrushOrigin()
{
    if (!m_shape_ptr) 
    {
        std::cerr << "[Brush] Centering an invalid shape!\n";
        return;
    }   
    const float origin_cords = m_size / 2.0f;
    m_shape_ptr->setOrigin(origin_cords, origin_cords);
}

void Brush::applySizeToShape()
{
    if (!m_shape_ptr)
    {
        std::cerr << "[Brush] Applying size to a nullptr shape!\n";
        return;
    }

    switch (m_shape_type)
    {
    case Brush::ShapeType::Circle:
        // So the total diameter is indeed brush_size
        static_cast<sf::CircleShape*>(m_shape_ptr.get())
            ->setRadius(m_size / 2);  
        break;

    case Brush::ShapeType::Rectangle:
        static_cast<sf::RectangleShape*>(m_shape_ptr.get())
            ->setSize({m_size, m_size});
        break;

    default:
        break;
    }
}