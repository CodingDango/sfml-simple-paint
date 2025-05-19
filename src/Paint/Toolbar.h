#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Brush.h"
#include "Entity.h"

#include <SFML/Graphics.hpp>

class Toolbar : public Entity
{
public:
    /////////////////////////////////////////////////////////////
    // Constructer Declarations
    /////////////////////////////////////////////////////////////
    Toolbar(Brush& brush);

    /////////////////////////////////////////////////////////////
    // Public Methods Declarations (the interface)
    /////////////////////////////////////////////////////////////
    void setBrushColor(const sf::Color& color);
    void setBrushSize(float size);
    
private:
    Brush& m_brush;
};

#endif
