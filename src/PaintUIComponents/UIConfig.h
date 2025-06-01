#ifndef PAINT_UI_COMPONENTS_UI_CONFIG_H
#define PAINT_UI_COMPONENTS_UI_CONFIG_H

#include <SFML/Graphics/Font.hpp>
#include "Utils.h"

namespace UIConfig    
{
    // Font for the PaintUIComponents
    inline const std::string FONT_FILE_PATH { "assets/fonts/Poppins-Regular.ttf" };
    inline const sf::Font LABEL_FONT { utils::loadFontFromFile(FONT_FILE_PATH) };
    
    // Font size for the PaintUIComponents
    inline const unsigned int LABEL_FONT_SIZE = 16.0f;

    // Text style for the PaintUIComponents
    inline const sf::Text::Style LABEL_TEXT_STYLE = sf::Text::Style::Bold; 
}

#endif