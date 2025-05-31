#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include "EntityTypes.h" 
#include "Utils.h"       

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string> 

namespace UI
{
    class TextLabel : public UIEntity
    {
    public:
        /////////////////////////////////////////////////////////////
        // Public Typedefs & Enums
        /////////////////////////////////////////////////////////////
        enum Alignment { Left, Center, Right };

        /////////////////////////////////////////////////////////////
        // Constructor
        /////////////////////////////////////////////////////////////
        TextLabel(
            const sf::Font& font_ref,
            const std::string& string,
            unsigned int char_size,
            const sf::Vector2f& box_size
        );

        /////////////////////////////////////////////////////////////
        // Public Methods - Interface
        /////////////////////////////////////////////////////////////

        // --- Text Properties ---
        void setString(const std::string& str);
        void setTextColor(const sf::Color& col);
        void setCharSize(unsigned int size);
        void setTextAlignment(Alignment alignment);
        void setTextStyle(sf::Text::Style style);

        std::string getTextCopy() const;
        sf::Color getTextColor() const;
        unsigned int getCharSize() const;
        Alignment getTextAlignment() const;
        const sf::Text& getActualText() const; 

        // --- Box Properties ---
        void setBoxColor(const sf::Color& col);
        void setBoxDimensions(const sf::Vector2f& dimensions);
        void setBoxCornerRadius( 
            float top_left,
            float top_right,
            float bottom_left,
            float bottom_right
        );

        sf::Color getBoxColor() const;
        sf::FloatRect getBoxBounds() const; // Renamed from getBoxSize for clarity with SFML's getGlobalBounds/getLocalBounds

        /////////////////////////////////////////////////////////////
        // Entity Overrides (Base class virtual functions)
        /////////////////////////////////////////////////////////////
        void handleEvent(const sf::Event& event) override;
        void update(float dt, const sf::Vector2f& mouse_pos) override;
        void render(sf::RenderTarget& dest) override;

        /////////////////////////////////////////////////////////////
        // UIEntity Overrides (Base class virtual functions)
        /////////////////////////////////////////////////////////////
        void setPosition(const sf::Vector2f& pos) override;
        void setPosition(float x, float y) override;
        sf::Vector2f getSize() const override; // This now aligns with getBoxBounds potentially, ensure consistency

    private:
        /////////////////////////////////////////////////////////////
        // Private Helper Methods
        /////////////////////////////////////////////////////////////
        void alignTextInBox();
        void updateBoxSize(const sf::Vector2f& new_size); // Or perhaps updateBoxSize

        /////////////////////////////////////////////////////////////
        // Private Member Variables
        /////////////////////////////////////////////////////////////

        // -- Text Data --
        const sf::Font& m_font_ref; 
        std::string m_string_content; 
        unsigned int m_character_size; 
        sf::Color m_text_color = sf::Color::White; 
        Alignment m_text_alignment = Center;       
        sf::Text m_text_object;                    

        // -- Box Data --
        sf::Color m_box_color = sf::Color::Transparent; 
        sf::RectangleShape m_box_shape;              
    };
}

#endif // TEXT_LABEL_H