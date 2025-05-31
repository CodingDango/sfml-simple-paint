#include "BrushLogic.h"

/////////////////////////////////////////////////////////////
// Constructer Definitions
/////////////////////////////////////////////////////////////
BrushLogic::BrushLogic(Brush::ShapeType shape_type, sf::Color col, float size)
:   m_brush_ptr { std::make_unique<Brush>(shape_type, col, size) }
{}

/////////////////////////////////////////////////////////////
// Setter Definitions
/////////////////////////////////////////////////////////////
void BrushLogic::setColor(const sf::Color& color)
{
    if (!m_brush_ptr)
        outputBrushIsNull("setColor()");

    m_brush_ptr->setColor(color);
}

void BrushLogic::setSize(float size)
{   
    if (!m_brush_ptr)
        outputBrushIsNull("setSize()");

    m_brush_ptr->setSize(std::clamp(size, MIN_SIZE, MAX_SIZE));
}

void BrushLogic::setShape(Brush::ShapeType type)
{
    if (!m_brush_ptr)
        outputBrushIsNull("setShape()");

    m_brush_ptr->setShapeType(type);
}

void BrushLogic::setPosition(const sf::Vector2f& pos)
{
    if (!m_brush_ptr)
        outputBrushIsNull("setPosition()");

    m_brush_ptr->setPosition(pos);
}

/////////////////////////////////////////////////////////////
// Getters Definitions
/////////////////////////////////////////////////////////////
sf::Vector2f BrushLogic::getPosition() const
{
    return m_brush_ptr->getShape().getPosition();
}

float BrushLogic::getWidth() const
{
    return m_brush_ptr->getShape().getGlobalBounds().width;
}

sf::FloatRect BrushLogic::getBounds() const
{
    if (!m_brush_ptr)
        outputBrushIsNull("getBounds()");

    return m_brush_ptr->getShape().getGlobalBounds();
}

const sf::Shape& BrushLogic::getShape() const
{
    if (!m_brush_ptr)
        outputBrushIsNull("getShape()");

    return m_brush_ptr->getShape();
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void BrushLogic::update(float dt, const sf::Vector2f& mouse_pos)
{
    m_brush_ptr->setPosition(mouse_pos);
}

/////////////////////////////////////////////////////////////
// Debug helpers Definitions
/////////////////////////////////////////////////////////////
void BrushLogic::outputBrushIsNull(std::string_view func_name) const
{
    dbg::outputErr(CLASS_NAME, func_name, "m_brush_ptr is null!");
}