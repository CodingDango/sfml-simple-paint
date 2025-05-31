#include "UIEntityContainerComponent.h"

void UI::UIEntityContainerComponent::addChild(std::unique_ptr<UIEntity> entity_ptr) 
{
    if (entity_ptr)
        m_ui_entities.push_back(std::move(entity_ptr));
}

void UI::UIEntityContainerComponent::clearChildren()
{
    m_ui_entities.clear();
}

size_t UI::UIEntityContainerComponent::getChildCount() const 
{
    return m_ui_entities.size();
}

UIEntity* UI::UIEntityContainerComponent::operator[](size_t index) 
{
    if (index < m_ui_entities.size()) 
    {
        return m_ui_entities[index].get();
    }

    return nullptr;
}

const UIEntity* UI::UIEntityContainerComponent::operator[](size_t index) const 
{
    if (index < m_ui_entities.size()) 
    {
        return m_ui_entities[index].get();
    }

    return nullptr;
}

void UI::UIEntityContainerComponent::handleUIEntitiesEvents(const sf::Event& event)
{
    for (auto& ui_entity_ptr : m_ui_entities) 
    {
         ui_entity_ptr->handleEvent(event); 
    }
}

void UI::UIEntityContainerComponent::updateUIEntities(float dt, const sf::Vector2f& mouse_pos)
{
    for (auto& ui_entity_ptr : m_ui_entities) 
    { 
        ui_entity_ptr->update(dt, mouse_pos); 
    }
}

void UI::UIEntityContainerComponent::renderUIEntities(sf::RenderTarget& dest)
{
    for (const auto& ui_entity_ptr : m_ui_entities)
    {
        ui_entity_ptr->render(dest);
    }
}