#ifndef APP_H
#define APP_H

#include "Brush.h"
#include "Button.h"
#include "Toolbar.h"
#include "ToolbarUI.h"
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

    // -- Canvas Setup --
    inline static const sf::Vector2u CANVAS_SIZE { 
        800, WINDOW_HEIGHT_PX 
    };

    // not initializing sprite with canvas texture yet
    // m_canvas_texture is in an invalid state before calling create()
    sf::RenderTexture m_canvas_texture;
    sf::Sprite m_canvas_sprite;

    // -- Brush Setup --
    inline static const Brush::ShapeType BRUSH_STARTING_SHAPE = Brush::ShapeType::Circle;
    inline static const sf::Color BRUSH_STARTING_COL = sf::Color::White;
    inline static const float BRUSH_STARTING_SIZE = 20.0f;

    Brush m_brush { BRUSH_STARTING_SHAPE, BRUSH_STARTING_COL, BRUSH_STARTING_SIZE };
    
    // -- Toolbar Setup --
    inline static const sf::Vector2f TOOLBAR_STARTING_POS { 1000, 200 };

    Toolbar m_toolbar;
    ui::ToolbarUI m_toolbar_ui;

    /////////////////////////////////////////////////////////////
    // Private Method Declarations  
    /////////////////////////////////////////////////////////////

    void processEvents();
    void updateEntities();
    void drawEntities();
};   

#endif