#include "ButtonBase.h"

/////////////////////////////////////////////////////////////
//  ButtonBase Callback Setters
/////////////////////////////////////////////////////////////
void UI::ButtonBase::setClickCallback(const std::function<void()>& callback)
{
    m_click_callback = callback;
}

void UI::ButtonBase::setHoverCallback(const std::function<void()>& callback)
{
    m_hover_callback = callback;
}

void UI::ButtonBase::setNoHoverCallback(const std::function<void()>& callback)
{
    m_no_hover_callback = callback;
}


void UI::ButtonBase::handleMouseCallbacks(const sf::Vector2f& mouse_pos)
{   
    bool is_mouse_hovered = isMouseHovered(mouse_pos);  // Virtual :)

    // Check for leave
    if (!is_mouse_hovered && m_was_hovered)
    {
        if (m_no_hover_callback)
            m_no_hover_callback();
    }

    // Check for enter
    else if (is_mouse_hovered && !m_was_hovered)
    {
        if (m_hover_callback)
            m_hover_callback();
    }

    // Check for click
    if (is_mouse_hovered && m_is_mouse_released)
    {
        if (m_click_callback)
            m_click_callback();
    }
    
    m_was_hovered = is_mouse_hovered;
    m_is_mouse_released = false;
}

void UI::ButtonBase::handleMouseEvents(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        m_is_mouse_released = true;
        break;
    
    default:
        break;
    }
}