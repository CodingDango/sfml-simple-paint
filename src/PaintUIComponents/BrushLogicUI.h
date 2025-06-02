#ifndef BRUSH_LOGIC_UI_H
#define BRUSH_LOGIC_UI_H

#include "BrushLogic.h"
#include "EntityTypes.h"

// UI Components
#include "TextLabel.h"
#include "UIEntityContainerComponent.h"

// Paint UI Components
#include "BrushColorPallete.h"
#include "BrushShapes.h"

#include "Debug.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace UI
{
    class BrushLogicUI : public Entity
    {
    public:
        BrushLogicUI(
            BrushLogic* brush_logic_ptr, 
            const sf::Vector2f& start_pos,
            const sf::Vector2f& size,
            const sf::Color& bg_col
        );
        
        /////////////////////////////////////////////////////////////
        // Entity Overrides
        /////////////////////////////////////////////////////////////
        void handleEvent(const sf::Event& event) override;
        void update(float dt, const sf::Vector2f& mouse_pos) override;
        void render(sf::RenderTarget& dest) override;
        
    private:
        /////////////////////////////////////////////////////////////
        // State
        /////////////////////////////////////////////////////////////
        BrushLogic* m_brush_logic_ptr;
        sf::RectangleShape m_bg_rect;   
        UI::UIEntityContainerComponent m_ui_entities;

        /////////////////////////////////////////////////////////////
        // Paint UI Components Positions 
        /////////////////////////////////////////////////////////////
        inline const static sf::Vector2f BRUSH_COLOR_PALLETE_POS { 1021.f, 540.f };
        inline const static sf::Vector2f BRUSH_SHAPES_POS { 1022.f, 16.f };
        
        /////////////////////////////////////////////////////////////
        // Helpers
        /////////////////////////////////////////////////////////////
        void configBg(const sf::Vector2f& bg_pos, const sf::Vector2f& bg_size, const sf::Color& bg_col);
        void configPaintUIComponents();
    };
}

#endif