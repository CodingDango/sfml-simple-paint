#ifndef CANVAS_H
#define CANVAS_H

#include "Brush.h"
#include "Entity.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace paint
{
    class Canvas : public Entity
    {
    public:
        Canvas(
            Brush* brush_ptr, 
            const sf::Vector2f& canvas_pos,
            const sf::Vector2u& canvas_size
        );

        /////////////////////////////////////////////////////////////
        // Entity Overrides
        /////////////////////////////////////////////////////////////
        void render(sf::RenderTarget& dest) override;
        void handleEvent(const sf::Event& event) override;

    private:
        Brush* m_brush_ptr;
        sf::Vector2f m_canvas_pos;
        sf::Vector2u m_canvas_size;
        sf::RenderTexture m_render_texture;
        sf::Sprite m_sprite;
    
        void configRenderObjects();
    };
}

#endif