#include "ToolbarUI.h"


ui::ToolbarUI::ToolbarUI(Toolbar& toolbar, const sf::Vector2f& start_pos)
:   m_toolbar { toolbar }
{
    prepareBtns(start_pos);
}

void ui::ToolbarUI::checkForBtnHover(const sf::Event& event)
{
    for (auto& btn : m_btns) { btn.checkHover(event); }
}

void ui::ToolbarUI::checkForBtnClick(const sf::Event& event)
{ 
    for (auto& btn : m_btns) { btn.checkClick(event); }
}

void ui::ToolbarUI::drawOnWindow(sf::RenderWindow& dest)
{
    for (auto& btn : m_btns) { dest.draw(btn.getDrawableRect()); }
}

void ui::ToolbarUI::prepareBtns(const sf::Vector2f& start_pos)
{
    static const float MARGIN_Y_PX = 15.0f;
    float curr_x = start_pos.x;
    float curr_y = start_pos.y;

    for (size_t i = 0; i < m_btn_inits.size(); i++)
    {   
        const auto& btn_color = m_btn_inits[i].m_color;
        const auto& btn_size  = m_btn_inits[i].m_btn_size; 

        m_btns.emplace_back(btn_color, btn_size);
        m_btns[m_btns.size() - 1].setPosition(curr_x, curr_y);

        curr_y += btn_size.y + MARGIN_Y_PX;
    }
}