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
    Toolbar(Brush* brush_ptr);

    /////////////////////////////////////////////////////////////
    // Public Methods Declarations (the interface)
    /////////////////////////////////////////////////////////////
    void setBrushColor(const sf::Color& color);
    void setBrushSize(float size);
    void setBrushShape(Brush::ShapeType type);
    
private:
    Brush* m_brush_ptr;
};

#endif
