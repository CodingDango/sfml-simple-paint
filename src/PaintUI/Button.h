#ifndef BUTTON_H
#define BUTTON_H

#include "Utils.h"
#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace ui
{
    class Button
    {
    public:
        /////////////////////////////////////////////////////////////
        // Constructor Declarations  
        /////////////////////////////////////////////////////////////

        Button(const sf::Color& fill_color, const sf::Vector2f& btn_size);

        /////////////////////////////////////////////////////////////
        // Update Methods
        /////////////////////////////////////////////////////////////

        void checkHover(const sf::Event& event);
        void checkClick(const sf::Event& event);

        /////////////////////////////////////////////////////////////
        // Setters  
        /////////////////////////////////////////////////////////////

        void setPosition(const sf::Vector2f& pos);
        void setPosition(float x, float y);
        void setClickCallback(const std::function<void()>& callback);
        void setHoverCallback(const std::function<void()>& callback);
        void setNoHoverCallback(const std::function<void()>& callback);

        /////////////////////////////////////////////////////////////
        // Getters  
        /////////////////////////////////////////////////////////////

        sf::Color getFillColor() const;
        const sf::RectangleShape& getDrawableRect() const;

    private:
        static constexpr float m_normal_scale_factor = 1.0f;
        static constexpr float m_hover_scale_factor  = 1.1f;

        sf::RectangleShape m_rect_shape;
        sf::Color m_fill_color;

        std::function<void()> m_hover_callback;
        std::function<void()> m_no_hover_callback;
        std::function<void()> m_click_callback;
    };

    struct BtnInitData
    {
        BtnInitData(const sf::Color& color, const sf::Vector2f& btn_size);
        const sf::Color m_color;
        const sf::Vector2f m_btn_size;
    };
} 

#endif