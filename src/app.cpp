#include "app.h"

/////////////////////////////////////////////////////////////
// Constructer Definitions
/////////////////////////////////////////////////////////////

App::App()
{   
    // -- Window Setup
    m_window.setFramerateLimit(M_MAX_FPS);

    // -- Canvas Setup --
    m_canvas_texture.create(M_WINDOW_WIDTH_PX, M_WINDOW_HEIGHT_PX);
    m_canvas_sprite.setTexture(m_canvas_texture.getTexture());

    // -- Brush Setup
    m_brush.setOrigin(m_brush.getRadius(), m_brush.getRadius());
    m_brush.setFillColor(M_BRUSH_COLOR);
}

/////////////////////////////////////////////////////////////
// Public Methods Definition
/////////////////////////////////////////////////////////////

void App::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        updateEntities();
        drawEntities();
    }
}


/////////////////////////////////////////////////////////////
// Private Methods Definition
/////////////////////////////////////////////////////////////

void App::processEvents()
{
    const float delta_time { m_clock.restart().asSeconds() };
    const sf::Vector2f mouse_pos { utils::toVector2f(sf::Mouse::getPosition(m_window)) };

    sf::Event event {};
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;

        case sf::Event::KeyPressed:
            if (event.key.control && event.key.code == sf::Keyboard::C)
                m_canvas_texture.clear();
            break;
        
        case sf::Event::MouseButtonPressed:
            m_is_brush_painting = true;
            break;

        case sf::Event::MouseMoved:
            break;

        case sf::Event::MouseButtonReleased:
            m_is_brush_painting = false;
            break;

        default:
            break;
        }
    }
}

void App::updateEntities()
{   
    const sf::Vector2f mouse_pos { utils::toVector2f(sf::Mouse::getPosition(m_window)) };

    // -- Update Brush
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_brush.setFillColor(M_BRUSH_COLOR);
        m_brush.setPosition(mouse_pos); 
    }
    else  
    {
        m_brush.setFillColor(M_BRUSH_COLOR_INACTIVE);
    }
}

void App::drawEntities()
{      
    m_window.clear();

    // -- Draw Brush And Canvas
    m_canvas_texture.draw(m_brush);
    m_window.draw(m_canvas_sprite);
    
    m_window.display();
    m_canvas_texture.display();
}