#ifndef APP_H
#define APP_H

#include "Brush.h"
#include "Button.h"
#include "BrushController.h"
#include "BrushControllerUI.h"
#include "Canvas.h"
#include "Entity.h"
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
    inline static const std::string WINDOW_TITLE { "SimplePaint" };
    inline static const int WINDOW_WIDTH_PX   = 1280;
    inline static const int WINDOW_HEIGHT_PX  = 720;
    inline static const int MAX_FPS = 120;

    sf::RenderWindow m_window;

    // -- System Setup --
    sf::Clock m_clock;
    std::vector<std::unique_ptr<Entity>> m_entities;

    // -- Canvas Config --
    inline static const sf::Vector2u CANVAS_SIZE { 800, WINDOW_HEIGHT_PX };
    inline static const sf::Vector2f CANVAS_POS  { 0, 0 };
        
    // -- Brush Config --
    inline static const Brush::ShapeType BRUSH_STARTING_SHAPE = Brush::ShapeType::Circle;
    inline static const sf::Color BRUSH_STARTING_COL = sf::Color::White;
    inline static const float BRUSH_STARTING_SIZE = 20.0f;
    
    // -- BrushController Config --
    inline static const sf::Vector2f TOOLBAR_STARTING_POS { 1000, 200 };

    /////////////////////////////////////////////////////////////
    // Private Method Declarations  
    /////////////////////////////////////////////////////////////
    void processEvents();
    void updateEntities();
    void drawEntities();
    void initializeEntities();
};   

#endif