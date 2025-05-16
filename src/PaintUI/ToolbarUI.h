#ifndef TOOLBAR_UI_H
#define TOOLBAR_UI_H

#include "Button.h"
#include "Toolbar.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace ui
{
    class ToolbarUI
    {
    public:
        ToolbarUI(Toolbar& toolbar, const sf::Vector2f& start_pos);
        
        void checkForBtnHover(const sf::Event& event);
        void checkForBtnClick(const sf::Event& event);

        void drawOnWindow(sf::RenderWindow& dest);

    private:
        const sf::Vector2f m_btn_size_px { 75.0f, 75.0f };

        const std::vector<ui::BtnInitData> m_btn_inits {
            { sf::Color::Red, m_btn_size_px   },
            { sf::Color::Green, m_btn_size_px },
            { sf::Color::Blue, m_btn_size_px  },
        };

        std::vector<ui::Button> m_btns;
        Toolbar& m_toolbar;

        void prepareBtns(const sf::Vector2f& start_pos);
    };
}

#endif