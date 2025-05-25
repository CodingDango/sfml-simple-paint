#include "TextLabel.h"

/////////////////////////////////////////////////////////////
// Constructers
/////////////////////////////////////////////////////////////
ui::TextLabel::TextLabel(
    const std::string& string,
    const sf::Color& text_col,
    sf::Uint8 text_size,
    const sf::Font& font,
    Alignment text_alignment,
    const sf::Color& box_col,
    const sf::Vector2f& box_dimensions
)
:   m_string    { string },
    m_text_col  { text_col },
    m_text_size { text_size },
    m_font      { font },
    m_text      { m_string, m_font, m_text_size }, 
    m_alignment { text_alignment },
    m_box_col   { box_col },
    m_box_dimensions    { box_dimensions }
{}
    
/////////////////////////////////////////////////////////////
// Setters
/////////////////////////////////////////////////////////////
void ui::TextLabel::setText(const std::string& str)
{

}

void ui::TextLabel::setTextColor(const sf::Color& col)
{

}

void ui::TextLabel::setTextSize(sf::Uint8 size)
{

}

void ui::TextLabel::setTextAlignment(Alignment alignment)
{

}

void ui::TextLabel::setBoxColor(const sf::Color& col)
{

}

void ui::TextLabel::setBoxDimensions(const sf::Vector2f& dimensions)
{

}

/////////////////////////////////////////////////////////////
// Getters
/////////////////////////////////////////////////////////////
std::string ui::TextLabel::getTextCopy() const
{
    return m_string;
}

sf::Color ui::TextLabel::getTextColor() const
{
    return m_text_col;
}  

sf::Uint8 ui::TextLabel::getTextSize() const
{
    return m_text_size;
}

ui::TextLabel::Alignment ui::TextLabel::getTextAlignment() const
{
    return m_alignment;
}

sf::Color ui::TextLabel::getBoxColor() const
{
    return m_box_col;
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void ui::TextLabel::handleEvent(const sf::Event& event)
{

}

void ui::TextLabel::update(float dt, const sf::Vector2f& mouse_pos)
{

}

void ui::TextLabel::render(sf::RenderTarget& dest)
{
    dest.draw(m_box);
    dest.draw(m_text);
}

/////////////////////////////////////////////////////////////
// UIEntity Overrides
/////////////////////////////////////////////////////////////
void ui::TextLabel::setPosition(const sf::Vector2f& pos)
{
    m_box.setPosition(pos);

    const sf::FloatRect text_bounds = m_text.getGlobalBounds();

    m_text.setOrigin(
        text_bounds.left + (text_bounds.width / 2.0f),
        text_bounds.top + (text_bounds.height / 2.0f)
    );

    m_text.setPosition(
        m_box.getPosition().x + (m_box_dimensions.x / 2.0f),
        m_box.getPosition().y + (m_box_dimensions.y / 2.0f)
    );
}

void ui::TextLabel::setPosition(float x, float y)
{
    m_box.setPosition({x, y});
}

sf::Vector2f ui::TextLabel::getSize() const
{
    return m_box_dimensions;
}

        // -- Text
        // // -- Text
        // std::string m_string;
        // sf::Color m_text_col;
        // sf::Uint8 m_text_size;
        // sf::Font m_font;
        // sf::Text m_text;
        // Alignment m_alignment;
        
        // // -- Box
        // sf::Color m_box_col;
        // sf::Vector2f m_box_dimensions;
        // sf::RectangleShape m_box;
