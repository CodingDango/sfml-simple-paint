
#include "BrushSizeIncrement.h"

BrushSizeIncrement::BrushSizeIncrement(BrushLogic* brush_logic_ptr)
:   m_brush_logic_ptr {brush_logic_ptr}
{
    configureUIElements();
}

/////////////////////////////////////////////////////////////
// Entity Overrides
/////////////////////////////////////////////////////////////
void BrushSizeIncrement::handleEvent(const sf::Event& event)
{
    m_ui_elements.handleUIEntitiesEvents(event);
} 

void BrushSizeIncrement::update(float dt, const sf::Vector2f& mouse_pos)
{
    m_ui_elements.updateUIEntities(dt, mouse_pos);
} 

void BrushSizeIncrement::render(sf::RenderTarget& dest)
{
    m_ui_elements.renderUIEntities(dest);
} 


/////////////////////////////////////////////////////////////
// UI Entity Overrides
/////////////////////////////////////////////////////////////
void BrushSizeIncrement::setPosition(const sf::Vector2f& pos)
{
    positionUIElements(pos);
}

/////////////////////////////////////////////////////////////
// Helpers
/////////////////////////////////////////////////////////////
void BrushSizeIncrement::configureUIElements()
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

    // Input label
    std::unique_ptr<UI::TextLabel> input_text_ptr {
        std::make_unique<UI::TextLabel>(
            UIConfig::LABEL_FONT,
            "",
            UIConfig::LABEL_FONT_SIZE,
            INPUT_TEXT_SIZE      
        )
    };

    input_text_ptr->setBoxColor(INPUT_TEXT_BG_COL);
    m_ui_elements.addChild(std::move(input_text_ptr));

    // Decrement Button
    std::unique_ptr<UI::Button> decrement_btn_ptr {
        std::make_unique<UI::Button>(
            DECREMENT_BTN_BG_COL,
            BTN_SIZE
        )
    };

    m_ui_elements.addChild(std::move(decrement_btn_ptr));

    // Increment Button
    std::unique_ptr<UI::Button> increment_btn_ptr {
        std::make_unique<UI::Button>(
            INCREMENT_BTN_BG_COL,
            BTN_SIZE
        )
    };

    m_ui_elements.addChild(std::move(increment_btn_ptr));
}

void BrushSizeIncrement::positionUIElements(const sf::Vector2f& pos)
{
    static constexpr int HEADER_LABEL_IDX   = 0;
    static constexpr int INPUT_TEXT_IDX     = 1;
    static constexpr int DECREMENT_BTN_IDX  = 2;
    static constexpr int INCREMENT_BTN_IDX  = 3;

    // Position Header Label
    m_ui_elements[HEADER_LABEL_IDX]->setPosition(pos);

    // Position Input Text, below the heade rlabel
    m_ui_elements[INPUT_TEXT_IDX]->setPosition(pos.x, pos.y + HEADER_LABEL_SIZE.y);

    // Position Decrement button below the input text
    const float BTN_Y = pos.y + HEADER_LABEL_SIZE.y + INPUT_TEXT_SIZE.y;
    m_ui_elements[DECREMENT_BTN_IDX]->setPosition(pos.x, BTN_Y);
    m_ui_elements[INCREMENT_BTN_IDX]->setPosition(pos.x + BTN_SIZE.x, BTN_Y);
}