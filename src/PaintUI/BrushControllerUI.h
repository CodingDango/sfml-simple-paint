#ifndef BRUSH_CONTROLLER_UI_H
#define BRUSH_CONTROLLER_UI_H

#include "Button.h"
#include "BrushController.h"
#include "Debug.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace ui
{
    class BrushControllerUI : public Entity
    {
    public:
        BrushControllerUI(BrushController* toolbar_ptr, const sf::Vector2f& start_pos);
        
        /////////////////////////////////////////////////////////////
        // Entity Overrides
        /////////////////////////////////////////////////////////////
        void handleEvent(const sf::Event& event) override;
        void update(float dt, const sf::Vector2f& mouse_pos) override;
        void render(sf::RenderTarget& dest) override;
        
    private:
        const sf::Vector2f m_btn_size_px { 75.0f, 75.0f };
        const std::vector<ui::BtnInitData> m_btn_inits {
            { sf::Color::Red,   m_btn_size_px  },
            { sf::Color::Green, m_btn_size_px  },
            { sf::Color::Blue,  m_btn_size_px  },
        };

        std::vector<std::unique_ptr<ui::Button>> m_btns;
        BrushController* m_brush_controller_ptr;

        void prepareBtns(const sf::Vector2f& start_pos);
        void handleBtnsEvents(const sf::Event& event);
        void updateBtns(float dt, const sf::Vector2f& mouse_pos);
        void renderBtns(sf::RenderTarget& dest);
    };
}

#endif