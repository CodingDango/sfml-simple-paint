
#include "Button.h"
#include "BrushLogic.h"
#include "EntityTypes.h"
#include "TextLabel.h"
#include "UIEntityContainerComponent.h"
#include "UIConfig.h"

#include <SFML/Graphics.hpp>

class BrushSizeIncrement : public UIEntity
{
public:
    BrushSizeIncrement(BrushLogic* brush_logic_ptr);
        
    /////////////////////////////////////////////////////////////
    // Entity Overrides
    /////////////////////////////////////////////////////////////
    void handleEvent(const sf::Event& event) override;
    void update(float dt, const sf::Vector2f& mouse_pos) override;
    void render(sf::RenderTarget& dest) override;

    /////////////////////////////////////////////////////////////
    // UI Entity Overrides
    /////////////////////////////////////////////////////////////
    void setPosition(const sf::Vector2f& pos) override;

    
private:
    BrushLogic* m_brush_logic_ptr;
    UI::UIEntityContainerComponent m_ui_elements;

    inline static const std::string HEADER_LABEL_STR {"BRUSH SIZE"};
    inline static const sf::Vector2f HEADER_LABEL_SIZE {111.f, 40.f};

    inline static const sf::Color INPUT_TEXT_BG_COL = sf::Color::White;
    inline static const sf::Vector2f INPUT_TEXT_SIZE {111.f, 40.f};

    inline static const sf::Vector2f BTN_SIZE {55.f, 39.f};
    inline static const sf::Color DECREMENT_BTN_BG_COL {0x3A4452FF};
    inline static const sf::Color INCREMENT_BTN_BG_COL {0x222831FF};

    void configureUIElements();
    void positionUIElements(const sf::Vector2f& pos);
};  