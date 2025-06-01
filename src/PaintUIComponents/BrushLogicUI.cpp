#include "BrushLogicUI.h"

UI::BrushLogicUI::BrushLogicUI(
    BrushLogic* brush_logic_ptr, 
    const sf::Vector2f& start_pos,
    const sf::Vector2f& size,
    const sf::Color& bg_col
)
:   m_brush_logic_ptr { brush_logic_ptr }
{
    configBg(start_pos, size, bg_col);
    configPaintUIComponents();
}

void UI::BrushLogicUI::configBg(
    const sf::Vector2f& bg_pos, 
    const sf::Vector2f& bg_size,
    const sf::Color& bg_col
)
{
    m_bg_rect.setSize(bg_size);
    m_bg_rect.setFillColor(bg_col);
    m_bg_rect.setPosition(bg_pos);
}

void UI::BrushLogicUI::configPaintUIComponents()
{
    // Brush color pallete
    std::unique_ptr<BrushColorPallete> brush_color_pallete { 
        std::make_unique<BrushColorPallete>(m_brush_logic_ptr) 
    };

    brush_color_pallete->setPosition(BRUSH_COLOR_PALLETE_POS);
    m_ui_entities.addChild(std::move(brush_color_pallete));

    // BrushShapes  Component
    std::unique_ptr<BrushShapes> brush_shapes {
        std::make_unique<BrushShapes>(m_brush_logic_ptr)
    };

    brush_shapes->setPosition(BRUSH_SHAPES_POS);
    m_ui_entities.addChild(std::move(brush_shapes));
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void UI::BrushLogicUI::handleEvent(const sf::Event& event)
{
    m_ui_entities.handleUIEntitiesEvents(event);
}

void UI::BrushLogicUI::update(float dt, const sf::Vector2f& mouse_pos)
{
    m_ui_entities.updateUIEntities(dt, mouse_pos);
}

void UI::BrushLogicUI::render(sf::RenderTarget& dest) 
{
    dest.draw(m_bg_rect);
    m_ui_entities.renderUIEntities(dest);
}
