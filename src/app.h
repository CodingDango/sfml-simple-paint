#ifndef APP_H
#define APP_H

#include "utils.h"
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
    inline static const int M_MAX_FPS = 60;

    // -- Window Setup --
    sf::RenderWindow m_window {
        sf::VideoMode { M_WINDOW_WIDTH_PX, M_WINDOW_HEIGHT_PX },
        M_WINDOW_TITLE
    };

    // -- System Setup --
    sf::Clock m_clock {};

    // -- Canvas Config --
    inline static const sf::Vector2u M_CANVAS_SIZE { 
        M_WINDOW_WIDTH_PX, M_WINDOW_HEIGHT_PX 
    };

    // -- Canvas Setup --
    sf::RenderTexture m_canvas_texture {};

    // not initializing sprite with canvas texture yet
    // m_canvas_texture is in an invalid state before calling create()
    sf::Sprite m_canvas_sprite {};  

    // -- Brush Config --
    inline static const float M_BRUSH_SIZE_PX = 20.0f; 
    inline static const sf::Color M_BRUSH_COLOR = sf::Color::Red;
    inline static const sf::Color M_BRUSH_COLOR_INACTIVE = utils::modifyOpacity(M_BRUSH_COLOR, 0); 
    
    // -- Brush State --
    bool m_is_brush_painting = false;
    sf::Vector2f m_last_mouse_pos {};

    // -- Brush Setup --
    sf::CircleShape m_brush { M_BRUSH_SIZE_PX };

    /////////////////////////////////////////////////////////////
    // Private Method Declarations
    /////////////////////////////////////////////////////////////

    void processEvents();
    void updateEntities();
    void drawEntities();
};   

#endif