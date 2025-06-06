
#include "BrushShapes.h"

BrushShapes::BrushShapes(BrushLogic* brush_logic_ptr)
:   m_brush_logic_ptr {brush_logic_ptr}
{
    configureUIElements();
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void BrushShapes::handleEvent(const sf::Event& event)
{
    m_ui_elements.handleUIEntitiesEvents(event);
} 

void BrushShapes::update(float dt, const sf::Vector2f& mouse_pos)
{
    m_ui_elements.updateUIEntities(dt, mouse_pos);
} 

void BrushShapes::render(sf::RenderTarget& dest)
{
    m_ui_elements.renderUIEntities(dest);
} 


/////////////////////////////////////////////////////////////
// UI Entity Overrides
/////////////////////////////////////////////////////////////
void BrushShapes::setPosition(const sf::Vector2f& pos)
{
    positionUIElements(pos);
}

/////////////////////////////////////////////////////////////
// Helpers
/////////////////////////////////////////////////////////////
void BrushShapes::configureUIElements()
{
    // Header label
    std::unique_ptr<UI::TextLabel> header_text_ptr {
        std::make_unique<UI::TextLabel>(
            UIConfig::LABEL_FONT,
            HEADER_LABEL_STR,
            UIConfig::LABEL_FONT_SIZE,
            HEADER_LABEL_SIZE      
        )
    };

    header_text_ptr->setTextAlignment(
        UI::TextLabel::AlignmentX::CenterX,
        UI::TextLabel::AlignmentY::TopY
    );

    header_text_ptr->setTextStyle(UIConfig::LABEL_TEXT_STYLE);
    m_ui_elements.addChild(std::move(header_text_ptr));

    // The Rectangular Buttons
    for (int i = 0; i < TOTAL_BTNS; i++)
    {
        std::unique_ptr<UI::StandardButton> button { 
            std::make_unique<UI::StandardButton>(BTN_BG_COL, BTN_SIZE)
        };

        button->setIconTexture(BTN_ICONS_TEXTURES[i]);

        const auto button_ptr = button.get();
        int button_idx = i;

        button->setHoverCallback([this, button_ptr, button_idx](){
            if (button_ptr != m_selected_btn_ptr)
                button_ptr->setFillColor(BTN_BG_COL_HOVER);
        });

        button->setNoHoverCallback([this, button_ptr, button_idx](){
            if (button_ptr != m_selected_btn_ptr)
                button_ptr->setFillColor(BTN_BG_COL);
        });

        button->setClickCallback([this, button_ptr, button_idx](){
            bool was_eraser_active_before_this_click = m_is_current_shape_eraser;
            bool is_clicked_button_eraser = (button_idx == ERASER_BTN_IDX);

            m_is_current_shape_eraser = is_clicked_button_eraser;

            if (m_is_current_shape_eraser && !was_eraser_active_before_this_click)
            {
                m_previous_brush_col = m_brush_logic_ptr->getFillColor();
                m_brush_logic_ptr->setColor(sf::Color::White);
            }

            else if (!m_is_current_shape_eraser && was_eraser_active_before_this_click)
                m_brush_logic_ptr->setColor(m_previous_brush_col);
            
            if (m_selected_btn_ptr != nullptr)
                {
                    const auto previous_btn_ptr = m_selected_btn_ptr;
                    m_selected_btn_ptr = button_ptr;
                    previous_btn_ptr->callNoHoverCallback();
                }

                button_ptr->setFillColor(BTN_BG_COL_SELECTED);
                m_brush_logic_ptr->setShape(BTN_SHAPE_TYPE_FOR_BURSH[button_idx]); 
                m_selected_btn_ptr = button_ptr;
        });

        if (button_idx == CIRCLE_BTN_IDX)
            button_ptr->callClickCallback();
        
        m_ui_elements.addChild(std::move(button));
    }
}

void BrushShapes::positionUIElements(sf::Vector2f pos)
{
    static constexpr int HEADER_LABEL_IDX   = 0;
    static constexpr int BUTTONS_IDX_START = 1;
    const int BUTTONS_IDX_END = m_ui_elements.getChildCount(); 
    
    // Position Header Label
    m_ui_elements[HEADER_LABEL_IDX]->setPosition(pos);

    // The rest are just buttons
    pos.y += m_ui_elements[HEADER_LABEL_IDX]->getSize().y;

    for (int i = BUTTONS_IDX_START; i < BUTTONS_IDX_END; i++)
    {   
        m_ui_elements[i]->setPosition(pos); 
        pos.x += BTN_SIZE.x;
    }
}