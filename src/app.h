#ifndef APP_H
#define APP_H

#include "Brush.h"
#include "Button.h"
#include "BrushLogic.h"
#include "BrushLogicUI.h"
#include "Canvas.h"
#include "EntityTypes.h"
#include "Utils.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class App
{
public:
    App();
    void run();

private:
    /////////////////////////////////////////////////////////////
    // Attribute Definitions
    /////////////////////////////////////////////////////////////

    // -- Window Setup --
    inline static const std::string WINDOW_TITLE {"SimplePaint"};
    inline static const int WINDOW_WIDTH_PX   = 1280;
    inline static const int WINDOW_HEIGHT_PX  = 720;
    inline static const int MAX_FPS = 120;
    inline static const sf::Color WINDOW_BG_COLOR {0x222831FF};

    sf::RenderWindow m_window;

    // -- System Setup --
    sf::Clock m_clock;
    std::vector<std::unique_ptr<Entity>> m_entities;
    
    // -- Canvas Config --
    inline static const sf::Vector2u CANVAS_SIZE {900, 625};
    inline static const sf::Vector2f CANVAS_POS  {47, 47}; 
    inline static const sf::Color CANVAS_BG_COL  {sf::Color::White};

    // -- Brush Config --
    inline static const Brush::ShapeType BRUSH_STARTING_SHAPE = Brush::ShapeType::Circle;
    inline static const sf::Color BRUSH_STARTING_COL {sf::Color::Black};
    inline static const float BRUSH_STARTING_SIZE = 20.0f;
    
    // -- BrushLogicUI Config --
    inline static const sf::Vector2f BRUSH_UI_STARTING_POS {1003.0f, 0.0f};
    inline static const sf::Vector2f BRUSH_UI_SIZE {277.0f, WINDOW_HEIGHT_PX};
    inline static const sf::Color BRUSH_UI_BG_COL {0x393E46FF};

    /////////////////////////////////////////////////////////////
    // Private Method Declarations  
    /////////////////////////////////////////////////////////////
    void processEvents();
    void updateEntities();
    void drawEntities();
    void initializeEntities();
};   

#endif