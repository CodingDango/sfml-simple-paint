#ifndef CUSTOM_RECTANGLE_H
#define CUSTOM_RECTANGLE_H

#include "CustomShape.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace sf
{
    class RenderTarget;
    class RenderStates;
}

class CustomRectangle : public CustomShape
{
public:
    void setFillColor(const sf::Color& color) override;
    void setBorderRadius(float top_left, float top_right, float bottom_left, float bottom_right);
    sf::Color getFillColor() const override;
    sf::FloatRect getLocalBounds() const override;
    void draw(sf::RenderTarget& dest, sf::RenderStates states) const override;

private:
    
    // Convex shape for a rectangle?
    // So make a rectangle shape from scratch using convex shape alone?
    // I mean.. we literally have to do this right?
    // We wanted rounded corners after all.

};

#endif