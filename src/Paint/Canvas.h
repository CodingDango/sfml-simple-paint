#ifndef CANVAS_H
#define CANVAS_H

#include "BrushLogic.h"
#include "EntityTypes.h"
#include "Utils.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace Paint
{
    class Canvas : public UIEntity
    {
    public:
        Canvas(
            BrushLogic* brush_logic_ptr, 
            const sf::Vector2f& canvas_pos,
            const sf::Vector2u& canvas_size,
            const sf::Color& canvas_col
        );

        /////////////////////////////////////////////////////////////
        // Entity Overrides
        /////////////////////////////////////////////////////////////
        void render(sf::RenderTarget& dest) override;
        void update(float dt, const sf::Vector2f& mouse_pos) override;
        void handleEvent(const sf::Event& event) override;

    private:
        BrushLogic* m_brush_logic_ptr;
        sf::Vector2f m_canvas_pos;
        sf::Vector2u m_canvas_size;
        const sf::Color m_canvas_col;
        sf::RenderTexture m_render_texture;
        sf::Sprite m_sprite;
        sf::Vector2f m_unmapped_last_brush_pos;
        bool m_was_hovered = false;
        bool m_was_pressed = false;
        bool m_is_painting = false;

        void configRenderObjects();
        void applySmoothBrushStrokes();
        void applyBrushDab(const sf::Vector2f& unmapped_brush_pos); 
    };
}

#endif