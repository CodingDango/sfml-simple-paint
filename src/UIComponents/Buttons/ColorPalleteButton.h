#ifndef COLOR_PALLETE_BUTTON_H
#define COLOR_PALLETE_BUTTON_H

#include "ButtonBase.h"
#include <SFML/Graphics.hpp>

namespace UI
{
    class ColorPalleteButton : public UI::ButtonBase
    {
    public:
        /////////////////////////////////////////////////////////////
        // Class Specific Stuff
        /////////////////////////////////////////////////////////////
        ColorPalleteButton(
            const sf::Color& col, 
            const sf::Vector2f& size = {0.f, 0.f}
        );

        void setInnerMostOutlineThickness(float thickness);
        void setInnerMostOutlineColor(const sf::Color& col);

        void setOutlineThickness(float thickness) override;
        void setOutlineColor(const sf::Color& col) override;
        void setFillColor(const sf::Color& col) override;
        
        void setSize(const sf::Vector2f& size);
        sf::Color getFillColor() const override;
        bool isMouseHovered(const sf::Vector2f& mouse_pos) const override;

        /////////////////////////////////////////////////////////////
        // Entity Overrides
        /////////////////////////////////////////////////////////////
        virtual void handleEvent(const sf::Event& event);
        virtual void update(float dt, const sf::Vector2f& mouse_pos);
        virtual void render(sf::RenderTarget& dest);

        /////////////////////////////////////////////////////////////
        // UIEntity Overrides
        /////////////////////////////////////////////////////////////
        virtual void setPosition(const sf::Vector2f& pos);
        virtual void setPosition(float x, float y);
        virtual sf::Vector2f getSize() const;

    private:
        sf::RectangleShape m_rectangle;        // For First Inner Outline (The largest one, it is white)
        sf::RectangleShape m_second_rectangle; // For Inner Inner Outline (Its outline will be divided by 2, it is black)
    };
} 

#endif