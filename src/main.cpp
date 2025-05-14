#include "utils.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

int main()
{
    // -- Window Setup --
    const std::string window_title { "SimplePaint" };
    const int window_width_px   = 1280;
    const int window_height_px  = 720;
    const int max_fps = 60;

    sf::RenderWindow window {
        sf::VideoMode{ window_width_px, window_height_px },
        window_title
    };

    window.setFramerateLimit(max_fps);

    // -- System Setup --
    sf::Clock clock {};

    // -- Paint Setup --

    // Canvas Setup
    const sf::Vector2u canvas_size { window_width_px, window_height_px };

    sf::RenderTexture canvas_texture {};
    canvas_texture.create(canvas_size.x, canvas_size.y);

    const sf::Texture& canvas_texture_texture = canvas_texture.getTexture();
    sf::Sprite canvas_sprite {  canvas_texture_texture };

    // Brush Setup
    const float brush_size_px = 20.0f; 
    const sf::Color brush_color = sf::Color::Red;
    
    bool is_painting = false;
    sf::Vector2f last_mouse_pos {};

    sf::CircleShape brush { brush_size_px };
    brush.setOrigin(brush.getRadius(), brush.getRadius());
    brush.setFillColor(brush_color);

    // -- Main Game loop --
    while (window.isOpen())
    {
        const float delta_time { clock.restart().asSeconds() };
        const sf::Vector2f mouse_pos { utils::toVector2f(sf::Mouse::getPosition(window)) };

        // -- Process Events --
        sf::Event event {};
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.control && event.key.code == sf::Keyboard::C)
                    canvas_texture.clear();
            
                break;
            
            case sf::Event::MouseButtonPressed:
                is_painting = true;
                last_mouse_pos = mouse_pos;
                break;

            case sf::Event::MouseMoved:
            {
                if (is_painting)
                {
                    sf::Vector2f direction { mouse_pos - last_mouse_pos };
                    for (double i = 0.1; i <= 1; i += 0.1)
                    {
                        float x = direction.x * i;
                        float y = direction.y * i;
                        brush.setPosition(x, y);
                        canvas_texture.draw(brush);
                        last_mouse_pos = mouse_pos;
                    }
                }  
            }
                break;

            case sf::Event::MouseButtonReleased:
                is_painting = false;
                break;


            default:
                break;
            }
        }

        // -- Update logic --
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            brush.setPosition(mouse_pos);
            canvas_texture.draw(brush);
        }   

        // -- Drawing logic --        
        window.clear();
        window.draw(canvas_sprite);
        window.display();

        canvas_texture.display();
    }
}