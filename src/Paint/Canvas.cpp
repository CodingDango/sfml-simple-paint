#include "Canvas.h"

Paint::Canvas::Canvas(            
    BrushLogic* brush_logic_ptr,
    const sf::Vector2f& canvas_pos,
    const sf::Vector2u& canvas_size,
    const sf::Color& canvas_col
)
:   m_brush_logic_ptr { brush_logic_ptr },
    m_canvas_pos      { canvas_pos },
    m_canvas_size     { canvas_size },
    m_canvas_col      { canvas_col }
{
    configRenderObjects();
}

void Paint::Canvas::configRenderObjects()
{   
    m_render_texture.create(m_canvas_size.x, m_canvas_size.y);
    m_render_texture.clear(m_canvas_col);

    m_sprite.setTexture(m_render_texture.getTexture());
    m_sprite.setPosition(m_canvas_pos);
}

void Paint::Canvas::applySmoothBrushStrokes()
{
    const sf::Vector2f unmapped_curr_brush_pos = m_brush_logic_ptr->getPosition(); 
    const sf::Vector2f journey_vector =  unmapped_curr_brush_pos - m_unmapped_last_brush_pos;
    const float journey_length = utils::vectLength(journey_vector);
    sf::Vector2f journey_direction;

    if (journey_length > 0)
        journey_direction = journey_vector / journey_length;

    const float step_size = (m_brush_logic_ptr->getBounds().width / 3.0f);

    for (double i = 0; i < journey_length; i += step_size)
    {
        const sf::Vector2f dab_pos = m_unmapped_last_brush_pos + utils::multVectByFactor(journey_direction, i);
        applyBrushDab(dab_pos);
    }

    applyBrushDab(unmapped_curr_brush_pos);

    m_unmapped_last_brush_pos = unmapped_curr_brush_pos;
}

void Paint::Canvas::applyBrushDab(const sf::Vector2f& unmapped_brush_pos)
{   
    const sf::Vector2f mapped_current_new_brush_pos = unmapped_brush_pos - m_canvas_pos;

    m_brush_logic_ptr->setPosition(mapped_current_new_brush_pos);
    m_render_texture.draw(m_brush_logic_ptr->getShape());
    m_brush_logic_ptr->setPosition(unmapped_brush_pos);
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void Paint::Canvas::update(float dt, const sf::Vector2f& mouse_pos)
{
    m_is_hovered = m_sprite.getGlobalBounds().contains(mouse_pos);

    // Check for enter
    if (!m_was_hovered && m_is_hovered)
        m_unmapped_last_brush_pos = mouse_pos;

    // Checks for just pressed

    if (m_is_hovered && m_is_pressed && !m_was_pressed)
        m_is_painting = true;

    if (!m_is_pressed)
        m_is_painting = false;

    m_was_pressed = m_is_pressed;
    m_was_hovered = m_is_hovered;
}

void Paint::Canvas::render(sf::RenderTarget& dest) 
{
    if (m_is_painting)
        applySmoothBrushStrokes();

    m_render_texture.display();
    dest.draw(m_sprite);    
}

void Paint::Canvas::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if (event.key.control && event.key.code == sf::Keyboard::C)
            m_render_texture.clear(m_canvas_col);
        break;

    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            m_is_pressed = true;
            m_unmapped_last_brush_pos = m_brush_logic_ptr->getPosition();
         }

        break;

    case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left)
            m_is_pressed = false;
        break;

    default:
        break;
    }
}
