#ifndef BUTTON_BASE_H
#define BUTTON_BASE_H

#include "EntityTypes.h"
#include "Utils.h"

#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace UI
{
    class ButtonBase : public UIEntity
    {
    public:
        virtual ~ButtonBase() = default;

        void setClickCallback(const std::function<void()>& callback);
        void setHoverCallback(const std::function<void()>& callback);
        void setNoHoverCallback(const std::function<void()>& callback);

        virtual void setOutlineColor(const sf::Color& col) = 0;
        virtual void setOutlineThickness(float thickness) = 0;
        virtual void setFillColor(const sf::Color& col) = 0;
        
        virtual sf::Color getFillColor() const = 0;
        virtual bool isMouseHovered(const sf::Vector2f& mouse_pos) const = 0;

        // Below will be implemented by the concrete class.. 
        // /////////////////////////////////////////////////////////////
        // // Entity Overrides
        // /////////////////////////////////////////////////////////////
        // virtual void handleEvent(const sf::Event& event);
        // virtual void update(float dt, const sf::Vector2f& mouse_pos);
        // virtual void render(sf::RenderTarget& dest);

        // /////////////////////////////////////////////////////////////
        // // UIEntity Overrides
        // /////////////////////////////////////////////////////////////
        // virtual void setPosition(const sf::Vector2f& pos);
        // virtual void setPosition(float x, float y);
        // virtual sf::Vector2f getSize() const;
        
    protected:
        void handleMouseCallbacks(const sf::Vector2f& mouse_pos);
        void handleMouseEvents(const sf::Event& event);

    private:
        std::function<void()> m_hover_callback;
        std::function<void()> m_no_hover_callback;
        std::function<void()> m_click_callback;
    };

    // TODO
    // Create RectButton class Can hold ONE Drawable, and Transformable/ Object to be its Icon
    // Each class should be able to handle holding one icon?
    // Turn the Button into a Base Class.
} 

#endif