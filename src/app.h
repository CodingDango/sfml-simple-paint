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

    // -- Window Config --
    inline static const std::string M_WINDOW_TITLE { "SimplePaint" };
    inline static const int M_WINDOW_WIDTH_PX   = 1280;
    inline static const int M_WINDOW_HEIGHT_PX  = 720;
    inline static const int M_MAX_FPS = 120;

    // -- Window Setup --
    sf::RenderWindow m_window {
        sf::VideoMode { M_WINDOW_WIDTH_PX, M_WINDOW_HEIGHT_PX },
        M_WINDOW_TITLE
    };

    // -- System Setup --
    sf::Clock m_clock {};

    // -- Paint Setup --

    // Canvas Config 
    inline static const sf::Vector2u M_CANVAS_SIZE { 
        800, M_WINDOW_HEIGHT_PX 
    };

    // Canvas Setup 
    sf::RenderTexture m_canvas_texture {};

    // not initializing sprite with canvas texture yet
    // m_canvas_texture is in an invalid state before calling create()
    sf::Sprite m_canvas_sprite {};  

    // Brush Config
    inline static const sf::Vector2f M_BRUSH_INACTIVE_POS {-1000.0f, -1000.0f}; // When the user stops painting, outof obunds
    inline static const float M_BRUSH_SIZE_PX = 20.0f; 
    inline static const sf::Color M_STARTING_BRUSH_COLOR = sf::Color::Red;
    
    // Brush State
    bool m_is_brush_painting = false;
    sf::Vector2f m_last_mouse_pos {};

    // Brush Setup
    sf::CircleShape m_brush { M_BRUSH_SIZE_PX };

    // Toolbar Config
    Toolbar m_toolbar { m_brush };
    ui::ToolbarUI m_toolbar_ui { m_toolbar, { 1000, 200} };

    // Button Setup

    /////////////////////////////////////////////////////////////
    // Private Method Declarations  
    /////////////////////////////////////////////////////////////

    void processEvents();
    void updateEntities();
    void drawEntities();
};   

#endif