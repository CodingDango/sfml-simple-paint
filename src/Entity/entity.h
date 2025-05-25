#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/RenderTarget.hpp>   // Vect a
#include <SFML/Graphics/RenderWindow.hpp>   // For event

struct Entity
{       
    virtual ~Entity() = default;
    virtual void handleEvent(const sf::Event& event) {};
    virtual void update(float dt, const sf::Vector2f& mouse_pos) {};
    virtual void render(sf::RenderTarget& dest) {};
};

struct UIEntity : public Entity
{   
    virtual ~UIEntity() = default;

    virtual sf::Vector2f getSize() const { return {0, 0}; };
    virtual sf::Vector2f getPosition() const { return {0, 0}; };
    
    virtual void setPosition(const sf::Vector2f& pos) {};
    virtual void setPosition(float x, float y) {};
    
    bool is_mouse_released = false;
    bool is_hovered = false;
    bool is_pressed = false;
    bool is_hidden = false;
};

#endif