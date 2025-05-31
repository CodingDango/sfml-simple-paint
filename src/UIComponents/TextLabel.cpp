#include "TextLabel.h"

/////////////////////////////////////////////////////////////
// Constructers
/////////////////////////////////////////////////////////////
UI::TextLabel::TextLabel(
    const sf::Font& font_ref,
    const std::string& string,
    unsigned int char_size,
    const sf::Vector2f& box_size
    // const sf::Color& text_col,
    // Alignment text_alignment = Center,
    // const sf::Color& box_col = sf::Color::Transparent,
    // const sf::Vector2f& box_dimensions = sf::Vector2f(0, 0)
)
:   m_font_ref          { font_ref },
    m_string_content    { string },
    m_character_size    { char_size },
    m_text_object       { string, font_ref, char_size }
{
    // Box cant be smaller than the text itself.
    updateBoxSize(box_size);
    m_box_shape.setFillColor(m_box_color);
}

/////////////////////////////////////////////////////////////
// Setters
/////////////////////////////////////////////////////////////
void UI::TextLabel::setString(const std::string& str)
{
    m_text_object.setString(str);
}   

void UI::TextLabel::setTextColor(const sf::Color& col)
{
    m_text_object.setFillColor(col);
}

void UI::TextLabel::setCharSize(unsigned int size)
{
    m_text_object.setCharacterSize(size);

}

void UI::TextLabel::setTextAlignment(Alignment alignment)
{
    m_text_alignment = alignment;
    alignTextInBox();
}

void UI::TextLabel::setBoxColor(const sf::Color& col)
{
    m_box_shape.setFillColor(col);
    m_box_color = col;
}

void UI::TextLabel::setBoxDimensions(const sf::Vector2f& dimensions)
{
    updateBoxSize(dimensions);
}

void UI::TextLabel::setTextStyle(sf::Text::Style style)
{
    m_text_object.setStyle(style);
}

/////////////////////////////////////////////////////////////
// Getters
/////////////////////////////////////////////////////////////
std::string UI::TextLabel::getTextCopy() const
{
    return m_string_content;
}

sf::Color UI::TextLabel::getTextColor() const
{
    return m_text_color;
}  

unsigned int UI::TextLabel::getCharSize() const
{
    return m_character_size;
}

UI::TextLabel::Alignment UI::TextLabel::getTextAlignment() const
{
    return m_text_alignment;
}

sf::Color UI::TextLabel::getBoxColor() const
{
    return m_box_color;
}

const sf::Text& UI::TextLabel::getActualText() const
{
    return m_text_object; 
}

sf::FloatRect UI::TextLabel::getBoxBounds() const
{
    return m_box_shape.getGlobalBounds();
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void UI::TextLabel::handleEvent(const sf::Event& event)
{

}

void UI::TextLabel::update(float dt, const sf::Vector2f& mouse_pos)
{

}

void UI::TextLabel::render(sf::RenderTarget& dest)
{
    dest.draw(m_box_shape);
    dest.draw(m_text_object);
}

/////////////////////////////////////////////////////////////
// UIEntity Overrides
/////////////////////////////////////////////////////////////
void UI::TextLabel::setPosition(const sf::Vector2f& pos)
{
    setPosition(pos.x, pos.y);
}

void UI::TextLabel::setPosition(float x, float y)
{
    if (utils::isVectNotZero(m_box_shape.getSize()))
    {
        m_box_shape.setPosition(x, y);
        alignTextInBox();   
    }
    else
    {
        m_text_object.setPosition(x, y);
    }
}

sf::Vector2f UI::TextLabel::getSize() const
{
    return m_box_shape.getSize();
}

/////////////////////////////////////////////////////////////
// Helpers
/////////////////////////////////////////////////////////////
void UI::TextLabel::alignTextInBox()
{
    const sf::FloatRect text_bounds = m_text_object.getLocalBounds();

    // This is for the origin
    // For now alignment only affects the X
    // That is why top distance is always at center
    float left_distance {};
    float top_distance  { text_bounds.height / 2.0f };

    switch (m_text_alignment)
    {
    case UI::TextLabel::Alignment::Left:
        left_distance = 0;
        break;
    
    case UI::TextLabel::Alignment::Center:
        left_distance = text_bounds.width / 2.0f;
        break; 
    
    case UI::TextLabel::Alignment::Right:
        left_distance = text_bounds.width;
        break;
    
    default:
        break;
    }

    m_text_object.setOrigin(
        text_bounds.left + left_distance, 
        text_bounds.top + top_distance
    );
         
    m_text_object.setPosition(
        m_box_shape.getPosition().x + (m_box_shape.getSize().x / 2.0f),
        m_box_shape.getPosition().y + (m_box_shape.getSize().y / 2.0f)
    );
}

void UI::TextLabel::updateBoxSize(const sf::Vector2f& new_size)
{
    // Box cant be smaller than the text itself
    sf::Vector2f box_size {};
    box_size.x = std::max(new_size.x, m_text_object.getGlobalBounds().width);
    box_size.y = std::max(new_size.y, m_text_object.getGlobalBounds().height);
    m_box_shape.setSize(box_size);
}
