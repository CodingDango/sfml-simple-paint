#include "Button.h"

/////////////////////////////////////////////////////////////
//  Button Constructers
/////////////////////////////////////////////////////////////
UI::Button::Button(const sf::Color& fill_color, const sf::Vector2f& btn_size)
:    
    m_shape { btn_size },
    m_fill_color { fill_color }
{
    m_shape.setFillColor(m_fill_color);
    m_shape.setScale(m_normal_scale_factor, m_normal_scale_factor);

    // Default Button Callbacks    
    m_hover_callback    = [this](){ m_shape.setScale(m_hover_scale_factor, m_hover_scale_factor); };
    m_no_hover_callback = [this](){ m_shape.setScale(m_normal_scale_factor, m_normal_scale_factor); };
    m_click_callback    = [](){};   
}

/////////////////////////////////////////////////////////////
//  Button Callback Setters
/////////////////////////////////////////////////////////////
void UI::Button::setClickCallback(const std::function<void()>& callback)
{
    m_click_callback = callback;
}

void UI::Button::setHoverCallback(const std::function<void()>& callback)
{
    m_hover_callback = callback;
}

void UI::Button::setNoHoverCallback(const std::function<void()>& callback)
{
    m_no_hover_callback = callback;
}

void UI::Button::setOutlineColor(const sf::Color& col)
{
    m_shape.setOutlineColor(col);
}

void UI::Button::setOutlineThickness(float thickness)
{
    m_shape.setOutlineThickness(thickness);
}

/////////////////////////////////////////////////////////////
//  Button Getters 
/////////////////////////////////////////////////////////////
sf::Color UI::Button::getFillColor() const 
{
    return m_fill_color;
}

const sf::RectangleShape& UI::Button::getDrawableRect() const
{
    return m_shape;
}

/////////////////////////////////////////////////////////////
// Conditional
/////////////////////////////////////////////////////////////
bool UI::Button::isMouseHovered(const sf::Vector2f& mouse_pos) const
{
    return m_shape.getGlobalBounds().contains(mouse_pos);
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////        
void UI::Button::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        UIEntity::is_mouse_released = (event.mouseButton.button == sf::Mouse::Left);
    
    default:
        break;
    }
}

void UI::Button::update(float dt, const sf::Vector2f& mouse_pos)
{   
    bool is_mouse_hovered = isMouseHovered(mouse_pos); 

    if (is_mouse_hovered)
        m_hover_callback();
    else
        m_no_hover_callback();
    
    if (is_mouse_released && is_mouse_hovered)
        m_click_callback();

    is_mouse_released = false;
}

void UI::Button::render(sf::RenderTarget& dest)
{
    dest.draw(m_shape);
}

/////////////////////////////////////////////////////////////
// UIEntity Overrides
/////////////////////////////////////////////////////////////
void UI::Button::setPosition(const sf::Vector2f& pos)
{
    setPosition(pos.x, pos.y);
}

void UI::Button::setPosition(float x, float y)
{
    m_shape.setPosition(x, y);
}

sf::Vector2f UI::Button::getSize() const
{
    return m_shape.getSize();
}