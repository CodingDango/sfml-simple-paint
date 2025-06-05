#include "Brush.h"

Brush::Brush(Brush::ShapeType shape_type, sf::Color col, float size)
:   m_shape_type  { shape_type },
    m_color { col },
    m_size  { size }
{
    configureBrushShape();
    centerBrushOrigin();
    setColor(col);
}

void Brush::configureBrushShape()
{   

    m_shape_ptr.reset();

    switch (m_shape_type)
    {
        case ShapeType::Circle:
        {
            // Keep your existing Circle case code
            float radius = m_size / 2.0f;
            if (radius <= 0) radius = 1.0f;
            m_shape_ptr = std::make_unique<sf::CircleShape>(radius);
            break;
        }

        case ShapeType::Rectangle:
        {
            // Keep your existing Rectangle case code
            float side = m_size;
            if (side <= 0) side = 1.0f;
            m_shape_ptr = std::make_unique<sf::RectangleShape>(sf::Vector2f(side, side));
            break;
        }

        case ShapeType::Triangle: // <-- REPLACE the body of this case
        {
            int num_points = 3;
            float radius = m_size / 2.0f; // Use half size as radius
            if (radius <= 0) radius = 1.0f;

            auto triangle = std::make_unique<sf::ConvexShape>(num_points);

            // These are the specific points needed for an UPright triangle
            // centered at (0,0) in the shape's local coordinates.
            // Don't worry about *why* these numbers work with cos/sin right now.
            triangle->setPoint(0, sf::Vector2f(radius * std::cos(270.0f * M_PI / 180.0f), radius * std::sin(270.0f * M_PI / 180.0f))); // Top vertex
            triangle->setPoint(1, sf::Vector2f(radius * std::cos(30.0f * M_PI / 180.0f),  radius * std::sin(30.0f * M_PI / 180.0f)));  // Bottom-Right vertex
            triangle->setPoint(2, sf::Vector2f(radius * std::cos(150.0f * M_PI / 180.0f), radius * std::sin(150.0f * M_PI / 180.0f))); // Bottom-Left vertex

            m_shape_ptr = std::move(triangle); // Take ownership
            break;
        }

        case ShapeType::Star: // <-- REPLACE the body of this case
        {
            int num_points = 10; // 5 outer + 5 inner
            float outer_radius = m_size / 2.0f; // Use half size as outer radius
             if (outer_radius <= 0) outer_radius = 1.0f;

            float inner_radius_factor = 0.4f; // Ratio of inner to outer radius (adjust if star looks weird)
            float inner_radius = outer_radius * inner_radius_factor;

            // This offset makes the first point face UPWARDS.
            float angle_offset_deg = 270.0f; // Use 270 degrees for UP in SFML's Y-down system

            auto star = std::make_unique<sf::ConvexShape>(num_points);

            for (int i = 0; i < num_points; ++i)
            {
                // Calculate the angle for this point
                float angle_deg = (i * (360.0f / num_points)) + angle_offset_deg;
                float angle_rad = angle_deg * M_PI / 180.0f;

                // Alternate between outer and inner radius for star points
                float current_radius = (i % 2 == 0) ? outer_radius : inner_radius; // 0, 2, 4, 6, 8 are outer points

                // Calculate point coordinates relative to (0,0) center
                star->setPoint(i, sf::Vector2f(current_radius * std::cos(angle_rad), current_radius * std::sin(angle_rad)));
            }

            m_shape_ptr = std::move(star); // Take ownership
            break;
        }

        default:
            // Keep your existing default case code
            std::cerr << "[Brush] Attempted to create unknown brush shape type! Defaulting to Circle.\n";
            m_shape_type = ShapeType::Circle; // Change the type state
             float radius = m_size / 2.0f;
            if (radius <= 0) radius = 1.0f;
            m_shape_ptr = std::make_unique<sf::CircleShape>(radius);
            break;
    }
    // Keep the line setting the fill color AFTER the switch
    if (m_shape_ptr)
    {
         m_shape_ptr->setFillColor(m_color);
    }
    centerBrushOrigin();
}

void Brush::setShapeType(Brush::ShapeType type)
{
    if (m_shape_type == type)
        return;

    m_shape_type = type;
    configureBrushShape();
}

void Brush::setSize(float size) 
{
    if (size <= 0)
    {
        std::cerr << "[Brush] Size cannot be negative!\n";
        return;
    }
    
    m_size = size;
    configureBrushShape();
}

void Brush::setColor(const sf::Color& col)
{
    m_color = col;

    if (!m_shape_ptr)
    {
        std::cerr << "[Brush] Attempted to setColor on null\n";
        return;
    }

    m_shape_ptr->setFillColor(m_color);
}

void Brush::setPosition(const sf::Vector2f vect)
{
    m_shape_ptr->setPosition(vect);
}

const sf::Shape& Brush::getShape() const
{
    return *m_shape_ptr.get();
}

Brush::ShapeType Brush::getShapeType() const
{
    return m_shape_type;
}

sf::Color Brush::getFillColor() const
{
    return m_color;
}

void Brush::centerBrushOrigin()
{
    if (!m_shape_ptr) 
    {
        std::cerr << "[Brush] Centering an invalid shape!\n";
        return;
    }   

    sf::FloatRect bounds = m_shape_ptr->getLocalBounds();

    const float center_x = bounds.left + bounds.width / 2.0f;
    const float center_y = bounds.top + bounds.height / 2.0f;

    m_shape_ptr->setOrigin(center_x, center_y);
}