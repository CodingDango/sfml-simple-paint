#ifndef ENTITY_H
#define ENTITY_H

#include <set>

// Forward declarations for SFML
namespace sf
{
    class Event;
    class Vector2f;
    class RenderTexture;
} 

namespace entity 
{
    // Usable components
    const enum components {
        NONE = 0,
        DRAWABLE = 1,
        HOVERABLE = 2,
        CLICKABLE = 3
    };

    struct Entity
    {       
        const std::set<int> components_set;

        virtual void processEvent(const sf::Event& event) = 0;
        virtual void update(float dt, const sf::Vector2f& mouse_pos) = 0;
        virtual void draw(sf::RenderTexture& dest) = 0;
    };
}

#endif