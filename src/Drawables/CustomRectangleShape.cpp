#include "CustomRectangleShape.h"
#include <cmath>      // For std::cos, std::sin
#include <algorithm>  // For std::min
#include <vector>     // Used temporarily in getLocalBounds

// Constructor
CustomRectangleShape::CustomRectangleShape(
    const sf::Vector2f& initial_size,
    float initial_radius,
    unsigned int initial_cornerPointCount)
    : m_size(initial_size),
      m_radius(initial_radius),
      m_cornerPointCount(std::max(2u, initial_cornerPointCount)) // Ensure at least 2 points for a corner to be valid
      // m_convexShape is default-constructed
{
    updatePoints(); // Calculate initial points for the shape
    // Set initial fill color for the convex shape (CustomShape::setFillColor will call this)
    // For now, let's set a default here, or ensure setFillColor is called after construction.
    // m_convexShape.setFillColor(sf::Color::White); // Or passed via constructor
}

// --- Method to recalculate points ---
void CustomRectangleShape::updatePoints() {
    // Ensure radius is not too large for the size, and not negative.
    // It can't be more than half the smaller dimension of the rectangle.
    float R = m_radius;
    if (R < 0.f) R = 0.f;
    R = std::min(R, m_size.x / 2.0f);
    R = std::min(R, m_size.y / 2.0f);

    // If radius is effectively zero or not enough points for a curve, draw a sharp rectangle.
    if (R == 0.f || m_cornerPointCount < 2) {
        m_convexShape.setPointCount(4);
        m_convexShape.setPoint(0, sf::Vector2f(0, 0));
        m_convexShape.setPoint(1, sf::Vector2f(m_size.x, 0));
        m_convexShape.setPoint(2, sf::Vector2f(m_size.x, m_size.y));
        m_convexShape.setPoint(3, sf::Vector2f(0, m_size.y));
        return;
    }

    unsigned int totalPointCount = m_cornerPointCount * 4;
    m_convexShape.setPointCount(totalPointCount);

    const float pi = 3.141592654f;
    // deltaAngle is the angle step between points on a 90-degree corner arc.
    float deltaAngle = 90.0f / (static_cast<float>(m_cornerPointCount) - 1.0f);
    unsigned int point_idx = 0;

    // Order of points for sf::ConvexShape should be consistent (e.g., clockwise)
    // Angles for SFML: 0 = East (right), 90 = South (down), 180 = West (left), 270 = North (up)

    // Top-left corner (center: (R, R))
    // Points from angle 180 (left) to 270 (up)
    sf::Vector2f centerTL(R, R);
    for (unsigned int i = 0; i < m_cornerPointCount; ++i) {
        float angleDeg = 180.f + (deltaAngle * i);
        float angleRad = angleDeg * pi / 180.f;
        m_convexShape.setPoint(point_idx++,
                               sf::Vector2f(centerTL.x + R * std::cos(angleRad),
                                            centerTL.y + R * std::sin(angleRad)));
    }

    // Bottom-left corner (center: (R, m_size.y - R))
    // Points from angle 90 (down) to 180 (left)
    sf::Vector2f centerBL(R, m_size.y - R);
    for (unsigned int i = 0; i < m_cornerPointCount; ++i) {
        float angleDeg = 90.f + (deltaAngle * i);
        float angleRad = angleDeg * pi / 180.f;
        m_convexShape.setPoint(point_idx++,
                               sf::Vector2f(centerBL.x + R * std::cos(angleRad),
                                            centerBL.y + R * std::sin(angleRad)));
    }

    // Bottom-right corner (center: (m_size.x - R, m_size.y - R))
    // Points from 0 (right) to 90 (down)
    sf::Vector2f centerBR(m_size.x - R, m_size.y - R);
    for (unsigned int i = 0; i < m_cornerPointCount; ++i) {
        float angleDeg = 0.f + (deltaAngle * i);
        float angleRad = angleDeg * pi / 180.f;
        m_convexShape.setPoint(point_idx++,
                               sf::Vector2f(centerBR.x + R * std::cos(angleRad),
                                            centerBR.y + R * std::sin(angleRad)));
    }

    // Top-right corner (center: (m_size.x - R, R))
    // Points from 270 (up) to 360/0 (right)
    sf::Vector2f centerTR(m_size.x - R, R);
    for (unsigned int i = 0; i < m_cornerPointCount; ++i) {
        float angleDeg = 270.f + (deltaAngle * i);
        float angleRad = angleDeg * pi / 180.f;
        m_convexShape.setPoint(point_idx++,
                               sf::Vector2f(centerTR.x + R * std::cos(angleRad),
                                            centerTR.y + R * std::sin(angleRad)));
    }
}

// --- CustomShape interface implementation ---
void CustomRectangleShape::setFillColor(const sf::Color& color) {
    m_convexShape.setFillColor(color);
}

sf::Color CustomRectangleShape::getFillColor() const {
    return m_convexShape.getFillColor();
}

sf::FloatRect CustomRectangleShape::getLocalBounds() const {
    // The m_convexShape's points are already in local coordinates (0,0 top-left of the shape area).
    // sf::ConvexShape::getLocalBounds() might not be perfectly tight if it just uses getPoint(0)
    // and assumes a simple polygon. For a truly accurate bound of *our points*, we might
    // iterate, but sf::ConvexShape's getLocalBounds() is often sufficient or we can use its points.
    // For simplicity and because the shape is convex and defined from (0,0) up to (m_size.x, m_size.y):
    return sf::FloatRect(0.f, 0.f, m_size.x, m_size.y);
    // A more accurate (but slower) way if m_convexShape.getLocalBounds() isn't trusted:
    // return m_convexShape.getGlobalBounds(); // if no transform applied yet, this is local
    // Or iterate m_convexShape.getPoint(i) to find min/max x/y.
    // sf::ConvexShape calculates its own bounds based on its points, so this should be okay:
    // return m_convexShape.getLocalBounds(); // This should be fine.
}

// --- sf::Drawable interface implementation (via CustomShape) ---
void CustomRectangleShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Apply the transform from sf::Transformable (which CustomShape inherits)
    states.transform *= getTransform(); // 'getTransform()' is from sf::Transformable
    target.draw(m_convexShape, states);
}

// --- Specific setters/getters ---
void CustomRectangleShape::setSize(const sf::Vector2f& size) {
    if (m_size != size) {
        m_size = size;
        updatePoints();
    }
}

const sf::Vector2f& CustomRectangleShape::getVisualSize() const {
    return m_size;
}

void CustomRectangleShape::setCornersRadius(float radius) {
    if (m_radius != radius) {
        m_radius = radius;
        updatePoints();
    }
}

float CustomRectangleShape::getCornersRadius() const {
    return m_radius;
}

void CustomRectangleShape::setCornerPointCount(unsigned int count) {
    unsigned int newCount = std::max(2u, count); // Ensure at least 2
    if (m_cornerPointCount != newCount) {
        m_cornerPointCount = newCount;
        updatePoints();
    }
}

unsigned int CustomRectangleShape::getCornerPointCount() const {
    return m_cornerPointCount;
}