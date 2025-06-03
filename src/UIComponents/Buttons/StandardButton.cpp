#include "StandardButton.h"

UI::StandardButton::StandardButton(
    const sf::Color& col, 
    const sf::Vector2f& size
)
:   m_rectangle {size}
{
    m_rectangle.setFillColor(col);
}

void UI::StandardButton::setIconTexture(const sf::Texture& text)
{
    m_icon_sprite.setTexture(text, true);
    centerIconInRectangle();
}

void UI::StandardButton::setSize(const sf::Vector2f& size)
{
    m_rectangle.setSize(size);
}

void UI::StandardButton::setOutlineColor(const sf::Color& col)
{
    m_rectangle.setOutlineColor(col);
}

void UI::StandardButton::setOutlineThickness(float thickness)
{
    m_rectangle.setOutlineThickness(thickness);
}

void UI::StandardButton::setFillColor(const sf::Color& col)
{
    m_rectangle.setFillColor(col);
}

sf::Color UI::StandardButton::getFillColor() const 
{
    return m_rectangle.getFillColor();
}

bool UI::StandardButton::isMouseHovered(const sf::Vector2f& mouse_pos) const
{
    return (m_rectangle.getGlobalBounds().contains(mouse_pos));
}

void UI::StandardButton::centerIconInRectangle()
{
    const sf::Vector2f rectangle_position = m_rectangle.getPosition();
    const sf::FloatRect rectangle_bounds = m_rectangle.getLocalBounds();
    const sf::FloatRect icon_bounds = m_icon_sprite.getLocalBounds();

    m_icon_sprite.setPosition(
        rectangle_position.x + (rectangle_bounds.width / 2.f) - (icon_bounds.width / 2.f),
        rectangle_position.y + (rectangle_bounds.height / 2.f) - (icon_bounds.height / 2.f)
    );
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void UI::StandardButton::handleEvent(const sf::Event& event)
{
    handleMouseEvents(event);
}

void UI::StandardButton::update(float dt, const sf::Vector2f& mouse_pos)
{
    handleMouseCallbacks(mouse_pos);
}

void UI::StandardButton::render(sf::RenderTarget& dest)
{
    dest.draw(m_rectangle);
    dest.draw(m_icon_sprite);
}

/////////////////////////////////////////////////////////////
// UIEntity Overrides
/////////////////////////////////////////////////////////////
void UI::StandardButton::setPosition(const sf::Vector2f& pos)
{
    setPosition(pos.x, pos.y);  // Use the other method instead :0
}

void UI::StandardButton::setPosition(float x, float y)
{
    m_rectangle.setPosition(x, y);
    centerIconInRectangle();
}

sf::Vector2f UI::StandardButton::getSize() const
{
    return m_rectangle.getLocalBounds().getSize();
}