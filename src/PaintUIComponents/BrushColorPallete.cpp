#include "BrushColorPallete.h"

BrushColorPallete::BrushColorPallete(
    BrushLogic* brush_logic_ptr
)
:  m_brush_logic_ptr { brush_logic_ptr }
{
    configureLabel();
    loadBtns();
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void BrushColorPallete::handleEvent(const sf::Event& event)
{
    m_color_btns.handleUIEntitiesEvents(event);
}

void BrushColorPallete::update(float dt, const sf::Vector2f& mouse_pos)
{
    m_color_btns.updateUIEntities(dt, mouse_pos);
}

void BrushColorPallete::render(sf::RenderTarget& dest) 
{
    m_color_btns.renderUIEntities(dest);
    dest.draw(m_label.getActualText());
}

/////////////////////////////////////////////////////////////
// UI Entity Overrides
/////////////////////////////////////////////////////////////
void BrushColorPallete::setPosition(const sf::Vector2f& pos)
{   
    m_label.setPosition(pos);
    positionBtns({pos.x, pos.y + m_label.getBoxBounds().height});
}

/////////////////////////////////////////////////////////////
// Private Methods
/////////////////////////////////////////////////////////////
void BrushColorPallete::configureLabel()
{
    m_label.setTextStyle(UIConfig::LABEL_TEXT_STYLE);
    m_label.setCharSize(UIConfig::LABEL_FONT_SIZE);
}

void BrushColorPallete::loadBtns()
{
    for (size_t i = 0; i < m_colors_for_pallete.size(); i++)
    {   
        const auto& btn_col = m_colors_for_pallete[i];
        std::unique_ptr<UI::Button> btn_ptr_owner = std::make_unique<UI::Button>(btn_col, BOX_COLOR_SIZE);

        const auto btn_ptr = btn_ptr_owner.get();
        const auto& btn_outline_col = BOX_COLOR_OUTLINE_HOVER;

        const auto& btn_click_callback = 
            [this, btn_col](){ m_brush_logic_ptr->setColor(btn_col); };  

        const auto& btn_hover_callback = 
            [this, btn_outline_col, btn_ptr](){ btn_ptr->setOutlineColor(btn_outline_col); };

        const auto& btn_no_hover_callback = 
            [this, btn_ptr](){ btn_ptr->setOutlineColor(sf::Color::Transparent); };

        btn_ptr_owner->setClickCallback(btn_click_callback); 
        btn_ptr_owner->setHoverCallback(btn_hover_callback); 
        btn_ptr_owner->setNoHoverCallback(btn_no_hover_callback);
        btn_ptr_owner->setOutlineThickness(-2.0f);

        m_color_btns.addChild(std::move(btn_ptr_owner));
    }
}

void BrushColorPallete::positionBtns(const sf::Vector2f& top_left_pos)
{
    float curr_x = top_left_pos.x;
    float curr_y = top_left_pos.y;

    for (size_t i = 0; i < m_color_btns.getChildCount(); i++)
    {       
        m_color_btns[i]->setPosition(curr_x, curr_y);

        if ((i + 1) % BOXES_PER_ROW == 0)
        {
            curr_y += BOX_COLOR_SIZE.y;
            curr_x = top_left_pos.x;
        }
        else
            curr_x += BOX_COLOR_SIZE.x;
    }
}