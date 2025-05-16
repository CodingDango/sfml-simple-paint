#include "Button.h"

/////////////////////////////////////////////////////////////
//  Button Constructers
/////////////////////////////////////////////////////////////

ui::Button::Button(const sf::Color& fill_color, const sf::Vector2f& btn_size)
:    
    m_rect_shape { btn_size },
    m_fill_color { fill_color }
{
    m_rect_shape.setOrigin(btn_size.x / 2, btn_size.y / 2);
    m_rect_shape.setFillColor(m_fill_color);

    // Default Button Callbacks
    m_hover_callback    = [this](){ m_rect_shape.setScale(m_hover_scale_factor, m_hover_scale_factor); };
    m_no_hover_callback = [this](){ m_rect_shape.setScale(m_normal_scale_factor, m_normal_scale_factor); };
    m_click_callback    = [](){ std::cout << "Hello\n"; };   
}

/////////////////////////////////////////////////////////////
//  Button Update Methods
/////////////////////////////////////////////////////////////

void ui::Button::checkHover(const sf::Event& event)
{   
    if (event.type != sf::Event::MouseMoved)
        return;

    std::cout << m_rect_shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseButton.y) << '\n';
    if (m_rect_shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
    {
        // m_rect_shape.setScale(m_hover_scale_factor, m_hover_scale_factor);   // This line works. itsthe callback
        m_hover_callback();
    }
    else
    {   
        // m_rect_shape.setScale(m_normal_scale_factor, m_normal_scale_factor); // This line works. the callbacks dont?
        m_no_hover_callback();
    }

}

void ui::Button::checkClick(const sf::Event& event)
{   
    if (event.type != sf::Event::MouseButtonPressed)
        return;
        
    if (m_rect_shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)
        && event.mouseButton.button == sf::Mouse::Button::Left)
        m_click_callback();   // Weirdly this one works fine. so its a problem with this reference?
}

/////////////////////////////////////////////////////////////
//  Button Callback Setters
/////////////////////////////////////////////////////////////

void ui::Button::setClickCallback(const std::function<void()>& callback)
{
    m_click_callback = callback;
}

void ui::Button::setHoverCallback(const std::function<void()>& callback)
{
    m_hover_callback = callback;
}

void ui::Button::setNoHoverCallback(const std::function<void()>& callback)
{
    m_no_hover_callback = callback;
}

/////////////////////////////////////////////////////////////
//  Button Transform Setters
/////////////////////////////////////////////////////////////

void ui::Button::setPosition(const sf::Vector2f& pos)
{
    m_rect_shape.setPosition(pos);
}

void ui::Button::setPosition(float x, float y)
{
    m_rect_shape.setPosition(x, y);
}

/////////////////////////////////////////////////////////////
//  Button Drawable Related Getters 
/////////////////////////////////////////////////////////////

sf::Color ui::Button::getFillColor() const 
{
    return m_fill_color;
}

const sf::RectangleShape& ui::Button::getDrawableRect() const
{
    return m_rect_shape;
}

/////////////////////////////////////////////////////////////
// BtnInitData Constructer
/////////////////////////////////////////////////////////////

ui::BtnInitData::BtnInitData(const sf::Color& color, const sf::Vector2f& btn_size)
:   m_color { color },
    m_btn_size { btn_size }
{}