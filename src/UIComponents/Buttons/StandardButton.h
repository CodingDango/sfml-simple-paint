#ifndef RECTANGLE_BUTTON_H
#define RECTANGLE_BUTTON_H

#include "ButtonBase.h"
#include <SFML/Graphics.hpp>

namespace UI
{
    class StandardButton : public UI::ButtonBase
    {
    public:
        /////////////////////////////////////////////////////////////
        // Class Specific Stuff
        /////////////////////////////////////////////////////////////
        StandardButton(
            const sf::Color& col, 
            const sf::Vector2f& size = {0.f, 0.f}
        );

        void setIconTexture(const sf::Texture& text);
        void setSize(const sf::Vector2f& size);

        void setOutlineColor(const sf::Color& col) override;
        void setOutlineThickness(float thickness) override;
        void setFillColor(const sf::Color& col) override;
        
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
        sf::RectangleShape m_rectangle;
        sf::Sprite m_icon_sprite;

        void centerIconInRectangle();
    };
} 

#endif