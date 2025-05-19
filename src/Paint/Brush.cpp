#include "Brush.h"

void Brush::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed 
        && event.mouseButton.button == sf::Mouse::Left)
        m_is_brush_painting = true;
}

void Brush::update(float dt, const sf::Vector2f& mouse_pos)
{
    if (m_is_brush_painting)
        m_shape_ptr->setPosition(mouse_pos);

    else 
        m_shape_ptr->setPosition(M_BRUSH_INACTIVE_POS); 
}

void Brush::render(sf::RenderTarget& dest) const
{
    dest.draw(*m_shape_ptr);
}

Brush::Brush(Brush::ShapeType shape_type, sf::Color col, float size)
:   m_shape_type  { shape_type },
    m_brush_color { col },
    m_brush_size  { size }
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
        m_shape_ptr = nullptr;
        break;
    }

    if (!m_shape_ptr)
    {
        std::cerr << "[Brush] Shape type not identified\n";
        return;
    }

    m_shape_ptr->setFillColor(m_brush_color);
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
    
    m_brush_size = size;
    applySizeToShape();
    centerBrushOrigin();
}

void Brush::setColor(const sf::Color& col)
{
    m_brush_color = col;

    if (!m_shape_ptr)
    {
        std::cerr << "[Brush] Attempted to setColor on null\n";
        return;
    }

    m_shape_ptr->setFillColor(m_brush_color);
}

const sf::Shape* Brush::getShape() const
{
    if (!m_shape_ptr)
    {
        std::cerr << "[Brush] Returning a null Brush Shape ptr!\n";
        return nullptr;
    }

    return m_shape_ptr.get();
}

Brush::ShapeType Brush::getShapeType() const
{
    return m_shape_type;
}

void Brush::centerBrushOrigin()
{
    if (!m_shape_ptr) 
    {
        std::cerr << "[Brush] Centering an invalid shape!\n";
        return;
    }   
    const float origin_cords = m_brush_size / 2.0f;
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
            ->setRadius(m_brush_size / 2);  
        break;

    case Brush::ShapeType::Rectangle:
        static_cast<sf::RectangleShape*>(m_shape_ptr.get())
            ->setSize({m_brush_size, m_brush_size});
        break;

    default:
        break;
    }
}