#include "BrushLogicUI.h"

ui::BrushLogicUI::BrushLogicUI(
    BrushLogic* brush_logic_ptr, 
    const sf::Vector2f& start_pos,
    const sf::Vector2f& size,
    const sf::Color& bg_col
)
:   m_brush_logic_ptr { brush_logic_ptr }
{
    configBg(start_pos, size, bg_col);
    prepareBtns(start_pos);
}

void ui::BrushLogicUI::configBg(
    const sf::Vector2f& bg_pos, 
    const sf::Vector2f& bg_size,
    const sf::Color& bg_col
)
{
    m_bg_rect.setSize(bg_size);
    m_bg_rect.setFillColor(bg_col);
    m_bg_rect.setPosition(bg_pos);
}

void ui::BrushLogicUI::prepareBtns(const sf::Vector2f& start_pos)
{   
    static const float MARGIN = 30.0f;

    float start_x = start_pos.x + MARGIN / 2;
    float start_y = start_pos.y + MARGIN / 2;

    float curr_x = start_x;
    float curr_y = start_y;

    for (size_t i = 0; i < m_btn_inits.size(); i++)
    {
        const auto& btn_color = m_btn_inits[i].m_color;
        const auto& btn_size  = m_btn_inits[i].m_size;
        const auto& btn_click_callback = [this, btn_color](){ m_brush_logic_ptr->setColor(btn_color); };  
    
        m_btns.emplace_back(std::make_unique<ui::Button>(btn_color, btn_size));
        
        m_btns.back()->setPosition(curr_x + btn_size.x, curr_y + btn_size.y);
        m_btns.back()->setClickCallback(btn_click_callback); 

        if ((i + 1) % 2 == 0)
        {
            curr_y += btn_size.y + MARGIN;
            curr_x = start_x;
        }
        else
            curr_x += MARGIN + btn_size.x;
    }
}

void ui::BrushLogicUI::handleBtnsEvents(const sf::Event& event)
{
    for (auto& btn_ptr : m_btns) { btn_ptr->handleEvent(event); }
}

void ui::BrushLogicUI::updateBtns(float dt, const sf::Vector2f& mouse_pos)
{
    for (auto& btn_ptr : m_btns) { btn_ptr->update(dt, mouse_pos); }
}

void ui::BrushLogicUI::renderBtns(sf::RenderTarget& dest)
{
    for (const auto& btn_ptr : m_btns)
    {
        dest.draw(btn_ptr->getDrawableRect());
    }
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void ui::BrushLogicUI::handleEvent(const sf::Event& event)
{
    for (auto& btn_ptr : m_btns) { btn_ptr->handleEvent(event); }
}

void ui::BrushLogicUI::update(float dt, const sf::Vector2f& mouse_pos)
{
    updateBtns(dt, mouse_pos);
}

void ui::BrushLogicUI::render(sf::RenderTarget& dest) 
{
    dest.draw(m_bg_rect);
    renderBtns(dest);
}
