#ifndef CUSTOM_SHAPE_H
#define CUSTOM_SHAPE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace sf
{
    class RenderTarget;
    class RenderStates;
} // namespace sf

// We inherit since sf::Transformable magically allows
// our shape to be scaled, resized and repositioned
// This is because sf::Transformable does not have any virtual functions
// So we cant replace any functionality regarding that.
// sf::Transformable will magically know what to do and handle accordingly
class CustomShape : public sf::Drawable, public sf::Transformable
{
public:
    virtual ~CustomShape() = default;
    virtual void setFillColor(const sf::Color& color) = 0;
    virtual sf::Color getFillColor() const = 0;
    virtual sf::FloatRect getLocalBounds() const = 0;

private:
    
};

#endif