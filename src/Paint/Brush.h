#ifndef BRUSH_H
#define BRUSH_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Brush : public Entity
{   
public:
    enum ShapeType {
        Circle = 0,
        Rectangle = 1
    };
    
    Brush(Brush::ShapeType shape_type, sf::Color col, float size);

    void setShapeType(Brush::ShapeType type);
    void setSize(float size);
    void setColor(const sf::Color& col);

    const sf::Shape* getShape() const;
    ShapeType getShapeType() const; 

    // Entity Overrides
    void handleEvent(const sf::Event& event) override;
    void update(float dt, const sf::Vector2f& mouse_pos) override;
    
private:
    // Brush State
    ShapeType m_shape_type; 
    sf::Color m_brush_color;
    float m_brush_size;
    bool m_is_brush_painting = false;
    sf::Vector2f m_last_mouse_pos;

    // Brush Shape
    std::unique_ptr<sf::Shape> m_shape_ptr;

    // When the user stops painting, outof obunds
    inline static const sf::Vector2f M_BRUSH_INACTIVE_POS {-1000.0f, -1000.0f}; 

    void configureBrushShape();
    void centerBrushOrigin();
    void applySizeToShape();
};  


#endif
