#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace ui
{
    class TextLabel : public UIEntity
    {
    public:
        enum Alignment {Left, Center, Right};

        /////////////////////////////////////////////////////////////
        // Constructer Declarations
        /////////////////////////////////////////////////////////////
        TextLabel(
            const std::string& string,
            const sf::Color& text_col,
            sf::Uint8 text_size,
            const sf::Font& font,
            Alignment text_alignment = Center,
            const sf::Color& box_col = sf::Color::Transparent,
            const sf::Vector2f& box_dimensions = sf::Vector2f(0, 0)
        );

        /////////////////////////////////////////////////////////////
        // Setters
        /////////////////////////////////////////////////////////////        
        void setText(const std::string& str);
        void setTextColor(const sf::Color& col);
        void setTextSize(sf::Uint8 size);
        void setTextAlignment(Alignment alignment);

        void setBoxColor(const sf::Color& col);
        void setBoxDimensions(const sf::Vector2f& dimensions);

        /////////////////////////////////////////////////////////////
        // Getters
        /////////////////////////////////////////////////////////////
        std::string getTextCopy() const;
        sf::Color getTextColor() const;
        sf::Uint8 getTextSize() const;
        Alignment getTextAlignment() const;

        sf::Color getBoxColor() const;

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
        sf::Vector2f getSize() const override;

    private:
        // -- Text
        std::string m_string;
        sf::Color m_text_col;
        sf::Uint8 m_text_size;
        sf::Font m_font;
        sf::Text m_text;
        Alignment m_alignment;
        
        // -- Box
        sf::Color m_box_col;
        sf::Vector2f m_box_dimensions;
        sf::RectangleShape m_box;
    };
}