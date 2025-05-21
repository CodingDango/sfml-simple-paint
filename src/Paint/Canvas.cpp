#include "Canvas.h"

paint::Canvas::Canvas(            
    Brush* brush_ptr, 
    const sf::Vector2f& canvas_pos,
    const sf::Vector2u& canvas_size
)
:   m_brush_ptr     { brush_ptr },
    m_canvas_pos    { canvas_pos },
    m_canvas_size   { canvas_size }
{
    configRenderObjects();
}

void paint::Canvas::configRenderObjects()
{
    m_render_texture.create(m_canvas_size.x, m_canvas_size.y);
    m_sprite.setTexture(m_render_texture.getTexture());
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void paint::Canvas::render(sf::RenderTarget& dest) 
{   
    m_render_texture.draw(*(m_brush_ptr->getShape()));
    dest.draw(m_sprite);    
    m_render_texture.display();
}

void paint::Canvas::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if (event.key.control && event.key.code == sf::Keyboard::C)
            m_render_texture.clear();
        break;
    
    default:
        break;
    }
}
