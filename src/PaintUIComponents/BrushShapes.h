#ifndef BRUSH_SHAPES_H
#define BRUSH_SHAPES_H

#include "StandardButton.h"
#include "BrushLogic.h"
#include "EntityTypes.h"
#include "TextLabel.h"
#include "UIEntityContainerComponent.h"
#include "UIConfig.h"
#include "utils.h"

#include <SFML/Graphics.hpp>

class BrushShapes : public UIEntity
{
public:
    BrushShapes(BrushLogic* brush_logic_ptr);
        
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
    const int ERASER_BTN_IDX = 0;
    sf::Color m_previous_brush_col = sf::Color::White;
    UI::StandardButton* m_selected_btn_ptr = nullptr;
    
    inline static const std::vector<sf::Texture> BTN_ICONS_TEXTURES {
        utils::loadTextureFromFile("assets/images/shape_icons/eraser.png"),
        utils::loadTextureFromFile("assets/images/shape_icons/circle.png"),
        utils::loadTextureFromFile("assets/images/shape_icons/rectangle.png"),
        utils::loadTextureFromFile("assets/images/shape_icons/triangle.png"),
        utils::loadTextureFromFile("assets/images/shape_icons/star.png"),
    };

    inline static const std::vector<Brush::ShapeType> BTN_SHAPE_TYPE_FOR_BURSH {
        Brush::ShapeType::Rectangle,
        Brush::ShapeType::Circle,
        Brush::ShapeType::Rectangle,
        Brush::ShapeType::Rectangle, // Soon triangle if i can
        Brush::ShapeType::Rectangle, // Soon star if im smart enough lol.
    };

    inline static const std::string HEADER_LABEL_STR {"Brush Shapes"};
    inline static const sf::Vector2f HEADER_LABEL_SIZE {240.f, 37.f};

    inline static const int TOTAL_BTNS = 5;
    inline static const sf::Vector2f BTN_SIZE {48.f, 48.f};
    inline static const sf::Color BTN_BG_COL {0x2D3541FF};
    inline static const sf::Color BTN_BG_COL_HOVER { utils::scaleColor(BTN_BG_COL, 1.2) };
    inline static const sf::Color BTN_BG_COL_SELECTED { 0xFD845FFF };

    void configureUIElements();
    void positionUIElements(sf::Vector2f pos);
};  

#endif