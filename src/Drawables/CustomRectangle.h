// CustomRectangleShape.h
#ifndef MY_ROUNDED_RECTANGLE_SHAPE_H
#define MY_ROUNDED_RECTANGLE_SHAPE_H

#include "CustomShape.h" // Your abstract base class
#include <SFML/Graphics/ConvexShape.hpp>

class CustomRectangleShape : public CustomShape {
public:
    explicit CustomRectangleShape(const sf::Vector2f& size = sf::Vector2f(100.f, 50.f),
                                     float radius = 5.f,
                                     unsigned int cornerPointCount = 15);

    // From CustomShape / sf::Drawable
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setFillColor(const sf::Color& color) override;
    sf::Color getFillColor() const override;
    sf::FloatRect getLocalBounds() const override;

    // Specific to CustomRectangleShape
    void setSize(const sf::Vector2f& size);
    const sf::Vector2f& getVisualSize() const; // Using getVisualSize to avoid confusion

    void setCornersRadius(float radius);
    float getCornersRadius() const;

    void setCornerPointCount(unsigned int count);
    unsigned int getCornerPointCount() const;

private:
    void updatePoints(); // Recalculates the vertices for m_convexShape

    sf::Vector2f m_size;
    float m_radius;
    unsigned int m_cornerPointCount;

    sf::ConvexShape m_convexShape; // Holds the points and does the drawing
};

#endif // MY_ROUNDED_RECTANGLE_SHAPE_H