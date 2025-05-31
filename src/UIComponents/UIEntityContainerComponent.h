#ifndef UI_ENTITY_CONTAINER_COMPONENT_H
#define UI_ENTITY_CONTAINER_COMPONENT_H

#include "EntityTypes.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

namespace UI
{
    class UIEntityContainerComponent
    {
    public:
        void addChild(std::unique_ptr<UIEntity> entity_ptr);
        void clearChildren();
        size_t getChildCount() const;

        UIEntity* operator[](size_t index);
        const UIEntity* operator[](size_t index) const;
        
        void handleUIEntitiesEvents(const sf::Event& event);
        void updateUIEntities(float dt, const sf::Vector2f& mouse_pos);
        void renderUIEntities(sf::RenderTarget& dest);

    private:
        std::vector<std::unique_ptr<UIEntity>> m_ui_entities;
    };
}

#endif