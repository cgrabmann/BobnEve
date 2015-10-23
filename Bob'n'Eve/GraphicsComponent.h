#pragma once
#include <SFML/include/SFML/Graphics/Color.hpp>
#include <cinttypes>

class GameObject;
class Renderer;

class GraphicsComponent
{
public:
	GraphicsComponent(sf::Color renderColor);
	~GraphicsComponent();

	void Update(GameObject& object, int16_t ms);
	virtual void Draw(const GameObject& object, Renderer& renderer) const;

protected:
	sf::Color renderColor_;
};

