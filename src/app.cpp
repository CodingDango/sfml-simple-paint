#include "app.h"

/////////////////////////////////////////////////////////////
// Constructer Definitions
/////////////////////////////////////////////////////////////

App::App()
:   m_window { sf::VideoMode {WINDOW_WIDTH_PX, WINDOW_HEIGHT_PX}, WINDOW_TITLE }
{
    initializeEntities();   
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
    sf::Event event {};
    
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;

        default:
            for (const auto& entity_ptr : m_entities)
            {
                entity_ptr->handleEvent(event);
            }

            break;
        }
    }
}

void App::updateEntities()
{   
    const float delta_time { m_clock.restart().asSeconds() };
    const sf::Vector2f mouse_pos { m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)) };

    for (const auto& entity_ptr : m_entities)
    {
        entity_ptr->update(delta_time, mouse_pos);
    }
}

void App::drawEntities()
{      
    m_window.clear(WINDOW_BG_COLOR);

    for (const auto& entity_ptr : m_entities)
    {
        entity_ptr->render(m_window);
    }

    m_window.display();
}

void App::initializeEntities()
{   
    // -- Brush Logic
    m_entities.emplace_back(
        std::make_unique<BrushLogic>(BRUSH_STARTING_SHAPE, BRUSH_STARTING_COL, BRUSH_STARTING_SIZE)
    );

    BrushLogic* brush_logic_ptr = static_cast<BrushLogic*>(m_entities.back().get());

    // -- Canvas
    m_entities.emplace_back(
        std::make_unique<paint::Canvas>(brush_logic_ptr, CANVAS_POS, CANVAS_SIZE, CANVAS_BG_COL)
    );

    // -- BrushLogicUI
    m_entities.emplace_back(
        std::make_unique<ui::BrushLogicUI>(
            brush_logic_ptr, 
            BRUSH_UI_STARTING_POS,
            BRUSH_UI_SIZE,
            BRUSH_UI_BG_COL
        )
    );
}