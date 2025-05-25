#ifndef BRUSH_LOGIC_H
#define BRUSH_LOGIC_H

#include "Brush.h"
#include "Entity.h"
#include "Debug.h"

#include <SFML/Graphics/Shape.hpp>

#include <memory>

class BrushLogic : public Entity
{
public:
    /////////////////////////////////////////////////////////////
    // Constructer Declarations
    /////////////////////////////////////////////////////////////
    BrushLogic(Brush::ShapeType shape_type, sf::Color col, float size);

    /////////////////////////////////////////////////////////////
    // Setters
    /////////////////////////////////////////////////////////////
    void setColor(const sf::Color& color);
    void setSize(float size);
    void setShape(Brush::ShapeType type);
    void setPosition(const sf::Vector2f& pos);

    /////////////////////////////////////////////////////////////
    // Getters
    /////////////////////////////////////////////////////////////
    sf::Vector2f getPosition() const;
    float getWidth() const;
    sf::FloatRect getBounds() const;
    const sf::Shape& getShape() const;

    /////////////////////////////////////////////////////////////
    // Entity Overrides
    /////////////////////////////////////////////////////////////
    void update(float dt, const sf::Vector2f& mouse_pos) override;

private:
    std::unique_ptr<Brush> m_brush_ptr;
    const float MAX_SIZE = 50.0f;
    const float MIN_SIZE = 1.0f;

    /////////////////////////////////////////////////////////////
    // Debug helpers
    /////////////////////////////////////////////////////////////
    std::string_view CLASS_NAME = "BrushLogic";
    void outputBrushIsNull(std::string_view func_name) const;
};

#endif
