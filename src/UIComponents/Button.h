#ifndef BUTTON_H
#define BUTTON_H

#include "EntityTypes.h"
#include "Utils.h"

#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace UI
{
    class Button : public UIEntity
    {
    public:
        /////////////////////////////////////////////////////////////
        // Constructor Declarations  
        /////////////////////////////////////////////////////////////
        Button(const sf::Color& fill_color, const sf::Vector2f& btn_size);

        void setClickCallback(const std::function<void()>& callback);
        void setHoverCallback(const std::function<void()>& callback);
        void setNoHoverCallback(const std::function<void()>& callback);
        void setOutlineColor(const sf::Color& col);
        void setOutlineThickness(float thickness);
        void setFillColor(const sf::Color& col);

        /////////////////////////////////////////////////////////////
        // Getters  
        /////////////////////////////////////////////////////////////
        sf::Color getFillColor() const;
        const sf::RectangleShape& getDrawableRect() const;

        /////////////////////////////////////////////////////////////
        // Conditional
        /////////////////////////////////////////////////////////////
        bool isMouseHovered(const sf::Vector2f& mouse_pos) const;

        /////////////////////////////////////////////////////////////
        // Entity Overrides
        /////////////////////////////////////////////////////////////
        void handleEvent(const sf::Event& event) override;
        void update(float dt, const sf::Vector2f& mouse_pos) override;
        void render(sf::RenderTarget& dest) override;

        /////////////////////////////////////////////////////////////
        // UIEntity Overrides
        /////////////////////////////////////////////////////////////
        void setPosition(const sf::Vector2f& pos) override;
        void setPosition(float x, float y) override;
        sf::Vector2f getSize() const override ;
         
    private:
        const float m_normal_scale_factor = 1.0f;
        const float m_hover_scale_factor  = 1.1f;

        sf::RectangleShape m_shape;
        sf::Color m_fill_color;

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