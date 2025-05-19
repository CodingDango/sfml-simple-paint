#include "Button.h"

/////////////////////////////////////////////////////////////
//  Button Constructers
/////////////////////////////////////////////////////////////
ui::Button::Button(const sf::Color& fill_color, const sf::Vector2f& btn_size)
:    
    m_shape { btn_size },
    m_fill_color { fill_color }
{
    m_shape.setOrigin(btn_size.x / 2, btn_size.y / 2);
    m_shape.setFillColor(m_fill_color);
    m_shape.setScale(m_normal_scale_factor, m_normal_scale_factor);

    // Default Button Callbacks    
    m_hover_callback    = [this](){ m_shape.setScale(m_hover_scale_factor, m_hover_scale_factor); };
    m_no_hover_callback = [this](){ m_shape.setScale(m_normal_scale_factor, m_normal_scale_factor); };
    m_click_callback    = [](){ std::cout << "Hello\n";  };   
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
    m_shape.setPosition(pos);
}

void ui::Button::setPosition(float x, float y)
{
    m_shape.setPosition(x, y);
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
    return m_shape;
}

/////////////////////////////////////////////////////////////
// BtnInitData Constructer
/////////////////////////////////////////////////////////////
ui::BtnInitData::BtnInitData(const sf::Color& color, const sf::Vector2f& btn_size)
:   m_color { color },
    m_btn_size { btn_size }
{}


/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////        
void ui::Button::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseMoved:
        Entity::is_hovered = m_shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y);
        break;

    case sf::Event::MouseButtonPressed:
        Entity::is_clicked = (m_shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)
        && event.mouseButton.button == sf::Mouse::Button::Left);

    default:
        break;
    }
}

void ui::Button::update(float dt, const sf::Vector2f& mouse_pos)
{
    if (Entity::is_hovered)
        m_hover_callback();
    else
        m_no_hover_callback();

    if (Entity::is_clicked)
        m_click_callback();
}

void ui::Button::render(sf::RenderTarget& dest) const
{
    dest.draw(m_shape);
}
