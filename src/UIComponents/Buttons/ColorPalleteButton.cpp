#include "ColorPalleteButton.h"

UI::ColorPalleteButton::ColorPalleteButton(
    const sf::Color& col, 
    const sf::Vector2f& size
)
:   m_rectangle {size},
    m_second_rectangle {size}
{
    m_rectangle.setFillColor(col);
    m_second_rectangle.setFillColor(sf::Color::Transparent);
}

void UI::ColorPalleteButton::setSize(const sf::Vector2f& size)
{
    m_rectangle.setSize(size);
    m_second_rectangle.setSize(size);
}

void UI::ColorPalleteButton::setInnerMostOutlineThickness(float thickness)
{
    m_second_rectangle.setOutlineThickness(thickness);
}

void UI::ColorPalleteButton::setInnerMostOutlineColor(const sf::Color& col)
{
    m_second_rectangle.setOutlineColor(col);
}

void UI::ColorPalleteButton::setOutlineThickness(float thickness)
{
    m_rectangle.setOutlineThickness(thickness);
}

void UI::ColorPalleteButton::setOutlineColor(const sf::Color& col)
{
    m_rectangle.setOutlineColor(col);
}

void UI::ColorPalleteButton::setFillColor(const sf::Color& col)
{
    m_rectangle.setFillColor(col);
}

sf::Color UI::ColorPalleteButton::getFillColor() const
{
    return m_rectangle.getFillColor();
}

bool UI::ColorPalleteButton::isMouseHovered(const sf::Vector2f& mouse_pos) const
{
    return (m_rectangle.getGlobalBounds().contains(mouse_pos));
}


/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void UI::ColorPalleteButton::handleEvent(const sf::Event& event)
{
    handleMouseEvents(event);
}

void UI::ColorPalleteButton::update(float dt, const sf::Vector2f& mouse_pos)
{
    handleMouseCallbacks(mouse_pos);
}

void UI::ColorPalleteButton::render(sf::RenderTarget& dest)
{
    dest.draw(m_rectangle);
    dest.draw(m_second_rectangle);
}

/////////////////////////////////////////////////////////////
// UIEntity Overrides
/////////////////////////////////////////////////////////////
void UI::ColorPalleteButton::setPosition(const sf::Vector2f& pos)
{
    setPosition(pos.x, pos.y);
}

void UI::ColorPalleteButton::setPosition(float x, float y)
{
    m_rectangle.setPosition(x, y);
    m_second_rectangle.setPosition(x, y);
}

sf::Vector2f UI::ColorPalleteButton::getSize() const
{
    return m_rectangle.getSize();
}



