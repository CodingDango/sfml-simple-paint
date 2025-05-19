#include "app.h"

/////////////////////////////////////////////////////////////
// Constructer Definitions
/////////////////////////////////////////////////////////////

App::App()
:   m_window     { sf::VideoMode { WINDOW_WIDTH_PX, WINDOW_HEIGHT_PX }, WINDOW_TITLE },
    m_brush      { BRUSH_STARTING_SHAPE, BRUSH_STARTING_COL, BRUSH_STARTING_SIZE },
    m_toolbar    { m_brush },
    m_toolbar_ui { m_toolbar, TOOLBAR_STARTING_POS }
{   
    // -- Window Setup
    m_window.setFramerateLimit(MAX_FPS);

    // -- Canvas Setup --
    m_canvas_texture.create(CANVAS_SIZE.x, CANVAS_SIZE.y);
    m_canvas_sprite.setTexture(m_canvas_texture.getTexture());

    // -- Brush Setup
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
    [[maybe_unused]] const float delta_time { m_clock.restart().asSeconds() };
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
            
            else if (event.key.code == sf::Keyboard::F)
            {
                switch (m_brush.getShapeType())
                {
                case Brush::ShapeType::Rectangle:
                    m_brush.setShapeType(Brush::ShapeType::Circle);
                    break;
                
                case Brush::ShapeType::Circle:
                    m_brush.setShapeType(Brush::ShapeType::Rectangle);
                    break;
                
                default:
                    break;
                }
            }

            break;
        
        case sf::Event::MouseMoved:
            m_toolbar_ui.checkForBtnHover(event);
            break;

        case sf::Event::MouseButtonPressed:
            m_toolbar_ui.checkForBtnClick(event);
            break;

        default:
            break;
        }
    }
}

void App::updateEntities()
{   
    const sf::Vector2f mouse_pos { utils::toVector2f(sf::Mouse::getPosition(m_window)) };
    m_brush.update(mouse_pos);
}

void App::drawEntities()
{      
    m_window.clear();
    m_toolbar_ui.drawOnWindow(m_window);
    
    // -- Draw Brush And Canvas
    m_canvas_texture.draw(*m_brush.getShape());
    m_window.draw(m_canvas_sprite);
    
    m_canvas_texture.display();
    m_window.display();
}