#include "ToolbarUI.h"


ui::ToolbarUI::ToolbarUI(Toolbar* toolbar_ptr, const sf::Vector2f& start_pos)
:   m_toolbar_ptr { toolbar_ptr }
{
    prepareBtns(start_pos);
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
        const auto& btn_click_callback = [this, btn_color](){ m_toolbar_ptr->setBrushColor(btn_color); };  
    
        m_btns.emplace_back(std::make_unique<ui::Button>(btn_color, btn_size));
        m_btns.back()->setPosition(curr_x, curr_y);
        m_btns.back()->setClickCallback(btn_click_callback);

        curr_y += btn_size.y + MARGIN_Y_PX;
    }
}

void ui::ToolbarUI::handleBtnsEvents(const sf::Event& event)
{
    for (auto& btn_ptr : m_btns) { btn_ptr->handleEvent(event); }
}

void ui::ToolbarUI::updateBtns(float dt, const sf::Vector2f& mouse_pos)
{
    for (auto& btn_ptr : m_btns) { btn_ptr->update(dt, mouse_pos); }
}

void ui::ToolbarUI::renderBtns(sf::RenderTarget& dest)
{
    for (const auto& btn_ptr : m_btns)
    {
        dest.draw(btn_ptr->getDrawableRect());
    }
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void ui::ToolbarUI::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
            handleBtnsEvents(event);
        break;
        
    case sf::Event::MouseMoved:
        handleBtnsEvents(event);
        break;

    default:
        break;
    }
}

void ui::ToolbarUI::update(float dt, const sf::Vector2f& mouse_pos)
{
    updateBtns(dt, mouse_pos);
}

void ui::ToolbarUI::render(sf::RenderTarget& dest) 
{
    renderBtns(dest);
}
