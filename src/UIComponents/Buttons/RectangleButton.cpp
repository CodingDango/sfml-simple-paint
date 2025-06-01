#include "RectangleButton.h"

UI::RectangleButton::RectangleButton(
    const sf::Color& col, 
    const sf::Vector2f& size
)
:   m_rectangle {size}
{
    m_rectangle.setFillColor(col);
}

void UI::RectangleButton::setSize(const sf::Vector2f& size)
{
    m_rectangle.setSize(size);
}

void UI::RectangleButton::setOutlineColor(const sf::Color& col)
{
    m_rectangle.setOutlineColor(col);
}

void UI::RectangleButton::setOutlineThickness(float thickness)
{
    m_rectangle.setOutlineThickness(thickness);
}

void UI::RectangleButton::setFillColor(const sf::Color& col)
{
    m_rectangle.setFillColor(col);
}

bool UI::RectangleButton::isMouseHovered(const sf::Vector2f& mouse_pos) const
{
    return (m_rectangle.getGlobalBounds().contains(mouse_pos));
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void UI::RectangleButton::handleEvent(const sf::Event& event)
{
    handleMouseEvents(event);
}

void UI::RectangleButton::update(float dt, const sf::Vector2f& mouse_pos)
{
    handleMouseCallbacks(mouse_pos);
}

void UI::RectangleButton::render(sf::RenderTarget& dest)
{
    dest.draw(m_rectangle);
}

/////////////////////////////////////////////////////////////
// UIEntity Overrides
/////////////////////////////////////////////////////////////
void UI::RectangleButton::setPosition(const sf::Vector2f& pos)
{
    m_rectangle.setPosition(pos);
}

void UI::RectangleButton::setPosition(float x, float y)
{
    m_rectangle.setPosition(x, y);
}

sf::Vector2f UI::RectangleButton::getSize() const
{
    return m_rectangle.getSize();
}