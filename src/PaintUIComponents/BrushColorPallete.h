#include "ColorPalleteButton.h"
#include "BrushLogic.h"
#include "EntityTypes.h"
#include "TextLabel.h"
#include "UIEntityContainerComponent.h"
#include "UIConfig.h"

#include <SFML/Graphics.hpp>

class BrushColorPallete : public UIEntity
{
public:
    BrushColorPallete( 
        BrushLogic* brush_logic_ptr
    );

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
    const sf::Vector2f LABEL_BOX_SIZE {240, 37};
    UI::UIEntityContainerComponent m_color_btns;
    const std::string LABEL { "Brush Colors"};
    UI::TextLabel m_label {
        UIConfig::LABEL_FONT,
        LABEL,
        UIConfig::LABEL_FONT_SIZE,
        LABEL_BOX_SIZE
    };

    BrushLogic* m_brush_logic_ptr;

    /////////////////////////////////////////////////////////////
    // Color Pallete Element Configs
    /////////////////////////////////////////////////////////////
    const int BOXES_PER_ROW = 6;
    const sf::Color BOX_COLOR_OUTLINE_HOVER { sf::Color::Black };
    const sf::Vector2f BOX_COLOR_SIZE { 40.0f, 40.0f };
    const std::vector<sf::Color> m_colors_for_pallete {
        sf::Color(0xFFFFFFFF),
        sf::Color(0xC3C3C3FF),
        sf::Color(0x585858FF),
        sf::Color(0x000000FF),
        sf::Color(0x88001BFF),
        sf::Color(0xec1c24FF),
        sf::Color(0xff7f27FF),
        sf::Color(0xffca18FF),
        sf::Color(0xfdeca6FF),
        sf::Color(0xfff200FF),
        sf::Color(0xc4ff0eFF),
        sf::Color(0x0ed145FF),
        sf::Color(0x8cfffbFF),
        sf::Color(0x00a8f3FF),
        sf::Color(0x3f48ccFF),
        sf::Color(0xb83dbaFF),
        sf::Color(0xffaec8FF),
        sf::Color(0xb97a56FF),
    };

    void configureLabel();
    void loadBtns();
    void positionBtns(const sf::Vector2f& top_left_pos);
};
