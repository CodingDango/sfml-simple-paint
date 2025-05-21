#ifndef ENTITY_H
#define ENTITY_H

// Forward declarations for SFML
#include <SFML/Graphics.hpp>

struct Entity
{       
    virtual ~Entity() = default;
    virtual void handleEvent(const sf::Event& event) {};
    virtual void update(float dt, const sf::Vector2f& mouse_pos) {};
    virtual void render(sf::RenderTarget& dest) {};

    bool is_clicked = false;
    bool is_hovered = false;
};

#endif